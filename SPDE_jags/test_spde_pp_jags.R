#
#Fit a point pattern intensity using SPDE and jags
#

#Load libraries

library(INLA)
library(rjags)
library(runjags)


#Example using INLA (from ?inla.spde2.matern)
set.seed(10)
n = 10
loc = matrix(runif(n * 2), n, 2)

mesh = inla.mesh.create(loc, refine = list(max.edge = 0.50))
spde = inla.spde2.matern(mesh)

#Number of points in the mesh
nv <- mesh$n
#Number of points in the pattern
n <- nrow(loc)


## ------------------------------------------------------------------------
spde <- inla.spde2.matern(mesh=mesh, alpha=2, constr = TRUE)
#Index of the spatial field
s.index <- inla.spde.make.index(name = "spatial.field", n.spde = spde$n.spde)

## ----eval = TRUE, message = FALSE----------------------------------------
#Voronoi triangulation
require(deldir)
dd = deldir(mesh$loc[,1],mesh$loc[,2])
plot(dd)
points(mesh$loc,col=2)

#create a list of tiles in a tessellation
mytiles = tile.list(dd)
#plot(mytiles)

## ----message = FALSE-----------------------------------------------------
require(gpclib)
bdy <- cbind(c(0, 1, 1, 0), c(0, 0, 1, 1))

pl.study = as(bdy, "gpc.poly") #class for polygons
area.poly(pl.study) #compute the area of the polygon

#compute weight as area of the polygon 
#given as interaction between voronoi tiles and domain polygon
w = unlist(lapply(mytiles,
    function(p) area.poly(intersect(as(cbind(p$x,p$y),"gpc.poly"),
                                    pl.study)
                          ))
)
sum(w)
table(w>0)


## ------------------------------------------------------------------------
#Prepare data
y.pp = rep(0:1,c(nv,n))
# augmented data:
# 0 at mesh vertices/integration points
# 1 at data locations

e.pp = c(w, rep(0,n))
# expected data:
# w at mesh vertices/integration points
# 0 at data locations

lmat <- inla.spde.make.A(mesh, loc) #projector matrix for obs points

imat <- Diagonal(nv, rep(1, nv)) #projector matrix for integration points (matrix of ones)

A.pp <- rBind(imat, lmat)

### Data stack
stk.pp <- inla.stack(data = list(y = y.pp, e = e.pp),
  A = list(A.pp),
  effects = list(c(s.index, list(Intercept = 1))),
  tag = 'pp')

join.stack <- inla.stack(stk.pp)

#Estimation
pp.res <- inla(y ~ 0 + Intercept + f(spatial.field, model = spde),
  family = 'poisson', data = inla.stack.data(join.stack),
  control.predictor = list(A = inla.stack.A(join.stack), link = 1,
    compute = TRUE),
  E = inla.stack.data(join.stack)$e)

     
result.field = inla.spde.result(pp.res, "spatial.field", spde)
plot(result.field$marginals.range.nominal[[1]])

d.stack <- inla.stack.data(join.stack)
#JAGS
d.jags <- list(y = d.stack$y, N = length(d.stack$y),
  nvar = 1, X = matrix(1, ncol = 1 , nrow = length(d.stack$y)),
  E = matrix(d.stack$e, ncol = 1),
  M0 = as.matrix(spde$param.inla$M0),
  M1 = as.matrix(spde$param.inla$M1),
  M2 = as.matrix(spde$param.inla$M2),
  n.spde = spde$n.spde,
  A.y = as.matrix(A.pp)
)
d.inits <- list(b = 0,
  theta = c(spde$f$hyper.default$theta1$initial,
    spde$f$hyper.default$theta2$initial),
   eta = matrix(1, ncol = 1, nrow = d.jags$n.spde)
)

#Fix E==0
#d.jags$E [d.jags$E == 0] <- 1e-10

jm1 <- jags.model("spde_pp_model.bug", data = d.jags, inits = d.inits, 
  n.chains = 1, n.adapt = 1000)
update(jm1, 1000)
jm1.samp <- coda.samples(jm1, c("b", "theta"), n.iter = 1000, 
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



#WinBUGS
library(R2WinBUGS)


#JAGS
d.WB <- list(y = d.stack$y, nv = nv, N = length(d.stack$y),
  idx1.n = nv + 1, idx2.n = nv + n,
  nvar = 1, X = matrix(1, ncol = 1 , nrow = length(d.stack$y)),
  E = matrix(d.stack$e, ncol = 1),
  M0 = as.matrix(spde$param.inla$M0),
  M1 = as.matrix(spde$param.inla$M1),
  M2 = as.matrix(spde$param.inla$M2),
  n.spde = spde$n.spde,
  A.y = as.matrix(A.pp)
)
d.inits <- list(b = 0,
  theta = c(spde$f$hyper.default$theta1$initial,
    spde$f$hyper.default$theta2$initial),
   eta = matrix(1, ncol = 1, nrow = d.jags$n.spde)
)

res.bugs <- bugs(d.WB, list(d.inits), model.file = "spde_pp_model_WB.bug",
  n.chains = 1, n.iter = 2000, n.thin = 1,
  parameters.to.save = "eta")


