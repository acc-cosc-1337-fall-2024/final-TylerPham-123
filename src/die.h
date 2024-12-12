//
#ifndef DIE_H
#define DIE_H

#include <random>

class Die {
public:
    Die();
    int roll();

private:
    int sides;
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;
};

#endif