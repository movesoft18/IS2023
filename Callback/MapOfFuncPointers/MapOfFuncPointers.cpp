// MapOfFuncPointers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

void PrintHello() { cout << "Привет, я рад вас видеть!\n"; }
void PrintGoodbye() { cout << "До скорых встреч!\n"; }
void PrintUnknownMessage() { cout << "Я не знаю, как ответить на ваш вопрос\n"; }

map<string, void(*)()> answers = {
    {"Привет", PrintHello},
    {"Пока", PrintGoodbye }
};

int main()
{
    system("chcp 1251");
    string mes = " ";
    getline(cin, mes);
    while (mes != "")
    {
        if (answers.count(mes) > 0)
            answers[mes]();
        else
            PrintUnknownMessage();
        getline(cin, mes);
    }
    cin.get();
}

