#include <iostream>
#include "windows.h"
#include "conio.h"
using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void SetTextColor(int color)
{
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo(hStdOut, &sbi);
    color = color & 0b00001111;
    sbi.wAttributes = sbi.wAttributes & 0b11110000;
    sbi.wAttributes = sbi.wAttributes | color;
    SetConsoleTextAttribute(hStdOut, sbi.wAttributes);
}

void SetTextBackground(int color)
{
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo(hStdOut, &sbi);
    color = color & 0b00001111;
    sbi.wAttributes = sbi.wAttributes & 0b00001111; 
    sbi.wAttributes = sbi.wAttributes | (color << 4);
    SetConsoleTextAttribute(hStdOut, sbi.wAttributes);
}

void GotoXY(int x, int y)
{
    COORD position{ x, y };
    SetConsoleCursorPosition(hStdOut, position);
}

void SetCursorVisibility(bool visible)
{
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(hStdOut, &ci);
    ci.bVisible = visible;
    SetConsoleCursorInfo(hStdOut, &ci);
}

void ShowCursor()
{
    SetCursorVisibility(true);
}

void HideCursor()
{
    SetCursorVisibility(false);
}

int main()
{
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    setlocale(LC_ALL, "");
    SetCursorVisibility(false);
    std::cout << "Привет\n";
    SetConsoleTextAttribute(hStdOut, 14 + 64);
    std::cout << "Привет\n";
    GetConsoleScreenBufferInfo(hStdOut, &sbi);
    int color = sbi.wAttributes & 0b00001111; // 0x0F  15
    int bColor = (sbi.wAttributes & 0b11110000) >> 4; // 0xF0  240
    cout << "Позиция курсора: " <<
        sbi.dwCursorPosition.X << "," << sbi.dwCursorPosition.Y << endl;
    cout << "Цвет символов " << color << endl;
    cout << "Цвет фона " << bColor << endl;
    SetTextColor(1);
    cout << "Синий на красном \n";
    SetTextBackground(14);
    cout << "Синий на желтом \n";
    GotoXY(20, 6);
    cout << "Текст по центру \n";
    _getch();
}

/*
цвет фона    цвет символов
____^_____  _____^____
7  6  5  4  3  2  1  0
i  R  G  B  i  r  g  b



*/