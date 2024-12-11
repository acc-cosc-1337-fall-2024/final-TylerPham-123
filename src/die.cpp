//
#include "die.h"

Die::Die() : rng(std::random_device{}()), dist(1, sides) {} // -> defines a distribution that generates random integers uniformly between 1 and sides.

int Die::roll()
{
    return dist(rng);
}