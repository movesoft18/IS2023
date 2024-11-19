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
    int a[10]{ 1,2,3,4,5,6,78,8,9,0 };
    int* pointer = a;
    for (int i = 0; i < 10; i++) cout << *pointer++ << endl;
    int* array = new int[size];
    int* index = array;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> *index;
        sum += *index;
        index++;
        
    }
    index = array;
    cout << "Сумма " << size << " элементов массива = " << sum << endl;
    index += 5;
    cout << *index << endl;
    delete[] array;
    array = nullptr;
    //...

    char str[] = "261727127";
    char str1[10];
    char* s = str;
    char* s1 = str1;
    while (*s1++ = *s++);
    //while (*s != 0) cout << *s++ << endl;
    cout << str1 << endl;
}

