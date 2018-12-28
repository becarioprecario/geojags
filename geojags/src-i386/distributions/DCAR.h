#ifndef DCAR_H_
#define DCAR_H_

#include <distribution/ArrayDist.h>

namespace jags {

struct RNG;

namespace geojags {

/**
 * @short Proper CAR distribution
 * <pre>
 * x[] ~ dmnorm(mu[], T[,])
 * T[] = tau * (I - rho * W)
 * f(x | mu, T) = sqrt(det(T)) * exp(-1/2 * (x-mu) %*% T %*% t(x-mu))
 * </pre>
 */
class DCAR : public ArrayDist {
public:
  DCAR();

  double logDensity(double const *x, unsigned int length, PDFType type,
		    std::vector<double const *> const &parameters,
		    std::vector<std::vector<unsigned int> > const &dims,
		    double const *lower, double const *upper)  const;
  void randomSample(double *x, unsigned int length,
		    std::vector<double const *> const &parameters,
		    std::vector<std::vector<unsigned int> > const &dims,
		    double const *lower, double const *upper, RNG *rng) const;
  void typicalValue(double *x, unsigned int length,
		    std::vector<double const *> const &parameters,
		    std::vector<std::vector<unsigned int> > const &dims,
		    double const *lower, double const *upper) const;
  /**
   * Checks that mu is a vector, T is a square matrix and the sizes of
   * mu and T conform.
   */
  bool checkParameterDim(std::vector<std::vector<unsigned int> > const &dims) 
      const;
  /**
   * Checks that T is symmetric. No need to test it is positive definite.
   */
  bool checkParameterValue(std::vector<double const *> const &parameters,
                           std::vector<std::vector<unsigned int> > const &dims) 
      const;
  std::vector<unsigned int> 
      dim(std::vector<std::vector<unsigned int> > const &dims) const;
  /**
   * Convenience random sampler function 
   *
   * @param x  Array that will hold the result
   *
   * @param mu Array of mean values. A null pointer may be given, and in
   * this case a mean of zero is used.
   *
   * @param tau Either the precision matrix or the variance-covariance
   * matrix.  Only the lower triangle is used.
   * 
   * @param prec Logical flag. If true then tau represents the
   * precision matrix (the parameterization used in the bugs language).
   * If false then tau represents the variance-covariance matrix.
   *
   * @param nrow length of x and mu; number of rows of the square matrix tau
   *
   * @param rng Random number generator
   */
  static void randomsample(double *x, double const *mu, double const *tau,
			   bool prec, int nrow, RNG *rng);
  void support(double *lower, double *upper, unsigned int length,
	       std::vector<double const *> const &parameters,
               std::vector<std::vector<unsigned int> > const &dims) const;
  bool isSupportFixed(std::vector<bool> const &fixmask) const;
};

}}

#endif /* DCAR_H_ */
