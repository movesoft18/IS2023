#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

map <string, string> tel;
bool PhoneBookChanged = false;
string FN = "phonebook.txt";

string Replace(string Source, char c1, char c2)
{
    for (int i = 0; i < Source.length(); i++)
        if (Source[i] == c1) Source[i] = c2;
    return Source;
}

void SetContact(string FIO, string phone)
{

    tel[FIO] = phone;
    PhoneBookChanged = true;

}

void PrintContacts()
{
    system("cls");
    for (auto i : tel)
    {
        cout << "ФИО: " << i.first << "   " << i.second << endl;
    }
    cout << endl << "Нажмите любую клавишу...";
    _getch();
}

bool SavePhoneBook(string FileName)
{
    ofstream f(FileName);
    if (f)
    {
        for (auto i : tel)
        {
            string s = Replace(i.first, ' ', '_');
            string s1 = Replace(i.second, ' ', '-');
            f << s << "\t" << s1 << endl;
        }
        f.close();
        return true;
    }
    return false;
}

void LoadPhoneBook(string FileName)
{
    ifstream f(FileName);
    string s, s1;
    if (f)
    {
        while (f >> s >> s1)
        {
            s = Replace(s, '_', ' ');
            tel[s] = s1;
            //tel.insert(pair<string, string>(s, s1));
            //tel.insert(make_pair(s, s1));
        }
        f.close();
    }
}


char MainMenu()
{
    system("cls");
    cout << "1. Добавить/изменить контакт" << endl;
    cout << "2. Вывод списка контактов" << endl;
    cout << "3. Удалить контакт" << endl;
    cout << "0. Выход" << endl;
    cout << "Ваш выбор >>";
    return _getch();
}

void DoSetContact()
{
    string n, t;
    system("cls");
    cout << "Введите ФИО контакта: ";
    getline(cin, n);
    cout << "Введите телефон контакта: ";
    getline(cin, t);
    SetContact(n, t);
}

void DeleteContact()
{
    string n;
    system("cls");
    cout << "Введите ФИО контакта: ";
    getline(cin, n);
    if (tel.count(n) == 0) {
        cout << "Контакт не найден. Нажмите любую клавишу...";
        _getch();
        return;
    }


    tel.erase(n);
    PhoneBookChanged = true;
    cout << "Контакт успешно удален. Нажмите любую клавишу...";
    _getch();
}

int main()
{
    system("chcp 1251");
    LoadPhoneBook(FN);
    char key = 0;
    while (key != '0')
    {
        key = MainMenu();
        switch (key)
        {
        case '1':
            DoSetContact();
            break;
        case '2':
            PrintContacts();
            break;
        case '3':
            DeleteContact();
            break;
        }
    }
    if (PhoneBookChanged) 
        SavePhoneBook(FN);
    //_getch();

}

