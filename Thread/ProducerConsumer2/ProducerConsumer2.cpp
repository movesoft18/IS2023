#include <iostream>
#include <queue>
#include <semaphore>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

counting_semaphore<1> sem(0);
queue<string> tasks;
mutex mut;

void Producer(int count)
{
    for (int i = 0; i < count; i++)
    {
        this_thread::sleep_for(chrono::seconds(rand() % 3)); // имитация работы
        string task = "Task " + to_string(i); // текст задачи
        mut.lock();
        tasks.push(task); // ставим задачу в очередь
        mut.unlock();
        string message = "Создана задача " + task + '\n';
        cout << message;
        sem.release(); // разблокируем семафор
    }
    mut.lock();
    tasks.push("End.");
    mut.unlock();
    sem.release();
}

void Consumer()
{
    while (true)
    {
        if (tasks.empty())
        {
            sem.acquire(); // жду открытия семафора
            continue;
        }
        mut.lock();
        string task = tasks.front(); // читаю задачу
        tasks.pop(); // удаляю ее из очереди
        mut.unlock();
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
