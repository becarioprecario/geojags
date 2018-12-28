#include <config.h>
#include <function/LinkFunction.h>

using std::string;

namespace jags {

LinkFunction::LinkFunction (string const &name, string const &link)
    : Function (name, 1), _link(link)
{
}

string const & LinkFunction::linkName () const
{
    return _link;
}

} //namespace jags
