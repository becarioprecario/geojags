#include <config.h>

#include "MNormaltwo.h"
#include "MNormaltwoFactory.h"
#include <graph/StochasticNode.h>
#include <distribution/Distribution.h>
#include <sampler/MutableSampler.h>
#include <sampler/SingletonGraphView.h>

#include <string>
#include <vector>

using std::vector;
using std::string;

namespace jags {
namespace bugs {

bool 
MNormaltwoFactory::canSample(StochasticNode * snode, Graph const &graph) const
{
    return (snode->distribution()->name() == "dmnorm" || snode->distribution()->name() == "dmnormtwo") && !isBounded(snode);
}

Sampler *
MNormaltwoFactory::makeSampler(StochasticNode *snode, Graph const &graph) const
{
    unsigned int N = snode->nchain();
    vector<MutableSampleMethod*> methods(N, 0);

    SingletonGraphView *gv = new SingletonGraphView(snode, graph);
    for (unsigned int ch = 0; ch < N; ++ch) {
        methods[ch] = new MNormtwoMetropolis(gv, ch);
    }
    return new MutableSampler(gv, methods, "bugs::MNormaltwoMetropolis");
}

string MNormaltwoFactory::name() const 
{
    return "bugs::MNormaltwo";
}

}}
