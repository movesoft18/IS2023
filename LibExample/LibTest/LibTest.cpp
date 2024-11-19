// LibTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "LibExample.h"

int main()
{
    bool result = IsLeapYear(1900);
    std::cout << result << std::endl;
    for (int i = 1; i <= 1000; i++)
        if (isPrime(i))
            std::cout << i << " ";
}
