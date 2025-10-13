#include <iostream>
#include "conio.h"
#include "Logger.h"

using namespace std;
// Логгируем события функции решения квадратного уравнения. Логгер передается по указателю
// Если передан пустой указатель, то логгирования нет.
// Обращаю внимание, что мы передаем ссылку на интерфейс ILogger, а не на какой-либо производный класс
// и это очень важно. Функция работает только с интерфейсом. Она не знает и не может знать, какой тип логгера
// в какой ситуации пользователю понадобится.
int GetQuadraticEquationRoots(double a, double b, double c, double& x1, double& x2, ILogger& logger = nullLogger)
{
    if (a == 0)
    {
        if (b != 0)
        {
            x1 = -c / b;
            // Выводим в лог сообщение. Неважно, какой фактически логгер будет использоваться. Код функции от этого не изменится
            logger.Log("При a=" + to_string(a) + " b=" + to_string(b) + " c=" + to_string(b) + " x=" + to_string(x1));
            return 1;
        }
        if (c == 0)
        {
            // Выводим в лог сообщение. Неважно, какой фактически логгер будет использоваться. Код функции от этого не изменится
            logger.Log("При a=" + to_string(a) + " b=" + to_string(b) + " c=" + to_string(b) + " Бесконечное множество решений");
            return 3;
        }
        // Выводим в лог сообщение. Неважно, какой фактически логгер будет использоваться. Код функции от этого не изменится
        logger.Log("При a=" + to_string(a) + " b=" + to_string(b) + " c=" + to_string(b) + " нет решений");
        return 0;
    }
    double d = b * b - 4 * a * c;
    if (d > 0)
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        // Выводим в лог сообщение. Неважно, какой фактически логгер будет использоваться. Код функции от этого не изменится
        logger.Log("При a=" + to_string(a) + " b=" + to_string(b) + " c=" + to_string(b) + " x1=" + to_string(x1) + " x2=" + to_string(x2));
        return 2;
    }
    if (d == 0)
    {
        x1 = -b / (2 * a);
        // Выводим в лог сообщение. Неважно, какой фактически логгер будет использоваться. Код функции от этого не изменится
        logger.Log("При a=" + to_string(a) + " b=" + to_string(b) + " c=" + to_string(b) + " x=" + to_string(x1));
        return 1;
    }
    // Выводим в лог сообщение. Неважно, какой фактически логгер будет использоваться. Код функции от этого не изменится
    logger.Log("При a=" + to_string(a) + " b=" + to_string(b) + " c=" + to_string(b) + " нет решений");
    return 0; //
}



int main()
{
    setlocale(LC_ALL, "");
    // создаем файловый логгер
    FileLogger fLogger("log.txt", true);
    // запускаем его
    bool fs = fLogger.StartLog();
    // создаем консольный логгер
    ConsoleLogger cLogger;
    // запускаем его
    bool cl = cLogger.StartLog();
    double x1, x2;
    // решаем уравнение с использованием файлового логгера
    int rootsCount = GetQuadraticEquationRoots(1, 2, 1, x1, x2, fLogger);
    // решаем 3 уравнения с использованием консольного логгера
    rootsCount = GetQuadraticEquationRoots(1, 2, -1, x1, x2, cLogger);
    rootsCount = GetQuadraticEquationRoots(5, 2, -1, x1, x2, cLogger);
    rootsCount = GetQuadraticEquationRoots(1, 2, 2, x1, x2, cLogger);
    // а здесь используется по умолчанию пустой логгер
    rootsCount = GetQuadraticEquationRoots(-1, 2, 1, x1, x2);
    _getch();
}