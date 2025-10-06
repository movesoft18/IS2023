#include "pch.h"
#include "CppUnitTest.h"
#include "qequation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QEquationTests
{
	TEST_CLASS(QEquationTests)
	{
	public:
		
		TEST_METHOD(TwoRoots)
		{
			//Initialization
			double a = 1;
			double b = 2;
			double c = -1;
			// Act
			auto result = qe::QuadraticEquation(a, b, c);
			// Assert
			Assert::AreEqual(2, result.rootsCount);
			Assert::AreEqual(
				0.414213562,
				result.x1,
				0.0000001
				);
			Assert::AreEqual(
				-2.414213562,
				result.x2,
				0.0000001
			);
		}

		TEST_METHOD(NoSolution)
		{
			//Initialization
			double a = 1;
			double b = 2;
			double c = 2;
			// Act
			auto result = qe::QuadraticEquation(a, b, c);
			// Assert
			Assert::AreEqual(0, result.rootsCount);

		}

		TEST_METHOD(OneRoot)
		{
			//Initialization
			double a = 1;
			double b = 2;
			double c = 1;
			// Act
			auto result = qe::QuadraticEquation(a, b, c);
			// Assert
			Assert::AreEqual(1, result.rootsCount);
			Assert::AreEqual(
				-1,
				result.x1,
				0.0000001
			);
		}

	};
}
