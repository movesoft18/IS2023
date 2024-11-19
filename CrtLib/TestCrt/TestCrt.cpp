#include <iostream>
#include "CrtLib.h"
using namespace std;
using namespace crt;

int main()
{

    setlocale(LC_ALL, "");
    SetCursorVisibility(false);
    std::cout << "Привет\n";
    SetTextColor(1);
    cout << "Синий на красном \n";
    SetTextBackground(14);
    cout << "Синий на желтом \n";
    GotoXY(20, 6);
    cout << "Текст по центру \n";
}

