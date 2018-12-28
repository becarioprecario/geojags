#include <config.h>
#include "Probit.h"

#include <JRmath.h>

using std::vector;

namespace jags {
namespace bugs {

    Probit::Probit ()
	: ScalarFunction ("probit", 1)
    {
    }

    double Probit::evaluate(vector<double const *> const &args) const
    {
	return qnorm (*args[0], 0, 1, 1, 0);
    }

    bool Probit::checkParameterValue (vector <double const *> const &args) const
    {
	double p = *args[0];
	return (p >= 0 && p <= 1);
    }

}}
