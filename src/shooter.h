//
#ifndef SHOOTER_H
#define SHOOTER_H

#include "roll.h"
#include <iostream>

class Shooter {
public:
    Shooter(Die& d1, Die& d2) : die1(d1), die2(d2) {}

    Roll* throw_dice() {
        Roll* roll = new Roll(die1, die2);
        roll->roll_dice();
        rolls.push_back(roll);
        return roll;
    }

    void display_rolled_values() const {
        for (Roll* roll : rolls) {
            std::cout << roll->roll_value() << " ";
        }
        std::cout << std::endl;
    }

    ~Shooter() {
        for (Roll* roll : rolls) {
            delete roll;
        }
    }

private:
    Die& die1;
    Die& die2;
    std::vector<Roll*> rolls;
};

#endif