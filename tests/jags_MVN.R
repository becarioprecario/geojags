#Example from https://people.orie.cornell.edu/davidr/or678/r2winbugs/MultiNormalBug.pdf


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


#dmnorm2
#library(geojags)
#rjags::load.module("geojags", "/Library/Frameworks/R.framework/Versions/3.3/Resources/library/geojags/libs")

#-- dmnorm2 included in the jags installation

m2 <- jags.model(file = "jags_dmnormtwo.txt", 
  data = data, inits = inits)
update(m2, n.iter = 500)
res2 <- jags.samples(m2, variable.names = c("mu","tau","Sigma"), n.iter = 10000)


res0
res2
