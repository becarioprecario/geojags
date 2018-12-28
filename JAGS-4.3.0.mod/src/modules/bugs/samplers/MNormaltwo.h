#ifndef MNORMTWO_METROPOLIS_H_
#define MNORMTWO_METROPOLIS_H_

#include <sampler/Metropolis.h>

namespace jags {

    class SingletonGraphView;

namespace bugs {

class MNormtwoMetropolis : public Metropolis
{
    SingletonGraphView const *_gv;
    unsigned int _chain;
    double *_mean;
    double *_var;
    double *_prec;
    unsigned int _n;
    unsigned int _n_isotonic;
    double _sump, _meanp;
    double _lstep;
    unsigned int _nstep;
    unsigned int _p_over_target;
public:
    MNormtwoMetropolis(SingletonGraphView const *gv, unsigned int chain);
    ~MNormtwoMetropolis();
    void rescale(double p);
    void update(RNG *rng);
    bool checkAdaptation() const;
    void getValue(std::vector<double> &value) const;
    void setValue(std::vector<double> const &value);
};

}}

#endif /* MNORM_METROPOLIS_H_ */
