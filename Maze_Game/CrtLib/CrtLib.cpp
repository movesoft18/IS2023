#include "windows.h"

namespace crt
{
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
}
