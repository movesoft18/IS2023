#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
using namespace std;

//Данные о человеке

struct Person1
{
    int id;         // id
    string name;    // имя
    int age;        // возраст
    char gender;    // пол;
};

void InvalidMethod_SaveDataToBinaryFile()   //запрашивает ввод данных с консоли и сохраняет в двоичный файл
{                                           // это неправильный способ, так как структуру, хранящую динамические
    Person1 p;                              // объекты сохранять напрямую в двоичный файл некорректно
    ofstream f("data.bin", ios::binary);    // открываем файл в двоичном режиме для записи
    if (f.is_open())                        // если открыт
    {
        while (true)                        // цикл
        {
            cin >> p.id;                    // здесь читаем данные так же, как и для текстового файла
            cin.get();
            getline(cin, p.name);
            cin >> p.age >> p.gender;
            if (cin.eof()) break;
            f.write((char*)&p, sizeof(p));  // а вто собственно запись структуры в файл
            // записываем столько байт, сколько размер структуры sizeof(p)
        }
        f.close();
    }
}



void InvalidMethod_LoadDataFromBinaryFile() // Читаем ранее сохраненные данные и выводим их в консоль
// На самом деле ничего не получится и мы столкнемся с ошибкой
{
    Person1 p;
    ifstream f("data.bin", ios::binary);
    if (f.is_open())
    {
        while (f.read((char*)&p, sizeof(p)))        // читать данные значительно проще, чем из текстового файла\
            // сразу читаем набор байт и записываем их в нашу структуру
        {
            cout << "Рег. номер: " << p.id << '\n';
            cout << "ФИО: " << p.name << '\n';      // здесь возникнет исключение
            cout << "Возраст: " << p.age << '\n';
            cout << "Пол: " << p.gender << '\n\n';
        }
        f.close();
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    InvalidMethod_SaveDataToBinaryFile();
    InvalidMethod_LoadDataFromBinaryFile();
}