
#include <iostream>
using namespace std;

int main()
{
    void* pointer;
    int value = 120;
    int* p;
    double* d;
    char* str;
    int a[10];
    p = &value;
    pointer = &value;
    cout << value << " " << *p << endl;
    value = 100;
    cout << value << " " << *p << endl;
    *p = 1000;
    cout << value << " " << *p << endl;

    d = new double;
    *d = 576647.46734;
    cout << *d << endl;
    delete d;

    //std::cout << "Hello World!\n";



    // 1. Объявление указателя
    int* x; //int* x = new int;
    // 2. Выделение памяти для хранения данных
    x = new int;
    // 3. Использование указателя по назначению
    //...
    *x = 46546;
    //...
    // 4. Освобождение памяти
    delete x;
    x = nullptr;
    // *x = 7678;

    int a[10000];
}

