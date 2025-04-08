// ThreadWithParams.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
using namespace std;

void factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    cout << n << "!=" << res << endl;
}

int main()
{
    thread t1(factorial, 10);
    thread t2(factorial, 5);
    // ....
    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
}