// MultiDimArrays.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    double a[12]{ 1,2,3,4,5,6,7,8,9,0, -1, -2 };

    for (int i = 0; i < 10; i++)
        cout << a[i] << endl;

    for (auto e : a)
        cout << e << endl;

    int matrix[3][4]{
        {1,2,3,4},
        {5,6,7,8},
        {9,0,-1,-8},
    };
    int ba[3][5];
    // инициализация матрицы с консоли
    for (int i = 0; i < 3; i++) // цикл по строкам
    {
        for (int j = 0; j < 5; j++) // цикл по столбцам
        {
            cout << "Введите элемент матрицы m[" << i << "][" << j << "]: ";
            cin >> ba[i][j];
        }
    }
    // вывод матрицы в консоль
    for (int i = 0; i < 3; i++) // цикл по строкам
    {
        for (int j = 0; j < 5; j++) // цикл по столбцам
        {
            // печатаем элемент строки
            cout << ba[i][j] << "\t";
        }
        cout << endl;
    }

}

