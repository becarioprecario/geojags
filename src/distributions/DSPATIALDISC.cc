#include "config.h"
#include <util/dim.h>
#include <util/nainf.h>
#include "DSPATIALDISC.h"

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

DSPATIALDISC::DSPATIALDISC()
  : ArrayDist("spatial.disc", 5) //mu, x[], y[], tau, alpha
{}

double DSPATIALDISC::logDensity( double const                         *x, 
                                 unsigned int                         m, 
                                 PDFType                              type,
                                 vector<double const *> const         &parameters,
                                 vector<vector<unsigned int> > const  &dims,
                                 double const                         *lower, 
                                 double const                         *upper ) const
{
    double const *mu    = parameters[0];
    double const *xx    = parameters[1];
    double const *yy    = parameters[2];
    double const *tau   = parameters[3];
    double const *alpha = parameters[4];

    int     N    = m * m;
    int     M    = m;
    int     info = 0;
    double  ldet;
    double  *VCOV  = new double[N];
    double  *Tcopy = new double[N];

    //VARIANCE matrix
    create_spatialdisc(VCOV, xx, yy, m, tau[0], alpha[0]);
    ldet = logdet(VCOV, m);

    //Cholesky decomposition
    //Based on src/modules/glm/samplers/ScaledWishart.cc
    //On exit, VCOV is lower triangular with the inverse of L; 
    //Variance mztrix = L L^T
    F77_DPOTRF("L", &M, VCOV, &M, &info);
    if (info != 0) {
        jags::throwRuntimeError("Failed to get Cholesky decomposition of the variance matrix");
    }

    //Compute inverse
    info = 0;
    F77_DTRTRI("L", "N", &M, VCOV, &M, &info);
    if (info != 0) {
        jags::throwRuntimeError("Failed to compute the inverse of the L matrix");
    }

    //Compute L^{-1} * (x -mu)

    vector<double> delta(m);
    for (unsigned int i = 0; i < m; ++i) {
	delta[i] = x[i] - mu[i];
    }
    // Inverse is (L^-1)^T %*% L^{-1}
    int i1 = 1;
    F77_DTRMV("L", "N", "N", &M, VCOV, &M, &delta[0], &i1);

    double loglik = 0;
    for(unsigned int i = 0; i < m ; ++i) {
      loglik -= delta[i] * delta[i]/2;
    }

  
    switch(type) {
           case PDF_PRIOR:
	              break;

           case PDF_LIKELIHOOD:
	              loglik += -ldet/2;//logdet(Tcopy, m)/2;
	              break;

           case PDF_FULL:
	              loglik += -ldet/2 - m * M_LN_SQRT_2PI;
	              break;
    }
    
    return loglik;
}

void DSPATIALDISC::randomSample( double                               *x, 
                                 unsigned int                         m,
                                 vector<double const *> const         &parameters,
                                 vector<vector<unsigned int> > const  &dims,
                                 double const                         *lower, 
                                 double const                         *upper,
                                 RNG                                  *rng ) const
{
    double const *mu    = parameters[0];
    double const *xx    = parameters[1];
    double const *yy    = parameters[2];
    double const *tau   = parameters[3];
    double const *alpha = parameters[4];

    int N = m * m;
    double * Tcopy = new double[N];

    create_spatialdisc( Tcopy, xx, yy, m, tau[0], alpha[0]);

    randomsample( x, mu, Tcopy, false, m, rng);
}

void DSPATIALDISC::randomsample( double        *x, 
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

bool DSPATIALDISC::checkParameterDim( vector<vector<unsigned int> > const &dims ) const
{
    //Vector mean and adjacency matrix
    if (!isVector(dims[0]))       return false;
    if (dims[0][0] != dims[1][0]) return false;
    
    return true;
}

vector<unsigned int> DSPATIALDISC::dim( vector<vector<unsigned int> > const &dims ) const
{
    return dims[0];
}

bool
DSPATIALDISC::checkParameterValue( vector<double const *> const         &parameters,
                                   vector<vector<unsigned int> > const  &dims ) const
{
    //FIXME: Check parameters
    //unsigned int n = dims[0][0];
    //return check_symmetry(adjacency, n) && check_symmetric_ispd(ajacency, n);
    return true; 
}


void DSPATIALDISC::support( double                               *lower, 
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

void DSPATIALDISC::typicalValue( double                               *x, 
                                 unsigned int                         m,
                                 vector<double const *> const         &parameters,
                                 vector<vector<unsigned int> > const  &dims,
                                 double const                         *lower,
                                 double const                         *upper) const
{
    for (unsigned int i = 0; i < m; ++i) {
	x[i] = parameters[0][i];
    }
}

bool DSPATIALDISC::isSupportFixed( vector<bool> const &fixmask ) const
{
    return true;
}

}}
