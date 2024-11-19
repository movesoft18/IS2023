// DynArrayTemplate.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    //...
};

template <typename T>
T* AllocateArray(int arraySize)
{
    return new T[arraySize];
}

template <typename T>
void InitArray(T* m, int size)//  функция печати массива. В функцию передается указатель на массив
{
    for (int i = 0; i < size; i++)
        cin >> m[i];
}

template <typename T>
void PrintArray(T* m, int size)//  функция печати массива. В функцию передается указатель на массив
{
    for (int i = 0; i < size; i++)
        cout << m[i] << ' ';
    cout << endl;
}

int main()
{
    int size = 5;
    double* a = AllocateArray<double>(size);
    InitArray(a, size);
    PrintArray(a, size);
    // работа с массивом
    delete[] a;
    a = nullptr; //  Не забываем присвоить указателю nullptr
}