#include "pch.h"
#include "LinearEq.h"

TEST(LinearEqTests, NoSolition) {
	auto result = LinearEquation(0, 3);
	EXPECT_EQ(result.count, 0);
}

TEST(LinearEqTests, InfinitySolutions) {
	auto result = LinearEquation(0, 0);
	EXPECT_EQ(result.count, 3);
}