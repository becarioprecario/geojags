#include <config.h>
#include <distribution/ScalarDist.h>
#include <util/nainf.h>
#include <util/dim.h>

#include <stdexcept>
#include <cmath>
#include <algorithm>

using std::max;
using std::min;
using std::string;
using std::vector;
using std::length_error;
using std::logic_error;
using std::count_if;

namespace jags {

ScalarDist::ScalarDist(string const &name, unsigned int npar, Support support)
  : Distribution(name, npar), _support(support)
{
}

double ScalarDist::l(vector<double const *> const &parameters) const
{
    switch(_support) {
    case DIST_UNBOUNDED:
	return JAGS_NEGINF;
	break;
    case DIST_POSITIVE: case DIST_PROPORTION:
	return 0;
	break;
    case DIST_SPECIAL:
	//You must overload this function 
	throw logic_error("Cannot call ScalarDist::l for special distribution");
    }
    return 0; //Wall
}

double ScalarDist::u(vector<double const *> const &parameters) const
{
    switch(_support) {
    case DIST_UNBOUNDED: case DIST_POSITIVE:
	return JAGS_POSINF;
	break;
    case DIST_PROPORTION:
	return 1;
	break;
    case DIST_SPECIAL:
	//You must overload this function 
	throw logic_error("Cannot call ScalarDist::u for special distribution");
    }
    return 0; //Wall
}

bool ScalarDist::isSupportFixed(vector<bool> const &fixmask) const
{
    if (_support == DIST_SPECIAL) {
	//You must overload this function 
	throw logic_error("Cannot call ScalarDist::isSupportFixed for special distribution");
    }
    else {
	return true;
    }
}

unsigned int ScalarDist::df() const
{
    return 1;
}

    double ScalarDist::KL(vector<double const *> const &par1,
			  vector<double const *> const &par2,
			  double const *lower, double const *upper,
			  RNG *rng, unsigned int nrep) const
    {
	double div = 0;
	
	for (unsigned int r = 0; r < nrep; ++r) {
	    double v1 = randomSample(par1, lower, upper, rng);
	    div += logDensity(v1, PDF_FULL, par1, lower, upper);
	    div -= logDensity(v1, PDF_FULL, par2, lower, upper);
	}
	return div / nrep;
    }

    double ScalarDist::KL(vector<double const *> const &par1,
			  vector<double const *> const &par2) const
    {
	return JAGS_NA;
    }
    
} //namespace jags
