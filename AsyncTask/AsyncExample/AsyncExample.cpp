#include <iostream>
#include <future>
#include <thread>

using namespace std;

int factorial(int x)
{
    this_thread::sleep_for(chrono::seconds(3));
    int res = 1;
    for (int i = 2; i <= x; i++)
        res *= i;
    //throw false;
    return res;
}

int main()
{
    setlocale(LC_ALL, "");
    //auto
    std::future<int> asyncRes1 = std::async(
        std::launch::async,
        factorial,
        10
    );
    auto asyncRes2 = std::async(
        std::launch::async,
        factorial,
        12
    );
    //.....
    cout << "Основной поток работает дальше\n";
    for (int i = 0; i < 50; i++)
    {
        cout << '.';
        this_thread::sleep_for(chrono::milliseconds(20));
    }
    if (asyncRes1.wait_for(chrono::seconds(0)) == future_status::ready
        && asyncRes2.wait_for(chrono::seconds(0)) == future_status::ready
        )
    {
        cout << "Результат готов\n";
        goto ready_1;
    }
    else
    {
        cout << "Результат не готов\n";
    }
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << '.';
        this_thread::sleep_for(chrono::milliseconds(20));
    }
    cout << endl;
    //....
ready_1:
    int fact1 = 0, fact2 = 0;
    try
    {
        fact1 = asyncRes1.get();
        fact2 = asyncRes2.get();
        cout << "факториал 10 = " << fact1 << endl;
        cout << "факториал 12 = " << fact2 << endl;
    }
    catch (...)
    {
        cout << "Исключение\n";
    }

}

