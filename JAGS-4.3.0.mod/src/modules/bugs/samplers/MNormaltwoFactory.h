#ifndef MNORMALTWO_FACTORY_H_
#define MNORMALTWO_FACTORY_H_

#include "MNormaltwo.h"

#include <sampler/SingletonFactory.h>

namespace jags {
namespace bugs {

/**
 * @short Factory object for multivariate normal samplers
 */
class MNormaltwoFactory : public SingletonFactory
{
public:
    bool canSample(StochasticNode *snode, Graph const &graph) const;
    Sampler *makeSampler(StochasticNode *snode, Graph const &graph) const;
    std::string name() const;
};

}}

#endif /* MNORMAL_FACTORY_H_ */
