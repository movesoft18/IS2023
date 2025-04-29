#include <iostream>
#include <queue>
#include <semaphore>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

condition_variable var;
queue<string> tasks;
mutex mut;

void Producer(int count)
{
    for (int i = 0; i < count; i++)
    {
        this_thread::sleep_for(chrono::seconds(rand() % 3)); // имитация работы
        string task = "Task " + to_string(i); // текст задачи
        unique_lock<mutex> locker(mut); // элемент синхронизации 
        tasks.push(task); // ставим задачу в очередь
        string message = "Создана задача " + task + '\n';
        cout << message;
        var.notify_one(); // даем сигнал потоку, что создана новая задача
    }
    unique_lock<mutex> locker(mut); // элемент синхронизации 
    tasks.push("End.");
    var.notify_one(); // даем сигнал потоку
}

void Consumer()
{
    while (true)
    {
        unique_lock<mutex> locker(mut);
        if (tasks.empty())
        {
            var.wait(locker, []() {return !tasks.empty(); });
        }
        string task = tasks.front(); // читаю задачу
        tasks.pop(); // удаляю ее из очереди
        locker.unlock();
        if (task == "End.")
        {
            cout << "Заканчиваем работу.\n";
            return;
        }
        string message = "Обрабатывается задача " + task + '\n';
        cout << message;
        this_thread::sleep_for(chrono::seconds(rand() % 3)); // имитация работы
    }
}

int main()
{
    setlocale(LC_ALL, "");
    thread producer(Producer, 20);
    thread consumer(Consumer);
    producer.join();
    consumer.join();
}
