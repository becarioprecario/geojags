#Test the Geojags library

library(rjags)

geo.path <- paste0(system.file("", package = "geojags"), "/libs/",
  .Platform$r_arch)
#Load package
rjags::load.module("geojags", geo.path)

#Simulate data
n <- 73
xx <- rnorm(n)
yy <- rnorm(n)
pts <- cbind(xx, yy)

tau <- 1
phi <- 1
kappa <- 1.5

#Distances
vcov <- matrix(0, n, n)

vcov[1, 1] <- 1/tau
for(i in 2:n) {
  for(j in 1:(i-1)) {
    ddist <- sqrt(sum((pts[i, ] - pts[j, ])^2))
    vcov[i, j] <- exp(-(ddist/phi)^kappa)/tau
    vcov[j ,i] <- vcov[i, j]
  }
  vcov[i, i] <- 1/tau
}

library(MASS)
set.seed(1)

x1 <- rnorm(n)

y <- mvrnorm(1, 3 + x1, vcov)

d <- list(y = y, x1 = x1, xx = xx, yy = yy, N = n)

inits <- list(alpha = 0, beta = 0, sigma = 1, phi = 1, kappa = 1)

m.spexp <- jags.model(file = "DSPATIALEXP.bug", data = d, inits = inits)
update(m.spexp, 1000)
res.spexp <- jags.samples(m.spexp, 
  variable.names = c("alpha", "beta", "tau", "phi", "kappa"),
  n.iter = 10000, thin = 10)
res.spexp

#Fit model with WinBUGS
library(R2WinBUGS)
res.WB <- bugs(data = d, inits = list(inits), model.file = "DSPATIALEXP.bug",
  parameters.to.save = c("alpha", "beta", "tau", "phi", "kappa"),
  n.chains = 1, n.iter = 10100, n.burnin = 100,
  n.thin = 10)


#Display results
plot.res <- function(name) {
  plot(density(res.spexp[[name]]), main = name)
  lines(density(res.WB$sims.list[[name]]), lty = 2)
}
par(mfrow = c(2, 3))
sapply(c("alpha", "beta", "tau", "phi", "kappa"), plot.res)

