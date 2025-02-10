#include <iostream>
using namespace std;

struct Person // структура данных, которую сортируем
{
    int id;
    string Name;
    int age;
    char gender;
    string company;
};

void BubbleSort(Person* array[], int count)
{
    bool exchange = false; // признак того, что за один проход цикла были найдены элементы
    // подлежащие обмену
    int n = count - 1;
    do
    {
        exchange = false; //  в начале цикла полагаем, что обменов не будет
        for (int i = 0; i < n; i++)  // цикл перебора элементов массива
        {
            if (array[i]->age > array[i + 1]->age) // вот здесь сравниваем ключи сортировки, обращаясь через указатель к данным
            {
                auto t = array[i]; // но меняем местами не данные, а указатели на эти данные
                array[i] = array[i + 1];
                array[i + 1] = t;
                exchange = true; // обозначаем, что перестановка была - значит, возможно элементы массива еще полностью не отсортированы
            }
        }
        n--;
    } while (exchange); // повторяем, если за цикл была хотя бы одно перестановка
}  // если перестановок не было - то массив отсортирован

void Print(Person* p[], int count) // функция вывода данных на экран
{
    for (int i = 0; i < count; i++)
    {
        cout << "id: " << p[i]->id << " Name: " << p[i]->Name << " age: " << p[i]->age << " gender: " << p[i]->gender
            << " Company: " << p[i]->company << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    Person persons[]{ // исходный массив структур
        {5, "Иванов", 23, 'М', "Яндекс"},
        {4, "Петров", 32, 'М', "Ростелеком"},
        {1, "Сидоров", 41, 'М', "Лукойл"},
        {2, "Васюкова", 20, 'Ж', "Транснефть"},
        {6, "Иванов", 54, 'М', "Вектор"},
        {3, "Дятлова", 31, 'Ж', "ИжГТУ"},
        {7, "Дугин", 38, 'М', "УдГУ"},
    };
    const int size = sizeof(persons) / sizeof(Person); // размер массива
    Person* p[size]; // массив указателей
    for (int i = 0; i < size; i++) p[i] = &persons[i]; // присваиваем каждому указателю адрес соответствующего элемента массива данных
    BubbleSort(p, size); // сортируем массив указателей на данные
    Print(p, size); // выводим результат
}