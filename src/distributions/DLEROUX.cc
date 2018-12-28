#include "config.h"
#include <util/dim.h>
#include <util/nainf.h>
#include "DLEROUX.h"

#include "lapack.h"
#include "matrix.h"
#include "matrix_utils.h"

#include <cmath>
#include <vector>
#include <cfloat>

#include <JRmath.h>

#include <module/ModuleError.h> // For 'throwRuntimeError'

using std::vector;

namespace jags {
namespace geojags {

DLEROUX::DLEROUX()
  : ArrayDist("dleroux", 4) //mu, W, lambda, tau
{}

double DLEROUX::logDensity( double const                         *x, 
                            unsigned int                         m, 
                            PDFType                              type,
			                      vector<double const *> const         &parameters,
			                      vector<vector<unsigned int> > const  &dims,
			                      double const                         *lower, 
                            double const                         *upper ) const
{
    double const * mu     = parameters[0];
    double const * T      = parameters[1];
    double const * lambda = parameters[2];
    double const * tau    = parameters[3];

    int N = m * m;
    double * Tcopy = new double[N];

    create_IlambdaW(Tcopy, T, m, lambda[0], tau[0]);

    double loglik = 0;
    vector<double> delta(m);

    for (unsigned int i = 0; i < m; ++i) {
	        delta[i] = x[i] - mu[i];
	        loglik  -= (delta[i] * Tcopy[i + i * m] * delta[i])/2;

       	for (unsigned int j = 0; j < i; ++j) {
       	        loglik -= (delta[i] * Tcopy[i + j * m] * delta[j]);
	      }
    }

    switch(type) {
    case PDF_PRIOR:
	        break;

    case PDF_LIKELIHOOD:
	        loglik += logdet(Tcopy, m)/2;
	        break;

    case PDF_FULL:
	        loglik += logdet(Tcopy, m)/2 - m * M_LN_SQRT_2PI;
	        break;
    }
    
    return loglik;
}

void DLEROUX::randomSample( double                               *x, 
                            unsigned int                         m,
			                      vector<double const *> const         &parameters,
			                      vector<vector<unsigned int> > const  &dims,
			                      double const                         *lower, 
                            double const                         *upper,
			                      RNG                                  *rng ) const
{
    double const * mu     = parameters[0];
    double const * T      = parameters[1];
    double const * lambda = parameters[2];
    double const * tau    = parameters[3];


    int N = m * m;
    double * Tcopy = new double[N];

    create_IlambdaW(Tcopy, T, m, lambda[0], tau[0]);

    randomsample(x, mu, Tcopy, true, m, rng);
}

void DLEROUX::randomsample( double        *x, 
                            double const  *mu, 
                            double const  *T,
			                      bool          prec, 
                            int           nrow, 
                            RNG           *rng )
{
  //FIXME: do something with rng

  int N = nrow*nrow;
  double * Tcopy = new double[N];

  for (int i = 0; i < N; ++i) {
    Tcopy[i] = T[i];
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

bool DLEROUX::checkParameterDim( vector<vector<unsigned int> > const &dims ) const
{
    //Allow scalar mean and precision. 
    //FIXME: IS this really needed? T is now and adjacency matrix
    if (isScalar(dims[0]) && isScalar(dims[1])) return true;

    //Vector mean and adjacency matrix
    if (!isVector(dims[0])) return false;
    if (!isSquareMatrix(dims[1])) return false;
    if (dims[0][0] != dims[1][0]) return false;
    
    return true;
}

vector<unsigned int> DLEROUX::dim( vector<vector<unsigned int> > const &dims ) const
{
    return dims[0];
}

bool
DLEROUX::checkParameterValue( vector<double const *> const         &parameters,
			                        vector<vector<unsigned int> > const  &dims ) const
{   
    double const *adjacency = parameters[1];
    unsigned int n = dims[0][0];

    return check_symmetry(adjacency, n);// && check_symmetric_ispd(precision, n);
}


void DLEROUX::support( double                               *lower, 
                       double                               *upper, 
                       unsigned int                         length,
		                   vector<double const *> const         &parameters,
		                   vector<vector<unsigned int> > const  &dims ) const
{
    for (unsigned int i = 0; i < length; ++i) {
	lower[i] = JAGS_NEGINF;
	upper[i] = JAGS_POSINF;
    }
}

void DLEROUX::typicalValue( double                               *x, 
                            unsigned int                         m,
			                      vector<double const *> const         &parameters,
			                      vector<vector<unsigned int> > const  &dims,
			                      double const                         *lower, 
                            double const                         *upper ) const
{
    for (unsigned int i = 0; i < m; ++i) {
	x[i] = parameters[0][i];
    }
}

bool DLEROUX::isSupportFixed( vector<bool> const &fixmask ) const
{
    return true;
}

}}
