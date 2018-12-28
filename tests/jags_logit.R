#Test implemented models using a small dataset and jags
#
#LOGIT link!
#
library(spdep)
library(rjags)
library(spatialprobit)
library(SEjags)

#Load data
data(Katrina)

#Sub-sample
set.seed(1)
Katrina <- Katrina[sample.int(nrow(Katrina), 50), ]

#Adjacenty matrix
nb <- knn2nb(knearneigh(cbind(Katrina$lat, Katrina$long), k=11))
listw <- nb2listw(nb, style="W")
W1 <- as(as_dgRMatrix_listw(listw), "CsparseMatrix")
#Eigenvalues of W1
W.eigen <- eigen(W1)$values
     

#Model formula
m.form <-  y1 ~ flood_depth + log_medinc + small_size + large_size +
  low_status_customers +  high_status_customers +     
  owntype_sole_proprietor + owntype_national_chain

#Fit model with spatialprobit
fit1 <- sarprobit(m.form,
  W = W1, data = Katrina, 
  ndraw = 600, burn.in = 100, thinning = 10,
  prior = list(T = diag(9) * 1e3),
  showProgress=TRUE)
summary(fit1)


slm.jags <- SEjags(m.form, data = Katrina, W = as(W1, "matrix"), 
  model ="slm", link = "probit",  n.burnin = 100, n.iter = 600,
  n.thin = 10)

#Compare results
print(slm.jags)
summary(fit1)


#Fit model with INLA
library(INLA)

#And index for slm model
n <- nrow(Katrina)
Katrina$idx <- 1:n

#Model matrix
mm <- model.matrix(m.form, Katrina)


#Zero-variance for Gaussian erros, not needed here(?)
zero.variance = list(prec=list(initial = 25, fixed=TRUE))

#Boundaries for rho
rho.min <- -1
rho.max <- 1


betaprec1<-.0001
#Standard regression model
Q.beta1 = Diagonal(n=ncol(mm), x=1)
Q.beta1 = betaprec1*Q.beta1

args.slm = list(
   rho.min = rho.min ,
   rho.max = rho.max,
   W = W1,
   X = matrix(0, nrow(mm),0),
   Q.beta = matrix(1,0,0)
)

#Definition of priors for precision of the error effect in the slm latent
#effect and the spatial autocorrelation parameter (in the (0,1) interval).
#
hyper.slm = list(
   prec = list(initial=log(1), fixed=TRUE),#prior = "loggamma", param = c(0.01, 0.01)),
      rho = list(prior = "logitbeta", param = c(1, 1))#list(initial=0, prior = "logitbeta", param = c(1,1))
)


#SLM model
slmm1<-inla( y1 ~ -1 +
   f(idx, model="slm",
      args.slm=list(rho.min = rho.min, rho.max = rho.max, W=W1, X=mm,
         Q.beta=Q.beta1),
      hyper=hyper.slm),
   data=Katrina, family="binomial",
   control.family = list(link="probit", hyper=zero.variance),
   control.compute=list(dic=TRUE, cpo=TRUE)
)

#RE-scale rho
ff <- function(z){ z * (rho.max - rho.min) + rho.min}
slmmarg <- inla.tmarginal(ff, slmm1$marginals.hyperpar[[1]])

#Summary of results
#Coefficients
slmm1$summary.random$idx[-(1:n),]
#Rho
inla.zmarginal(slmmarg)

