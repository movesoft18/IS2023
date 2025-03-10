﻿#include <iostream>
#include <conio.h>
#include "time.h"
#include "windows.h"
#include "CrtLib.h"

using namespace std;
using namespace crt;

const int LX = 75;
const int LY = 30;

const char player = (char)1;
// 0 - пустое пространство
// 1 - стена
// 2 - выход
// 3 - игрок
// 4 - монета
// 5 - алмаз
// 6 - время

int maze[LY][LX] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,0,0,0,0,0,0,1,1,1,1,0,0,4,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,0,0,0,1,1,0,0,6,0,1,1,1,1,0,0,0,4,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,6,5,6,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,5,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,4,0,0,1,1,1,1,1,1,},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,2,},
    {1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,},
    {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,6,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,},
    {1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,0,4,0,0,0,0,1,0,1,0,0,0,0,1,4,1,1,1,1,0,1,1,1,0,4,1,1,1,1,1,1,1,1,1,1,},
    {1,0,1,1,1,1,1,1,0,0,4,0,0,0,0,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,6,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,1,1,1,},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,},
    {1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,5,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,},
    {1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,},
    {1,5,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,1,1,4,1,1,1,0,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,},
    {1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,},
    {1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,},
    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,5,0,0,1,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,0,1,0,0,0,0,4,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,4,1,1,1,1,1,4,1,1,0,1,1,1,1,0,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,0,4,0,0,0,1,4,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,4,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,},
    {1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,4,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,0,1,1,1,6,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,0,0,0,1,5,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,4,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,1,1,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
    {1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};

// глобальные переменные
int hx, hy; // позиция игрока в лабиринте
int score = 0; // счет игры

int gameState = 0; // 0 - игра продолжается, 1 - выигрыш, 2 - закончилось время
int timeLimit = 600; // лимит игры в секундах
int gameTime; // оставшееся время

clock_t tstart; // значение счетчика таймера при старте игры

// Функция обновляет текущий счет на экране
void UpdateScore(int score)
{
    GotoXY(35, 30); // ставим курсор на последнюю строку консоли
    setlocale(LC_ALL, "ru-RU"); // включаем локаль, ориентированную на кириллицу
    cout << "СЧЕТ: " << score;  // выводим счет на экран
    setlocale(LC_ALL, "C"); // возвращаем настройки локали по умолчанию
}

// Функция обновляет оставшееся время до окончания игры
// параметр t функции - это текущее значение системного таймера, на момент вызова функции
void UpdateClock(clock_t t)
{
    gameTime = timeLimit - (t - tstart) / CLOCKS_PER_SEC; /* вычисляем оставшееся время в секундах
                    и помещаем результат в gameTime. (t-tstart) - кол-во миллисекунд, прошедшее
                    с момента старта игры. CLOCKS_PER_SEC - константа, определяющая количество
                    изменений системного таймера за 1 секунду. Для Windows это значение
                    равно 1000. Вычитая из timeLimit время, прошедшее с начала игры, мы вычисляем
                    остаток времени в секундах */
    setlocale(LC_ALL, "ru-RU"); // переключаем локаль
    if (gameTime < 0) // проверяем, закончилось ли время
    {
        gameState = 2; // если да, то обновляем статус игры на 2 - игрок ПРОИГРАЛ
    }
    else
    {  // если время осталось
        GotoXY(49, 30); // ставим курсор на последнюю строку
        cout << "Осталось: " << gameTime << " секунд "; // выводим остаток времени в консоль
    }
    setlocale(LC_ALL, "C"); // восстанавливаем настройки локали
}

// Функция печатает в консоли лабиринт
void PrintMaze(int maze[LY][LX], int sizeX, int sizeY)
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            switch (maze[i][j])
            {
            case 0:
                cout << ' ';
                break;
            case 1:
                cout << (char)178;
                break;
            case 2:
                cout << (char)176;
                break;
            case 3:
                cout << player;
                break;
            case 4:
                cout << '$';
                break;
            default:
                cout << '?';
            case 5:
                cout << (char)4;
                break;
            case 6:
                cout << (char)30;
                break;

            }
        }
        cout << endl;
    }
}

// Функция определяет позицию игрока в массиве, обновляя значения глобальных переменных hx и hy
void FindFirstPlayerPosition(int maze[LY][LX], int sizeX, int sizeY)
{
    for (int i = 0; i < sizeY; i++)  // цикл пробегает массив по строкам
    {
        for (int j = 0; j < sizeX; j++) // цикл пробегает массив по столбцам
        {
            if (maze[i][j] == 3)    // проверяем, если текущий элемент равен 3 - нашли
            {                       // требуемую позицию
                hx = j;             // записываем столбец в hx
                hy = i;             // записываем строку в hy
                return;             // завершаем работу функции
            }
        }
    }
    hx = hy = 0;    // если ничего не нашли - предполагаем, что игрок в позиции 0,0
}                   // это нелогично, но пока ничего предпринимать не будем, решение
                    // этой проблемы будет вашим персональным заданием по рефакторингу игры

//Функция скрывает игрока с экрана и убирает его из лабиринта
void HidePlayer()
{
    maze[hy][hx] = 0; // записываем в текущую позицию матрицы число 0
    GotoXY(hx, hy); // устанавливаем курсор в позицию игрока в консоль
    cout << ' ';    // и печатаем пробел
}

// функция показывает на экране игрока и записывает его в лабиринт
void ShowPlayer()
{
    maze[hy][hx] = 3; // записываем в текущую позицию матрицы число 0
    GotoXY(hx, hy); // устанавливаем курсор в позицию игрока в консоль
    cout << player; // и печатаем образ игрока
}

// Функция перемещает игрока вверх на одну клетку, если это разрешено
void GoUp()
{
    if (hy > 0) // проверяем, если текущая позиция игрока > 0 - то перемещаться можно
    {
        switch (maze[hy - 1][hx]) // проверяем, что находится в ячейке матрицы на строку выше
        {
        case 0:                  // если там пусто, то ход возможен.
            HidePlayer();       // вызываем функцию, которая скрывает игрока с экрана и убирает из текущей позиции матрицы
            hy--;               // уменьшаем координату y
            ShowPlayer();       // отображаем игрока в новой позиции
            break;
        case 2:                 // если там дверь выхода
            HidePlayer();       // по аналогии с вышестоящим кодом перемещаем игрока в новую позицию
            hy--;
            ShowPlayer();
            UpdateScore(score += 500);  // добавляем 500 бонусов за достижение выхода из лабиринта
            gameState = 1;              // изменяем статус игры на ВЫИГРЫШ
            break;
        case 4:                 // если там монета
            HidePlayer();       // по аналогии с вышестоящим кодом перемещаем игрока в новую позицию
            hy--;
            ShowPlayer();
            UpdateScore(score += 100); // добавляем 100 бонусов за сбор монеты
            break;
        case 5:                 // если там алмаз
            HidePlayer();       // по аналогии с вышестоящим кодом перемещаем игрока в новую позицию
            hy--;
            ShowPlayer();
            UpdateScore(score += 300); // добавляем 300 бонусов за сбор алмаза
            break;
        case 6:                 // если там время
            HidePlayer();       // по аналогии с вышестоящим кодом перемещаем игрока в новую позицию
            hy--;
            ShowPlayer();
            UpdateClock(score += 10); // добавляем 10 секунд за сбор времени
            break;
        }
    }

}

// Функция перемещает игрока вниз на одну клетку, если это разрешено
void GoDown()
{
    if (hy < LY - 1)
    {
        switch (maze[hy + 1][hx])
        {
        case 0:
            HidePlayer();
            hy++;
            ShowPlayer();
            break;
        case 2:
            HidePlayer();
            hy++;
            ShowPlayer();
            UpdateScore(score += 500);
            gameState = 1;
            break;
        case 4:
            HidePlayer();
            hy++;
            ShowPlayer();
            UpdateScore(score += 100);
            break;
        case 5:
            HidePlayer();
            hy++;
            ShowPlayer();
            UpdateScore(score += 300);
            break;
        case 6:
            HidePlayer();
            hy++;
            ShowPlayer();
            UpdateClock(score += 10);
            break;
        }
    }
}

// Функция перемещает игрока вправо на одну клетку, если это разрешено
void GoRight()
{
    if (hx < LX - 1)
    {
        switch (maze[hy][hx + 1])
        {
        case 0:
            HidePlayer();
            hx++;
            ShowPlayer();
            break;
        case 2:
            HidePlayer();
            hx++;
            ShowPlayer();
            UpdateScore(score += 500);
            gameState = 1;
            break;
        case 4:
            HidePlayer();
            hx++;
            ShowPlayer();
            UpdateScore(score += 100);
            break;
        case 5:
            HidePlayer();
            hx++;
            ShowPlayer();
            UpdateScore(score += 300);
            break;
        case 6:
            HidePlayer();
            hx++;
            ShowPlayer();
            UpdateClock(score += 10);
            break;
        }
    }
}

//// Функция перемещает игрока влево на одну клетку, если это разрешено
void GoLeft()
{
    if (hx > 0)
    {
        switch (maze[hy][hx - 1])
        {
        case 0:
            HidePlayer();
            hx--;
            ShowPlayer();
            break;
        case 2:
            HidePlayer();
            hx--;
            ShowPlayer();
            UpdateScore(score += 500);
            gameState = 1;
            break;
        case 4:
            HidePlayer();
            hx--;
            ShowPlayer();
            UpdateScore(score += 100);
            break;
        case 5:
            HidePlayer();
            hx--;
            ShowPlayer();
            UpdateScore(score += 300);
            break;
        case 6:
            HidePlayer();
            hx--;
            ShowPlayer();
            UpdateClock(score += 10);
            break;
        }
    }
}

// Функция обрабатывает события клавиатуры и управляет игрой
void Control()
{
    tstart = clock();  // запоминаем счетчик системного таймера в момент старта игры.
    UpdateScore(score); // обновляем счет игры, изначально он нулевой
    unsigned char x;  // это переменная хранит символ, соответствующий нажатой клавише
    while (gameState == 0)  // цикл игры - пока gameState == 0, игра идет
    {
        UpdateClock(clock());   // обновляем оставшееся время
        if (_kbhit())           // если была нажата клавиша - то обрабатываем ее, иначе следующая
        {                       // итерация игрового цикла
            x = _getch();       // считываем символ нажатой клавиш,
            if (x == 27) return;// если это символ Esc (27) то это выход из игры
            if (x == 0xe0)      // если это символ с кодом 0xE0 (шестнадцатеричное)
                switch (_getch()) // то считываем еще один символ (некоторые клавиши выдают двойные коды)
                {
                case 72:          // если 2-й символ код 72, то это клавиша курсор вверх
                    GoUp();       // идем вверх
                    break;
                case 80:          // если 2-й символ код 80, то это клавиша курсор вниз
                    GoDown();   // идем вниз
                    break;
                case 75:        // если 2-й символ код 75, то это клавиша курсор влево
                    GoLeft();   // идем влево
                    break;
                case 77:
                    GoRight();  // если 2 - й символ код 77, то это клавиша курсор вправо
                    break;      // идем вправо
                }
        }
        Sleep(200);             // останавливаем игру на 200 мсек, если этого не делать, то
    }                           // обновление игры будет слишком быстрым, мы не сможем управлять
}                               // игроком, а также напрасно нагрузим процессор ненужной работой

// Функция main, которая выполняется при запуске прграммы
int main()
{
    system("mode con cols=80 lines=31");
    system("cls");
    PrintMaze(maze, LX, LY);
    FindFirstPlayerPosition(maze, LX, LY);
    HideCursor();
    Control();
    ShowCursor();
}
