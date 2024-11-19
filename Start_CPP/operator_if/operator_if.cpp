#include <conio.h>
#include <iostream>
using namespace std;



int main()
{
    setlocale(LC_ALL, "");

    double a, b, c = 0, x1, x2, d;

    cout << "Программа отыскания...\n";
    cout << "Введите через пробел значение коэффициентов a b c: ";
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d > 0)
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (d == 0)
    {
        x1 = -b / (2 * a);
        cout << "x = " << x1 << endl;
    }
    else
    {
        cout << "Корней нет" << endl;
    }
   
    _getch();     
}

/*
if (условие)
    оператор1;
else
    оператор2;

if (условие)
{
    оператор1_1;
    оператор1_2;
    ...
}
else
{
    оператор2_1;
    оператор2_2;
    ...
}

*/



