#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
namespace qe
{
	struct Roots
	{
		int rootsCount; // кол-во корней 0 - нет, 1 - 1, 2 - бескон.
		double x1, x2;  // корни
	};

	Roots QuadraticEquation(double a, double b, double c);
}

