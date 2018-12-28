#include <config.h>
#include <compiler/Counter.h>

#include <stdexcept>
#include <string>

using std::logic_error;

namespace jags {
 
Counter::Counter(Range const &range)
  : RangeIterator(range)
{
  if (range.ndim(false) != 1)
    throw logic_error("Attempt to construct Counter from non-scalar Range");
}

Counter &Counter::next()
{
  nextLeft();
  return *this;
}

} //namespace jags
