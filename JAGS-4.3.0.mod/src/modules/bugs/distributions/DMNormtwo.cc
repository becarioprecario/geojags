#include <config.h>
#include <util/dim.h>
#include <util/nainf.h>
#include "DMNormtwo.h"

#include <lapack.h>
#include <matrix.h>

#include <cmath>
#include <vector>
#include <cfloat>

#include <JRmath.h>

using std::vector;

namespace jags {
namespace bugs {

DMNormtwo::DMNormtwo()
  : ArrayDist("dmnormtwo", 2) 
{}

double DMNormtwo::logDensity(double const *x, unsigned int m, PDFType type,
			  vector<double const *> const &parameters,
			  vector<vector<unsigned int> > const &dims,
			  double const *lower, double const *upper) const
{
    double const * mu = parameters[0];
    double const * T = parameters[1];

    double loglik = 0;
    vector<double> delta(m);
    for (unsigned int i = 0; i < m; ++i) {
	delta[i] = x[i] - mu[i];
	loglik -= (delta[i] * (99 * T[i + i * m]) * delta[i])/2;
	for (unsigned int j = 0; j < i; ++j) {
	    loglik -= (delta[i] * (99 * T[i + j * m]) * delta[j]);
	}
    }

    switch(type) {
    case PDF_PRIOR:
	break;
    case PDF_LIKELIHOOD:
	loglik += logdet(T, m)/2 + m * log(99)/2;
	break;
    case PDF_FULL:
	loglik += logdet(T, m)/2 + m * log(99)/2 - m * M_LN_SQRT_2PI;
	break;
    }
    
    return loglik;
}

void DMNormtwo::randomSample(double *x, unsigned int m,
			  vector<double const *> const &parameters,
			  vector<vector<unsigned int> > const &dims,
			  double const *lower, double const *upper,
			  RNG *rng) const
{
    double const * mu = parameters[0];
    double const * T = parameters[1];
    
    randomsample(x, mu, T, true, m, rng);
}

void DMNormtwo::randomsample(double *x, double const *mu, double const *T,
			  bool prec, int nrow, RNG *rng)
{
  //FIXME: do something with rng

  int N = nrow*nrow;
  double * Tcopy = new double[N];
  for (int i = 0; i < N; ++i) {
    Tcopy[i] = 99 * T[i];
  }
  double * w = new double[nrow];

  int info = 0;
  double worktest;
  int lwork = -1;
  // Workspace query
  F77_DSYEV ("V", "L", &nrow, Tcopy, &nrow, w, &worktest, &lwork, &info);
  // Now get eigenvalues/vectors with optimal work space
  lwork = static_cast<int>(worktest + DBL_EPSILON);
  double * work = new double[lwork];
  F77_DSYEV ("V", "L", &nrow, Tcopy, &nrow, w, work, &lwork, &info);
  delete [] work;

  /* Generate independent random normal variates, scaled by
     the eigen values. We reuse the array w. */
  if (prec) {
      for (int i = 0; i < nrow; ++i) {
	  w[i] = rnorm(0, 1/sqrt(w[i]), rng);
      }
  }
  else {
      for (int i = 0; i < nrow; ++i) {
	  w[i] = rnorm(0, sqrt(w[i]), rng);
      }
  }

  /* Now transform them to dependant variates 
    (On exit from DSYEV, Tcopy contains the eigenvectors)
  */
  for (int i = 0; i < nrow; ++i) {
      x[i] = mu ? mu[i] : 0;
      for (int j = 0; j < nrow; ++j) {
	  x[i] += Tcopy[i + j * nrow] * w[j]; 
      }
  }
  delete [] w;
  delete [] Tcopy;
}

bool DMNormtwo::checkParameterDim(vector<vector<unsigned int> > const &dims) const
{
    //Allow scalar mean and precision. 
    if (isScalar(dims[0]) && isScalar(dims[1])) return true;

    //Vector mean and matrix precision
    if (!isVector(dims[0])) return false;
    if (!isSquareMatrix(dims[1])) return false;
    if (dims[0][0] != dims[1][0]) return false;
    
    return true;
}

vector<unsigned int> DMNormtwo::dim(vector<vector<unsigned int> > const &dims) const
{
    return dims[0];
}

bool
DMNormtwo::checkParameterValue(vector<double const *> const &parameters,
			    vector<vector<unsigned int> > const &dims) const
{
    double const *precision = parameters[1];
    unsigned int n = dims[0][0];

    return check_symmetry(precision, n) && check_symmetric_ispd(precision, n);
}


void DMNormtwo::support(double *lower, double *upper, unsigned int length,
		     vector<double const *> const &parameters,
		     vector<vector<unsigned int> > const &dims) const
{
    for (unsigned int i = 0; i < length; ++i) {
	lower[i] = JAGS_NEGINF;
	upper[i] = JAGS_POSINF;
    }
}

void DMNormtwo::typicalValue(double *x, unsigned int m,
			  vector<double const *> const &parameters,
			  vector<vector<unsigned int> > const &dims,
			  double const *lower, double const *upper) const
{
    for (unsigned int i = 0; i < m; ++i) {
	x[i] = parameters[0][i];
    }
}

bool DMNormtwo::isSupportFixed(vector<bool> const &fixmask) const
{
    return true;
}

}}