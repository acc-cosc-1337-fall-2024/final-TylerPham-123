//
#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Roll {
public:
    Roll(Die& d1, Die& d2) : die1(d1), die2(d2) {}

    void roll_dice() {
        rolled_value = die1.roll() + die2.roll();
    }

    int roll_value() const {
        return rolled_value;
    }

private:
    Die& die1;
    Die& die2;
    int rolled_value;
};

#endif