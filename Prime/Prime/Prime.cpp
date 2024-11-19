#include <iostream>
#include <conio.h>
using namespace std;


bool isPrime(int value)
{
    if (value <= 2) {
        return true;
    }
    for (int i = 2; i <= sqrt(value); i++)
    {
        if (value % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int number = 2;
    while (number < 1000)
    {
        if (_kbhit()) break;
        if (isPrime(number))
            cout << number << " ";
        number++;
    }
    _getch();
    /*int n[]{ 2,9,67,89,34,56,67,22,331 };
    for (auto e : n)
        if (isPrime(e))
            cout << e << endl;*/
}