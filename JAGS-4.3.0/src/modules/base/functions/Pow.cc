#include <config.h>
#include "Pow.h"

#include <cmath>
#include <cfloat>

using std::vector;
using std::pow;
using std::string;

namespace jags {
namespace base {

Pow::Pow () : Infix ("^")
{
}

string Pow::alias() const
{
    return "pow";
}

double Pow::evaluate(vector<double const *> const &args) const
{
    return pow (*args[0], *args[1]);
}

bool Pow::checkParameterValue(vector<double const *> const &args) const
{
    if (*args[0] > 0) {
	return true;
    }
    else if (*args[0] == 0) {
	return *args[1] >= 0;
    }
    else {
	return *args[1] == static_cast<int>(*args[1]);
    }
}

    bool Pow::isPower(vector<bool> const &mask, vector<bool> const &fix) const
    {
	if (mask[1])
	    return false;
        else
            return fix.empty() || fix[1];
    }

}}
