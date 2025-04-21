#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex m;

void Increment()
{
    for (int i = 0; i < 2000000; i++)
    {
        m.lock();
        counter++;
        m.unlock();
    }
        
}

int main()
{
    cout << "start value counter=" << counter << endl;
    //Increment();
    //Increment();
    thread t1(Increment);
    thread t2(Increment);
    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    cout << "counter=" << counter << endl;
}

