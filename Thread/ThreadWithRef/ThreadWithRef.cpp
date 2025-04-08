// ThreadWithParams.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
using namespace std;

void factorial(int n, int& result)
{
    result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
}

int main()
{
    int res1 = 0, res2 = 0;
    thread t1(factorial, 10, ref(res1));
    thread t2(factorial, 5, ref(res2));
    // ....
    for (int i = 0; i < 200; i++) cout << ".";
    cout << endl;
    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    cout << "10!=" << res1 << endl;
    cout << "5!=" << res2 << endl;
}