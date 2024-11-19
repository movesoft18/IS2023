// LibExample.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "LibExample.h"
#include "math.h"

bool IsLeapYear(int year)
{
	return false;
}

bool isPrime(int value)
{
    for (int i = 2; i <= sqrt(value); i++)
    {
        if (value % i == 0)
            return false;
    }
    return true;
}