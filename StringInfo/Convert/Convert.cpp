// Convert.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int value;
    double d;
    float f;
    long l;
    unsigned long ul;
    getline(cin, str);
    //cin >> str;
    cout << str << endl;
    value = stoi(str);
    d = stod(str);
    f = stof(str);
    l = stol(str);
    ul = stoul(str);
    cout << value << endl;

    str = to_string(d);
}

