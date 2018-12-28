/*
        Copyright (C) 2016 Virgilio Gomez-Rubio <Virgilio.GOmez@uclm.es>
        
        This header is based on the MVN distribution in JAGS version 4.2.0,
        and specifies the SAR error distribution
        
    This file is part of geojags (and copied from runjags)
        Original DMNorm.h file is Copyright (C) 2002-16 Martyn Plummer, 
        from the source for JAGS version 4.2.0, licensed under GPL-2

    geojags is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    geojags is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with geojags  If not, see <http://www.gnu.org/licenses/>.
        
 */


#ifndef DSARERROR_H_
#define DSARERROR_H_

#include <distribution/ArrayDist.h>

namespace jags {

struct RNG;

namespace geojags {

/**
 * @short SAR error spatial distribution
 * <pre>
 * x[] ~ derrorsar(mu[], rho, W[,])
 * f(x | mu, T) = sqrt(det(T)) * exp(-1/2 * (x-mu) %*% T %*% t(x-mu))
 * T = (I - rho *W') %*% (I - rho * W)
 * </pre>
 */
class DSARError : public ArrayDist {
public:
  DSARError();

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
   * Checks that T is symmetric. Note that there is currently NO CHECK
   * that T is positive definite.
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

#endif /* DERRORSAR_H_ */
