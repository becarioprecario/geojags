//Virgilio Gómez Rubio, 2017
//Modified from file matrix.h in the jags software
#ifndef MATRIXUTILS_H_
#define MATRIXUTILS_H_

namespace jags {
namespace geojags {


/**
  * Computes matrix tau * [I - rho * W]
  *
  * @param PREC Pointer to an array of length m squared, which will contain
  * the matrix on exit.
  *
  * @param A pointer to array containing the values of the matrix W
  *
  * @param m Number of rows or columns in the matrix
  *
  * @param rho Spatial autocorrelation parameter
  *
  * @param tau Precision parameter
  *
  */
void create_IrhoW(double *PREC, double const *T, int m, double rho,
  double tau);


/**
  * Computes matrix tau * [I - rho * W'] * [I - rho * W]
  *
  * @param PREC Pointer to an array of length m squared, which will contain
  * the matrix on exit.
  *
  * @param A pointer to array containing the values of the matrix W
  *
  * @param m Number of rows or columns in the matrix
  *
  * @param rho Spatial autocorrelation parameter
  *
  * @param tau Precision parameter
  *
  */
void create_IrhoW2(double *PREC, double const *T, int m, double rho,
  double tau);


/**
  * Computes matrix (1/tau) * exp(- (d_ij * phi)^kappa)
  *
  * @param VCOV Pointer to an array of length m squared, which will contain
  * the variance-covariance matrix on exit.
  *
  * @param x x-coordinate of points
  *
  * @param y y-coordinate of points
  *
  * @param m Number of rows or columns in the matrix
  *
  * @param tau Precision parameter
  *
  * @param phi Scale parameter
  *
  * @param kappa Another scale parameter
  *
  */

void create_spatialexp(double *VCOV, double const *x, double const *y,
  int m, double tau, double phi, double kappa);

}}

#endif /* MATRIXUTILS_H_ */

