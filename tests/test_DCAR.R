#Test the Geojags library

library(rjags)

geo.path <- paste0(system.file("", package = "geojags"), "/libs/",
  .Platform$r_arch)
#Load package
rjags::load.module("geojags", geo.path)

#Simulate data
library(spdep)

##Columbus data set
#data(columbus)
#n <- nrow(columbus)
#W <- nb2mat(col.gal.nb, style = "B")

#Boston housing data
data(boston)
n <- nrow(boston.c)
WB <- nb2mat(boston.soi, style = "B")
WW <- nb2mat(boston.soi, style = "W")

#Subset data for testing
n <- 100
WB <- WB[1:n, 1:n]
WW <- WW[1:n, 1:n]

#Re-scale values in the adjacency matrix so that rho is roughly in (-1, 1).
WB <- WB / max(eigen(WB)$values)

#Parameters
rho <- 0.99
tau <- 10
#CAR error
#Sigma <- tau * (diag(n) - rho * WB)
#SAR error
Sigma <- diag(n) - rho * WW
Sigma <- tau * t(Sigma) %*% Sigma

library(MASS)
set.seed(1)

x1 <- rnorm(n)

y <- mvrnorm(1, 3 + x1, solve(Sigma)) 

d <- list(y = y, x1 = x1, W = WB, N = n)
inits <- list(alpha = 0, beta = 0, rho = 0)

m.car <- jags.model(file = "DCAR.bug", data = d, inits = inits)
update(m.car, 1000)
res.car <- jags.samples(m.car, 
  variable.names = c("alpha", "beta", "rho", "tau"),
  n.iter = 10000, thin = 10)
res.car

#SAR model
d$W <- WW
m.sar <- jags.model(file = "DSAR.bug", data = d, inits = inits)
update(m.sar, 1000)
res.sar <- jags.samples(m.sar,
  variable.names = c("alpha", "beta", "rho", "tau"),
  n.iter = 10000, thin = 10)
res.sar

#Display results
par(mfrow = c(2, 2))
plot(density(res.car$alpha), main = "alpha"); abline(v = 3)
lines(density(res.sar$alpha), lty = 2)
plot(density(res.car$beta), main = "beta"); abline(v = 1)
lines(density(res.sar$beta), lty = 2)
plot(density(res.car$rho), main = "rho"); abline(v = rho)
lines(density(res.sar$rho), lty = 2)
plot(density(res.car$tau), main = "tau"); abline(v = tau)
lines(density(res.sar$tau), lty = 2)

summary(spautolm(y ~ x1, listw = mat2listw(WB)), family = "CAR")
summary(spautolm(y ~ x1, listw = mat2listw(WW)), family = "SAR")


