#include <iostream>
#include <thread>
using namespace std;

void threadFunc()
{
    cout << "Привет из потока с Id: "
        << this_thread::get_id() << endl;
    for (int i = 0; i < 2000; i++)
        cout << this_thread::get_id() << " ";
}

int main()
{
    setlocale(LC_CTYPE, "");
    thread thr1(threadFunc);
    thread thr2(threadFunc);
    cout << "Привет из главного потока\n";
    for (int i = 0; i < 2000; i++)
        cout << "Главный поток! ";
    if (thr1.joinable()) thr1.join();
    if (thr2.joinable()) thr2.join();
    cout << "Все потоки завершены\n";
}
