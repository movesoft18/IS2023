#include <iostream>
#include <conio.h>
#include "../../Maze_Game/CrtLib/CrtLib.h"
#include "windows.h"
using namespace std;

struct Point // структура, описывающая точку
{
    int x, y;
};

struct StackItem // собственно сам элемент стека
{
    Point point; // точка
    StackItem* next;  // указатель на следующий элемент в списке
};

StackItem* stack = nullptr; // указатель на вершину стека, изначально стек пуст

bool IsEmpty() // функция проверяет пуст ли стек
{
    return stack == nullptr;
}

void Push(const Point& point) // Добавление точки в стек (аналог функции AddFirst линейного списка)
{
    //StackItem* item = new StackItem{ point, stack }; // этой строчкой можно заменить следующие 2
    StackItem* item = new StackItem; // создаем новый элемент стека
    item->point = point; //инициализируем данные в элементе
    item->next = stack; //корректируем указатель на следующий элемент
    stack = item; // теперь вершина стека указывает на добавленный элемент
}

Point Pop() // извлекает элемент из стека и возвращает его значение
{
    Point result; // здесь будет результат
    StackItem* temp; // временная переменная
    if (stack == nullptr) // если стек пуст
        throw  std::runtime_error("Невозможно извлечь элемент из пустого стека");
    result = stack->point; //записываем возвращаемые данные
    temp = stack;   // запоминаем элемент на вершине стека
    stack = temp->next; // перемещаем вершину стека на следующий за извлекаемым элемент
    delete temp;    // освобождаем память, занятую элементом на вершине
    return result; // возвращаем результат
}

void ClearStack()
{
    auto temp = stack; // вспомогательный указатель, который будет указывать на удаляемый элемент
    // в то время, как firstItem мы будем продвигать вперед на следующие элемент
    while (stack != nullptr) // пока не достигли конца списка
    {
        stack = stack->next; // передвигаем "курсор" на следующий элемент
        delete temp;    // удаляем текущий
        temp = stack; // обновляем temp, так чтобы он указывал на следующий
    } // в конце цикла firstItem будет равен nullptr
}

void Print(Point point) // для визуализации содержимого стека
{
    cout << "x: " << point.x << ", y: " << point.y << endl;
}

char buf[20][51] = { // массив символов области которого мы заливаем
    "##################################################",
    "#P                                               #",
    "#  ################ ##########  ###              #",
    "#     #             #        #  # #              #",
    "#     #             #  ###   #  # #     3        #",
    "#     #             #  ###   #### #              #",
    "#     #             #      #                     #",
    "#      ##############        #################   #",
    "#      #               ####                  #   #",
    "#      #    #####      ####        ######    #   #",
    "#      #               ####                  #   #",
    "#      ##############        #################   #",
    "#          #        #        #                   #",
    "#          #        #   ###  #        #333####   #",
    "#       556#        #   ###  #        #          #",
    "#    333   #        #E       #        #          #",
    "#    2222  #        ##########        #          #",
    "#   9  ####   #############################      #",
    "#           #                                    #",
    "##################################################"
};

bool isMazeValid(Point start, char fillColor, char borderColor)
{
    Push(start); // помещаем координаты затравочного пикселя в стек
    while (!IsEmpty()) // пока стек не пуст
    {
        Point p = Pop();  // извлекаем пиксел из стека
        if (buf[p.y][p.x] == 'E') {
            ClearStack();
            return true;
        }
        if (buf[p.y][p.x] != fillColor) // если ему не присвоено значение заливки
        {
            buf[p.y][p.x] = fillColor; // заливаем
            crt::GotoXY(p.x, p.y); // позиционируем курсов в позицию "пикселя"
            cout << fillColor; // отображаем на экране
        }

        if (buf[p.y][p.x + 1] != fillColor && buf[p.y][p.x + 1] != borderColor) // проверяем пиксед справа от текущего
            Push(Point{ p.x + 1, p.y }); // если он не закрашен и не является границей, то помещаем его координаты в стек
        if (buf[p.y][p.x - 1] != fillColor && buf[p.y][p.x - 1] != borderColor) // то же для левого
            Push(Point{ p.x - 1, p.y });
        if (buf[p.y - 1][p.x] != fillColor && buf[p.y - 1][p.x] != borderColor) // то же для верхнего
            Push(Point{ p.x, p.y - 1 });
        if (buf[p.y + 1][p.x] != fillColor && buf[p.y + 1][p.x] != borderColor) // то же для нижнего
            Push(Point{ p.x, p.y + 1 });
        Sleep(20); // задержка для визуализации алгоритма
    }
    return false;
}



int main()
{
    setlocale(LC_ALL, "");
    for (int i = 0; i < 20; i++) cout << buf[i] << endl; // печатаем массив на экране
    bool res = isMazeValid(Point{ 1, 1 }, '+', '#'); // заполняем область символами -
    if (res) {
        cout << "Лабиринт проходимый\n";
    }
    else
    {
        cout << "Лабиринт не проходимый\n";
    }
    //FloodFill(Point{ 1, 1 }, '.', '1'); // заполняем область символами .
    _getch();

}