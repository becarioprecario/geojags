#include "config.h"
#include <util/dim.h>
#include <util/nainf.h>
#include "DSAR.h"

#include "lapack.h"
#include "matrix.h"
#include "matrix_utils.h"

#include <cmath>
#include <vector>
#include <cfloat>

#include <JRmath.h>

using std::vector;

namespace jags {
namespace geojags {

DSAR::DSAR()
  : ArrayDist("dsar", 4) //mu, W, rho, tau
{} 

double DSAR::logDensity( double const                         *x,
                         unsigned int                         m,
                         PDFType                              type,
			             vector<double const *> const         &parameters,
			             vector<vector<unsigned int> > const  &dims,
			             double const                         *lower, 
                         double const                         *upper )  const
{                        
    
    double const * adj     = parameters[0];
    double const * weights = parameters[1];
    double const * num     = parameters[2];
    double const * tau     = parameters[3];
    double const * rho     = parameters[4];

    int    N      = m * m;
    int    *k     = 0;
    double loglik = 0;
    double fila   = 0;
 
    for (unsigned int i = 0; i < m; ++i) {
 
          fila = -x[i];
            for (unsigned int j = 0; j < num[i]; ++j) {
                  
                      fila += x[adj[j] - 1] * rho * weights[k[i] + j];
           
            }

           k[i+1]  = k[i]+num[i];

           loglik += fila*fila;
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

void DSAR::randomSample( double                               *x, 
                         unsigned int                         m,
			             vector<double const *> const         &parameters,
			             vector<vector<unsigned int> > const  &dims,
			             double const                         *lower, 
                         double const                         *upper,
			             RNG                                  *rng ) const
{
    double const *mu  = parameters[0];
    double const *T   = parameters[1];
    double const *rho = parameters[2];
    double const *tau = parameters[3];


    int    N      = m * m;
    double *Tcopy = new double[N];

    create_IrhoW2(Tcopy, T, m, rho[0], tau[0]);

    randomsample(x, mu, Tcopy, true, m, rng);
}

void DSAR::randomsample( double        *x,
                         double const  *mu,
                         double const  *T,
			             bool          prec, 
                         int           nrow, 
                         RNG           *rng )
{
  //FIXME: do something with rng

  int    N      = nrow*nrow;
  double *Tcopy = new double[N];

  for (int i = 0; i < N; ++i) {
    Tcopy[i] = T[i];
  }

  double *w = new double[nrow];

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

bool DSAR::checkParameterDim( vector<vector<unsigned int> > const &dims ) const
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

vector<unsigned int> DSAR::dim( vector<vector<unsigned int> > const &dims ) const
{
    return dims[0];
}

bool
DSAR::checkParameterValue( vector<double const *> const         &parameters,
			               vector<vector<unsigned int> > const  &dims ) const
{
    double const *adjacency = parameters[1];
    unsigned int n = dims[0][0];

//    return check_symmetry(adjacency, n);// && check_symmetric_ispd(precision, n);
    return true; //FIXME: Check wether the matrix has a symmtric structure
}


void DSAR::support( double                               *lower, 
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

void DSAR::typicalValue( double                               *x,
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

bool DSAR::isSupportFixed( vector<bool> const &fixmask ) const
{
    return true;
}

}}
