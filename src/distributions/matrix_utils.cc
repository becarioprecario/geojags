// Virgilio Gómez Rubio, 2017
//Modified version of matrix.cc in the jags software
#include "config.h"

#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
#include <module/ModuleError.h>

#include "lapack.h"
#include "matrix.h"
#include "matrix_utils.h"

using std::log;
using std::fabs;
using std::copy;
using std::vector;

namespace jags {
namespace geojags {

void create_IrhoW( double        *PREC, 
                   double const  *T, 
                   int           m, 
                   double        rho,
                   double        tau )
{
    int N = m * m;
    double rhotau = rho * tau;

    for (int i = 0; i < N ; ++i) {
      PREC[i] = - rhotau * T[i];
    }
    for(int i = 0; i < m ; ++i) {
      PREC[i + i * m] += tau;
    }
}

void create_IrhoW2( double        *PREC, 
                    double const  *T, 
                    int           m, 
                    double        rho,
                    double        tau )
{
    int N = m * m;
    double alpha = 1;
    double beta = 0;
    double *IrhoW = new double[N];

    create_IrhoW(IrhoW, T, m, rho, sqrt(tau));
/*void F77_DGEMM (const char* transa, const char* transb, const int* m,
                    const int* n , const int* k, const double* alpha,
                    const double* A, const int* lda,
                    const double* B, const int* ldb,
                    const double* beta, double* C, const int* ldc);
*/
    F77_DGEMM("T", "N", &m, &m, &m, &alpha, IrhoW, &m, IrhoW, &m,
      &beta, PREC, &m);

}

void create_IrhoW3( double       *PREC, 
                    double const *T, 
                    int          m, 
                    double       rho,
                    double       tau)
{
    int n[m] = {0};
    double rhotau = rho * tau;

    for(int i = 0; i < m ; ++i) {

         for(int j = 0; j < m ; ++j) {

            n[i] += T[i*m + j];
         }
         if (n[i] = 0){
          n[i] = 1;
         }
  }

    for (int i = 0; i < m ; ++i) {
        for (int j = 0; j < m; ++j){
          PREC[j + i*m] = - rhotau * T[j + i*m]/(n[i]+1);  //FIXME el numero de vecinos puede ser 0 y peta
        }
    }

    for(int i = 0; i < m ; ++i) {
      PREC[i + i * m] = tau;
    }
}



void create_IlambdaW( double       *PREC, 
                      double const *T, 
                      int          m, 
                      double       lambda,
                      double       tau)
{
    int N = m * m;
    int n[m-1] = {0};
    

    for(int i = 0; i < m ; ++i) {
         for(int j = 0; j < m ; ++j) {
            n[i] += T[i*m + j];
         }
    }

    for (int i = 0; i < N ; ++i) {
          PREC[i] = -lambda* T[i]*tau;
    }

    for(int i = 0; i < m ; ++i) {
      PREC[i + i * m] = ((1-lambda)+lambda*n[i])*tau;
    }
}





//Matrix for spatial.exp
// Precision is: tau * exp(- (d_ij * phi)^kappa)
//
void create_spatialexp( double        *VCOV, 
                        double const  *x, 
                        double const  *y,
                        int           m, 
                        double        tau, 
                        double        phi, 
                        double        kappa )
{
    double d;

    //Storage by column (CHECK!!)
    VCOV[0] = 1 / tau;
    for (int i = 1; i < m ; ++i) {
      for (int j = 0; j < i ; ++j) {
        d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        VCOV[i * m + j] = exp(- pow(d * phi, kappa)) / tau;
        VCOV[j * m + i] = VCOV[i * m + j];
      }
      VCOV[i + i * m] = 1 / tau;
    }
}





void create_spatialdisc( double        *VCOV, 
                         double const  *x, 
                         double const  *y,
                         int           m, 
                         double        tau, 
                         double        alpha )
{
   double d;
   double coc;
    VCOV[0] =  M_2_PI / tau;
   for (int i = 1; i < m ; ++i) {
      for (int j = 0; j < i ; ++j) {
        d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        coc = d/alpha;
        VCOV[i * m + j] =  d < alpha ? M_2_PI*(1/cos(coc)-coc*sqrt(1-coc*coc))/tau : 0;
        VCOV[j * m + i] = VCOV[i * m + j];
      }
      VCOV[i + i * m] =  M_2_PI / tau;
    }

}


}}

   