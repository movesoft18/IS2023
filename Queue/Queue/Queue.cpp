// Queue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
// элемент очереди: данные - символ
struct Queue
{
    char value;
    Queue* next;
};

Queue* tail = nullptr; // указатель на хвост очереди
int qLength = 0; // длина очереди

bool IsEmpty() // возвращает true, если очередь пуста
{
    return tail == nullptr;
}

void Enqueue(const char val) //помещение элемента в очередь
{
    Queue* temp;
    temp = new Queue;   // создаем новый элемент очереди
    temp->value = val;  // заполняем данные
    temp->next = tail;  // добавляем в
    tail = temp;        // конец очереди
    qLength++;                 // увеличиваем счетчик элементов очереди
}


char Dequeue() // извлечение элемента из очереди
{
    if (IsEmpty()) 
        throw std::runtime_error("Невозможно извлечь элемент из пустой очереди");
    // но мы пока не знаем как
    Queue* temp = tail;               // так как мы не храним указатель на голову очереди
    Queue* temp1 = tail;              // нам нужно пробежаться по всему списку
    if (temp->next == nullptr) tail = nullptr;
    while (temp->next != nullptr) // пробегаемся до головы очереди
    {
        temp1 = temp;
        temp = temp->next;
    }
    char result = temp->value; // выделяем результат - символ, хранящийся в первом элементе
    temp1->next = nullptr;
    delete temp; // удаляем элемент из очереди
    qLength--;          // уменьшаем кол-во элементов очереди
    return result;      // возвращаем результат
}

void DeleteQueue()  // удаление всей очереди и памяти
{                                 // собственно, это та же процедура удаления, как и с обычным линейным списком
    Queue* next;
    Queue* temp = tail;
    while (temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }
    tail = nullptr;
}

int main()
{
    setlocale(LC_ALL,"");
    Enqueue('a');
    Enqueue('b');
    Enqueue('c');
    auto q1 = Dequeue();
    auto q2 = Dequeue();
    auto q3 = Dequeue();
    auto q4 = Dequeue();
    cout << q1 << endl;
    cout << q2 << endl;
    cout << q3 << endl;

}

