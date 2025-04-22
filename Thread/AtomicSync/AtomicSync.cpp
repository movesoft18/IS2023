#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

atomic<int> counter(0);

void Increment()
{
    for (int i = 0; i < 2000000; i++)
    {
        counter++;
    }
}

int main()
{
    //cout << "start value counter=" << counter << endl;
    thread t1(Increment);
    thread t2(Increment);
    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    cout << "counter=" << counter << endl;
    
}

