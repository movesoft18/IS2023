#include "pch.h"
#include "LinearEq.h"

TEST(LinearEquationTests, NoSolution) {
	auto result = LinearEquation(0, 1);
	EXPECT_EQ(result.count, 0);
	//EXPECT_EQ(result.root, 0);
}

TEST(LinearEquationTests, InfinitySolutions) {
	auto result = LinearEquation(0, 0);
	EXPECT_EQ(result.count, 3);
	//EXPECT_EQ(result.root, 0);
}

TEST(LinearEquationTests, OneSolution) {
	auto result = LinearEquation(2, -2);
	EXPECT_EQ(result.count, 1);
	EXPECT_DOUBLE_EQ(result.root, 1);
}