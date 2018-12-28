// SPDE implementation with Stan
data {
  int<lower=0> N; // number of observations
  vector[N] y; // estimated treatment effects
  int<lower=0>nvar; //Number of variables
  matrix[N, nvar] X; //Covariates
  int<lower=0> n_spde; //Number of points in mesh
  matrix[N, n_spde] A_y; //Projector matrix
  vector[n_spde] mu_spde; 

  matrix[n_spde, n_spde] M0;
  matrix[n_spde, n_spde] M1;
  matrix[n_spde, n_spde] M2;
}

parameters {
  real<lower=0> prec_y; //Precision of observations
  vector[n_spde] eta; //Coeffiencients of SPDE 
  vector[2] theta;//Hyperparameters of SPDE
  vector[nvar] b; //Coefficients of covariates
}

transformed parameters {
  vector[N] spde;
  vector[N] mu;
  real<lower=0> tau;
  real<lower=0> kappa;
  matrix[n_spde, n_spde] PREC_spde;

  real<lower=0> sigma_y;

  sigma_y = 1/sqrt(prec_y);
  tau = exp(theta[1]);
  kappa = exp(theta[2]);
  spde =  A_y * eta;
  mu =  (X * b) + spde;
  PREC_spde = tau * tau * ((kappa^4) * M0 + (2 * kappa * kappa * M1) + M2);
}

model {
  for(i in 1:N)
    y[i] ~ normal(mu[i], sigma_y);

  eta ~ multi_normal_prec(mu_spde, PREC_spde);

  for(i in 1:nvar)
    b[i] ~ normal(0, 31.62);

  theta[1] ~ normal(0, 3.162);
  theta[2] ~ normal(0, 3.162);
  prec_y ~ gamma(1, 5e-05);
}

