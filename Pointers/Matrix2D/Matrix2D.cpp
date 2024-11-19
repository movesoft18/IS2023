// Matrix2D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    int rows = 3;
    int cols = 3;
    // выделяем память
    int** arr = new int* [rows]; // выделяем память под массив указателей на строки
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols]; // выделяем память под массив для каждой строки
    
    // заполняем массив с консоли

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];

    // печать массива

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << '\t';
        cout << endl;
    }



    // удаление массива
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;
}
