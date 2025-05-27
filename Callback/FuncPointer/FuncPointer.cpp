
#include <iostream>
using namespace std;

int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
double sum_d(double a, double b) { return a + b; }


int main()
{
    // указатель на данные
    int* px;
    px = new int{ 5 };
    // указатель на функцию
    int (*addition)(int, int);
    addition = sum;
    cout << sum(3, 5) << endl;
    cout << addition(3, 5) << endl;
    addition = sub;
    cout << addition(3, 5) << endl;

    delete px;
}

