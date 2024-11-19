// DynArrays.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* array = new int[size];
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
        sum += array[i];
    }
    cout << "Сумма " << size << " элементов массива = " << sum << endl;
    delete[] array;
    array = nullptr;
    //...
}

