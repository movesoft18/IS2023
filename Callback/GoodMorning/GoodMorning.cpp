// GoodMorning.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <functional>
using namespace std;

string GoogMorning() { return "Доброе утро!"; }
string GoogAfternoon() { return "Добрый день!"; }
string GoogEvening() { return "Добрый вечер!"; }
string GoogNight() { return "Добрый ночер!"; }

string (*mess (int hour))()
{
    if (hour < 6) return GoogNight;
    else if (hour < 11) return GoogMorning;
    else if (hour < 16) return GoogAfternoon;
    else return GoogEvening;
}

std::function<string()> mess1(int hour)
{
    if (hour < 6) return GoogNight;
    else if (hour < 11) return GoogMorning;
    else if (hour < 16) return GoogAfternoon;
    else return GoogEvening;
}

int main()
{
    setlocale(LC_ALL, "");
    int hour;
    cin >> hour;
    cout << mess(hour)() << " " << mess1(hour)() << endl;
}

