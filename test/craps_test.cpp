#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "die.h"

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}

TEST_CASE("DieTest, RollInRange")
{
    Die die;
    for (int i = 0; i < 10; ++i)
    {
        int roll = die.roll();
        REQUIRE(roll >= 1);
        REQUIRE(roll <= 6);
    }
}

#include "roll.h"

TEST_CASE("RollTest, RollInRange")
{
    Die die1, die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int roll_value = roll.roll_value();
        REQUIRE(roll_value >= 2);
        REQUIRE(roll_value <= 12);
    }
}

#include "shooter.h"

TEST_CASE("ShooterTest, ThrowDice") {
    Die die1, die2;
    Shooter shooter(die1, die2);

    for (int i = 0; i < 10; ++i) {
        Roll* roll = shooter.throw_dice();
        int rollValue = roll->roll_value();
        REQUIRE(rollValue >= 2);
        REQUIRE(rollValue <= 12);
        delete roll;
    }
}

#include "come_out_phase.h"
#include "point_phase.h"

TEST_CASE("PhaseTest, ComeOutPhaseTest") {
    ComeOutPhase comeOutPhase;
    Die die1, die2;
    Roll roll(die1, die2);

    // Test natural
    roll.roll_dice();
    REQUIRE(comeOutPhase.get_outcome(roll) == RollOutcome::natural);

    // Test craps
    roll.roll_dice();
    REQUIRE(comeOutPhase.get_outcome(roll) == RollOutcome::craps);

    // Test point
    roll.roll_dice();
    REQUIRE(comeOutPhase.get_outcome(roll) == RollOutcome::point);
}

TEST_CASE("PhaseTest, PointPhaseTest") {
    PointPhase pointPhase(6);
    Die die1, die2;
    Roll roll(die1, die2);

    // Test point
    roll.roll_dice();
    REQUIRE(pointPhase.get_outcome(roll) == RollOutcome::point);

    // Test seven out
    roll.roll_dice();
    REQUIRE(pointPhase.get_outcome(roll) == RollOutcome::seven_out);

    // Test no point
    roll.roll_dice();
    REQUIRE(pointPhase.get_outcome(roll) == RollOutcome::nopoint);
}