// SumPtr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    /*
    * int a,b,c;
    */
    int* a = new int;
    int* b = new int;
    int* c = new int;
    cout << *a;
    setlocale(LC_ALL, "");
    cout << "Введите первое число ";
    cin >> *a;
    cout << "Введите второе число ";
    cin >> *b;
    *c = *a + *b;
    cout << *c;
    delete a, b, c;
    a = b = c = nullptr;
    if (a != nullptr)
    {
        //..
    }
}

