#include <sampler/SingletonFactory.h>
#include <graph/StochasticNode.h>
#include <sampler/Sampler.h>

using std::vector;
using std::list;

namespace jags {

vector<Sampler *>
SingletonFactory::makeSamplers(list<StochasticNode*> const &nodes, 
			       Graph const &graph) const
{
    vector<Sampler *> samplers;
    for (list<StochasticNode*>::const_iterator p = nodes.begin();
	 p != nodes.end(); ++p)
    {
	if (canSample(*p, graph)) {
	    samplers.push_back(makeSampler(*p, graph));
	}
    }
    return samplers;
}

} //namespace jags
