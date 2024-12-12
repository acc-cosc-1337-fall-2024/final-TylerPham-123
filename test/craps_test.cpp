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