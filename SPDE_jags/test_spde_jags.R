#Load libraries

library(INLA)
library(rjags)
library(runjags)


#Example using INLA (from ?inla.spde2.matern)
n = 200
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
d.jags <- list(y = y, N = length(y),
  nvar = 1, X = matrix(1, ncol = 1 , nrow = length(y)),
  M0 = as.matrix(spde$param.inla$M0),
  M1 = as.matrix(spde$param.inla$M1),
  M2 = as.matrix(spde$param.inla$M2),
  n.spde = spde$n.spde,
  A.y = as.matrix(inla.spde.make.A(mesh, loc[idx.y, ]))
)
d.inits <- list(prec.y = 1, b = 0,
  theta = c(spde$f$hyper.default$theta1$initial,
    spde$f$hyper.default$theta2$initial),
   eta = matrix(0, ncol = 1, nrow = d.jags$n.spde)
)

jm1 <- jags.model("spde_model.bug", data = d.jags, inits = d.inits, 
  n.chains = 1, n.adapt = 100)
update(jm1, 1000)
jm1.samp <- coda.samples(jm1, c("b", "theta", "prec.y"), n.iter = 1000, 
  n.thin = 10)
summary(jm1.samp)


xx <- as.list(jm1.samp)[[1]]

par(mfrow = c(2, 2))
#Beta
plot(density(xx[, "b"]))
#Theta
for(i in 1:2) {
plot(result$marginals.spde2.blc[[1]][[i]], type = "l",
  main = paste0("theta", i))
lines((density(xx[, 2 + i])), lty = 2)
}
#Precision og Gaussian
plot(result$marginals.hyperpar[[1]], type = "l")
lines(density(xx[, "prec.y"]), lty = 2)



