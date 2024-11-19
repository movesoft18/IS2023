#include <conio.h>
#include <iostream>
using namespace std;
/*
тип_результата Имя_функции(список параметров)
{
    код алгоритма функции
}
*/

void PrintHello() 
{
    cout << "Hello!\n";
    return; // это можно не писать для void
}

bool isLeapYear(int year) // заглушка dummy
{
    // ...
    return false;
}

bool isHappyTicket(int num)
{
    // ...
    return false;
}

double getPosition(
    double x0 = 0, // начальная позиция
    double v0 = 0, // нач. скорость
    double a = 0,  // ускорение
    double t = 0)  // время
{
    return x0 + v0 * t + (a * t * t) / 2;
}

// если rootsCount == 1, берем только х1
// если rootsCount == 2, берем х1 и x2
struct Roots
{
    int rootsCount; // количество корней 
    double x1, x2; // корни
};

Roots GetQuadraticEquationRoots(double a, double b, double c)
{
    double d = b * b - 4 * a * c;
    if (d > 0)
        return Roots{2,(-b + sqrt(d)) / (2 * a),(-b - sqrt(d)) / (2 * a)};
    if (d == 0)
        return Roots{ 1, -b / (2 * a), 0 };
    return Roots{ 0,0,0 };
}

int main()
{
    setlocale(LC_ALL, "");
    cout << getPosition(100, 1.5, -0.02, 50) << endl;
    cout << getPosition() << endl;
    for (int i = 0; i <= 2024; i++)
        if (isLeapYear(i))
            cout << i << " ";

    int x, y;
    cin >> x >> y;
    PrintHello();
    int maxValue = max(x + y, x - y);
    cout << maxValue << endl;
    double a, b, c;

    cout << "Программа отыскания...\n";
    cout << "Введите через пробел значение коэффициентов a b c: ";
    cin >> a >> b >> c;
    Roots roots = GetQuadraticEquationRoots(a, b, c);
    if (roots.rootsCount == 0)
        cout << "Нет корней\n";
    else if (roots.rootsCount == 1)
        cout << "x=" << roots.x1 << endl;
    else 
        cout << "x1=" << roots.x1 << " x2=" << roots.x2 << endl;
    _getch();
}

int max(int a, int b)
{
    return a > b ? a : b;
}