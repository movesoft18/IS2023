#include <iostream>
#include <conio.h>

using namespace std;
// программа вычисления площади треугольника
int abcd;

int main()
{
    setlocale(LC_ALL, "");
    int x = 10, y = x + 20;
    double a, b, c, p, s;      // объявляем переменные
    cout << "Программа вычисления площади треугольника" << endl;
    cout << "Введите через пробел длины 3-х сторон: ";
    cin >> a >> b >> c;
    p = (a + b + c) / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "Площадь = " << s;      // выводим результат в консоль
    char c =_getch();
    cout << c << endl;
    _getch();
}
