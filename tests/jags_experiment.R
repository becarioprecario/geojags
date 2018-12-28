#Test implemented models using a small dataset and jags
#using spatialprobit::LeSagePaceExperiment(n = 30)
#
#
library(spdep)
library(rjags)
library(spatialprobit)
library(SEjags)

#Create data and conduct experiment
set.seed(2)
experiment <- LeSagePaceExperiment(n = 30, rho = 0.95, ndraw = 600,
  burn.in = 100)

#Create data.frame
d <- as.data.frame(cbind(experiment$y, experiment$X))
names(d) <- c("y", "Intercept", "var1", "var2")

#Model formula
m.form <- y ~ 1 + var1 + var2

#Fit model with spatialprobit
fit1 <- sarprobit(m.form,
  W = experiment$W, data = d,
  ndraw = 600, burn.in = 100, thinning = 10,
  prior = list(T = diag(3) * 1e3),
  showProgress=TRUE)
summary(fit1)


slm.jags <- SEjags(m.form, data = d, W = as(experiment$W, "matrix"), 
  model = "slm", link = "logit",  n.burnin = 2000, n.iter = 600)

#Compare results
print(slm.jags)
summary(fit1)


#Fit model with INLA
library(INLA)

#And index for slm model
n <- nrow(d)
d$idx <- 1:n

#Model matrix
mm <- model.matrix(m.form, d)

#Boundaries for rho
rho.min <- -1
rho.max <- 1

betaprec1 <- 0.001
#Standard regression model
Q.beta1 = Diagonal(n=ncol(mm), x = betaprec1)

#Definition of priors for precision of the error effect in the slm latent
#effect and the spatial autocorrelation parameter (in the (0,1) interval).
#
hyper.slm = list(
   prec = list(initial = log(1), fixed = TRUE),#prior = "loggamma", param = c(0.01, 0.01)),
      rho = list(prior = "logitbeta", param = c(1, 1))#list(initial=0, prior = "logitbeta", param = c(1,1))
)


#SLM model
slmm1<-inla( y ~ -1 +
   f(idx, model="slm",
      args.slm=list(rho.min = rho.min, rho.max = rho.max, 
         W = experiment$W, X=mm,
         Q.beta=Q.beta1),
      hyper=hyper.slm),
   data = d, family = "binomial",
   control.family = list(link = "probit"),
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

