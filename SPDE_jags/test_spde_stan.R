#Load libraries

library(INLA)
library(rstan)

#Run locally on multicore machine
rstan_options(auto_write = TRUE)
options(mc.cores = parallel::detectCores())


#Example using INLA (from ?inla.spde2.matern)
n = 20
field.fcn = function(loc) {
  10 * cos(2 * pi * 2 *(loc[, 1] + loc[, 2]))
}
loc = matrix(runif(n * 2), n, 2)

## One field, 2 observations per location
#idx.y = rep(1:n, 2)
idx.y = 1:n
y =  field.fcn(loc[idx.y, ]) + rnorm(length(idx.y))
     
mesh = inla.mesh.create(loc, refine = list(max.edge = 0.50))
spde = inla.spde2.matern(mesh)
data = list(y = y, field = mesh$idx$loc[idx.y])
formula = y ~ -1 + f(field, model = spde)
result = inla(formula, data = data, family = "normal")
     
## Plot the mesh structure:
plot(mesh)
     
if (FALSE) { #require(rgl)) {
col.pal = colorRampPalette(c("blue","cyan","green","yellow","red"))
## Plot the posterior mean:
plot(mesh, rgl=TRUE,
result$summary.random$field[,"mean"],
color.palette = col.pal)
## Plot residual field:
plot(mesh, rgl=TRUE,
result$summary.random$field[,"mean"]-field.fcn(mesh$loc),
color.palette = col.pal)
}
     
result.field = inla.spde.result(result, "field", spde)
plot(result.field$marginals.range.nominal[[1]])


#JAGS
d.stan <- list(y = y, N = length(y),
  nvar = 1, X = matrix(1, ncol = 1 , nrow = length(y)),
  M0 = as.matrix(spde$param.inla$M0),
  M1 = as.matrix(spde$param.inla$M1),
  M2 = as.matrix(spde$param.inla$M2),
  n_spde = spde$n.spde,
  mu_spde = rep(0, spde$n.spde),
  A_y = as.matrix(inla.spde.make.A(mesh, loc[idx.y, ]))
)
d.inits <- list(prec_y = 1, #b = c(0),
  theta = c(spde$f$hyper.default$theta1$initial,
    spde$f$hyper.default$theta2$initial),
   eta = rep(0, d.stan$n_spde)
)

fit <- stan(file = "spde_model.stan",
  data = d.stan, iter = 2000, warmup = 1000, chains = 1,
  init = list(d.inits),
  algorithm = "HMC",
  pars = c("b", "theta", "kappa", "tau", "prec_y"),
  verbose = TRUE) 


xx <- fit@sim$samples[[1]]

par(mfrow = c(2, 2))
#Beta
plot(density(xx[[1]]))
#Theta
for(i in 1:2) {
plot(result$marginals.spde2.blc[[1]][[i]], type = "l",
  main = paste0("theta", i))
lines((density(xx[[paste0("theta[", i, "]")]])), lty = 2)
}
#Precision og Gaussian
plot(result$marginals.hyperpar[[1]], type = "l")
lines(density(xx[["prec_y"]]), lty = 2)



