#pragma once


struct LEResult
{
	double root; // корень если есть
	int count;   // кол-во корней 0 - нет, 1-1корень, 3 - бесконечное множество
};

LEResult LinearEquation(double a, double b);