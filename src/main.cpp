#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    Die die1, die2;
    Shooter shooter(die1, die2);

    // Come Out Phase
    ComeOutPhase comeOutPhase;
    Roll* roll = shooter.throw_dice();
    std::cout << "Rolled " << roll->roll_value() << " start of come out phase" << std::endl;

    while (comeOutPhase.get_outcome(*roll) == RollOutcome::natural ||
           comeOutPhase.get_outcome(*roll) == RollOutcome::craps) {
        std::cout << "Roll again" << std::endl;
        delete roll;
        roll = shooter.throw_dice();
        std::cout << "Rolled " << roll->roll_value() << std::endl;
    }

    // Point Phase
    int point = roll->roll_value();
    std::cout << "Rolled " << point << " start of point phase" << std::endl;
    std::cout << "Roll until " << point << " or 7 is rolled" << std::endl;

    PointPhase pointPhase(point);
    delete roll;
    roll = shooter.throw_dice();

    while (pointPhase.get_outcome(*roll) != RollOutcome::seven_out &&
           pointPhase.get_outcome(*roll) != RollOutcome::point) {
        std::cout << "Rolled " << roll->roll_value() << " roll again" << std::endl;
        delete roll;
        roll = shooter.throw_dice();
    }

    std::cout << "Rolled " << roll->roll_value() << " end of point phase" << std::endl;
    delete roll;

    shooter.display_rolled_values();

    return 0;
}