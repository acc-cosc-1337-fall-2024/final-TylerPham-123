#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "die.h"
#include <cassert>

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}

TEST_CASE("Test die; Test 1: Roll 10 times")
{
	Die die;
	for (int i = 0; i < 10; ++i)
	{
		int roll = die.roll();
		assert(roll >= 1 && roll <= 6);
	}

	REQUIRE(die.roll() >= 1);
	REQUIRE(die.roll() <= 6);
}

TEST_CASE("Test die; Test 2: Roll 1000 times")
{
	Die die;
	int counts[6] = {0};
	for (int i = 0; i < 1000; ++i)
	{
		int roll = die.roll();
		counts[roll - 1]++;
	}

	REQUIRE(die.roll() >= 1);
	REQUIRE(die.roll() <= 6);
}
