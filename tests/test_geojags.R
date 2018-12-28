#Test the Geojags library

library(rjags)

geo.path <- paste0(system.file("", package = "geojags"), "libs")
#Load package
rjags::load.module("geojags", geo.path)

#Run simple model that includes a car.normal of dimension 3.

#Test car.normal
d.jags <- list(y = c(1, 2, 3), N = 3,
  adj = c(2, 3, 1),# 3, 1, 2),
  weights = rep(1, 3),
  num = rep(2, 3)
)

d.inits <- list(mu = rep(0, 3))

jm <- jags.model('test_geojags.bug', data = d.jags, inits = d.inits)
res <- jags.samples(jm, variable.names = c("mu", "tau"), n.iter = 1000)

res

#Test dmnormtwobis

library(MASS)  # need to mvrnorm
library(MCMCpack) # need for rwish
# Generate synthetic data
N = 5
S = matrix(c(1,.2,.2,5),nrow=2)
y = mvrnorm(N,c(1,3),S)
# Set up for WinBUGS
mu0 = as.vector(c(0,0))
S2 = matrix(c(1,0,0,1),nrow=2)/1000
S3 =  matrix(c(1,0,0,1),nrow=2)/10000
data=list(y = y, N = N, S2 = S2, S3 = S3, mu0 = mu0)
inits=function(){list( mu=mvrnorm(1,mu0,matrix(c(10,0,0,10),nrow=2) ),
tau = rwish(3,matrix(c(.02,0,0,.04),nrow=2)) )}


#Dump data
dump(names(data), "data_dmnorm2.txt")

#####  Fit models with jags
library(rjags)


#dmnorm
m0 <- jags.model(file = "jags_dmnorm.txt",
  data = data, inits = inits)
update(m0, n.iter = 500)
res0 <- jags.samples(m0, variable.names = c("mu","tau","Sigma"), n.iter = 10000)


#dmnormtwobis with fixed precision matrix

m2 <- jags.model(file = "jags_dmnormtwo.txt",
  data = data, inits = inits)
update(m2, n.iter = 500)
res2 <- jags.samples(m2, variable.names = c("mu","tau","Sigma"), n.iter = 10000)

#This is where the differences between dmnormtwo and dmnormtwobis (prec * 99)
#  is noticed
summary(res0$mu, sd)
summary(res2$mu, sd)


