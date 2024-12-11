//
#ifndef DIE_H
#define DIE_H

#include <random>
class Die
{
public:
    Die();
    int roll();

private:
    int sides = 6;
    std::mt19937 rng; // -> creates a Mersenne Twister pseudo-random number engine, providing a high-quality random number generator.
    std::uniform_int_distribution<int> dist;
};

#endif