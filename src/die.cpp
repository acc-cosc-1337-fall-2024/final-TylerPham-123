//
#include "die.h"

Die::Die() : sides(6), rng(std::random_device{}()), dist(1, sides) {}

int Die::roll() {
    return dist(rng);
}