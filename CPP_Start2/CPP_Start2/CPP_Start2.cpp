#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int a, b;      // объявляем переменные
    cout << "Программа сложения 2 чисел" << endl;
    cout << "Введите первое целое число: ";
    cin >> a;  
    cout << "Введите второе целое число: ";
    cin >> b;  
    int c = a + b;      // складываем
    cout << a << "+" << b << '=' << c;      // выводим результат в консоль
    _getch();
}
