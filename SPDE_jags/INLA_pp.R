## ----message = FALSE-----------------------------------------------------
library(spatstat)
#Load data
load("results/pp.RData")

#Remove all aditional information about the points
tornado <- unmark(kstorn_ppp)

#Points
pts <- as.matrix(coords(tornado))

#Boudnary
bdy <- do.call(cbind, as.polygonal(tornado$window)$bdry[[1]])

## ----fig = TRUE----------------------------------------------------------
library(sp)
dens <- as(density(tornado,  dimyx = c(15, 30)), 
  "SpatialGridDataFrame")
spplot(dens)

## ------------------------------------------------------------------------
library(INLA)
mesh <- inla.mesh.2d(loc.domain = pts,
  max.edge = c(1, 1), offset = c(2, 0.5))

#Number of points in the mesh
nv <- mesh$n
#Number of points in the pattern
n <- nrow(pts)


## ------------------------------------------------------------------------
spde <- inla.spde2.matern(mesh=mesh, alpha=2, constr = TRUE)
#Index of the spatial field
s.index <- inla.spde.make.index(name = "spatial.field", n.spde = spde$n.spde)

#Prediction points
A.pred <- inla.spde.make.A (mesh = mesh, loc = coordinates(dens))
stack.pred <- inla.stack(data = list(y = NA),
   A = list(A.pred),
   effects = list( c(s.index, list(Intercept=1)) ),
   tag = "pred")

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

lmat <- inla.spde.make.A(mesh, pts) #projector matrix for obs points

imat <- Diagonal(nv, rep(1, nv)) #projector matrix for integration points (matrix of ones)

A.pp <- rBind(imat, lmat)

## ----message = FALSE-----------------------------------------------------
### Data stack
stk.pp <- inla.stack(data = list(y = y.pp, e = e.pp),
  A = list(A.pp),
  effects = list(c(s.index, list(Intercept = 1))),
  tag = 'pp')

#Joint data
join.stack <- inla.stack(stk.pp, stack.pred)

#Estimation
pp.res <- inla(y ~ 0 + Intercept + f(spatial.field, model = spde),
  family = 'poisson', data = inla.stack.data(join.stack),
  control.predictor = list(A = inla.stack.A(join.stack), link = 1,
    compute = TRUE),
  E = inla.stack.data(join.stack)$e)

## ------------------------------------------------------------------------
idx <- inla.stack.index(join.stack, 'pred')$data
dens$SPDE <- pp.res$summary.fitted.values[idx, "mean"]

## ----echo = FALSE, fig = TRUE--------------------------------------------
spplot(dens)


