#Test implemented models using a small dataset and jags
library(spdep)
library(rjags)

#Load data
data(columbus)

#Fit models using spdep
lw <- nb2listw(col.gal.nb, style = "W")

#Model formula
m.form <-  CRIME ~ INC + HOVAL
#SEM
m.sem <- errorsarlm(m.form, data = columbus, listw = lw)
#SLM
m.slm <- lagsarlm(m.form, data = columbus, listw = lw)
#SDM
m.sdm <- lagsarlm(m.form, data = columbus, listw = lw,
  type = "mixed")


#Adjacency matrix
W <- nb2mat(col.gal.nb, style="W")
W.eigen <- eigen(W)$values

#Data for jags
d.jags <- list (y = columbus$CRIME)
d.jags$X <- model.matrix (CRIME ~ INC +  HOVAL, columbus)
#d.jags$X <- cbind(d.jags$X, W%*%d.jags$X[, -1])
d.jags$W <- W
d.jags$N <- nrow(columbus)
d.jags$n.var <- ncol(d.jags$X)
d.jags$I <- diag (d.jags$N)
#Bound for rho
d.jags$rho.min <- 1/min(W.eigen)
d.jags$rho.max <- 1/max(W.eigen)

#Inits for jags
d.inits <- list(b = matrix(0, nrow = d.jags$n.var, ncol = 1), tau = 1, rho = 0)


#Run jags
jm1 <- jags.model('slm.bug', data = d.jags, inits = d.inits, n.chains = 1,
  n.adapt = 100)

update(jm1, 1000)

jm1.samp <- jags.samples(jm1, c('b', 'rho', 'tau'), 1000)

print(jm1.samp)



#
#Impacts 
#

#---> SLM
#Av. tot. imp: beta / (1 - rho)
rho.sim <- jm1.samp$rho[1,,]
totimp.slm <- apply(jm1.samp$b[2:d.jags$n.var,1,,1], 1, function(X) {
 X/(1-rho.sim) 
})

#Av. direct impact: tr((I - rho*W)^{-1} *beta/n
library(parallel)
tr.aux1 <-  unlist(mclapply(rho.sim, function(X, W) {
  aux <- mean(diag(solve(diag(nrow(W)) - X * W)))
}, W = d.jags$W))
dirimp.slm <- apply(jm1.samp$b[2:d.jags$n.var,1,,1], 1, function (X) {
 X * tr.aux1
})

#Indirect impacts
indimp.slm <- totimp.slm - dirimp.slm

impacts.slm <- t(rbind(apply(dirimp.slm, 2, mean),
  apply(indimp.slm, 2, mean),
  apply(totimp.slm, 2, mean) 
))
colnames(impacts.slm) <- c("Direct", "Indirect", "Total")
rownames(impacts.slm) <- colnames(d.jags$X)[-1]

impacts.slm
impacts(m.slm, listw = lw)


#Test function
source("f.R")

kk <- SEMCMC(CRIME ~INC + HOVAL, data = columbus, W = W, model = "sem")
kk.imp <- impacts(kk, W)


