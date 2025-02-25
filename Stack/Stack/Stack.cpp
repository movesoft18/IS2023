#include <iostream>
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
    StackItem* item = new StackItem{ point, stack }; // этой строчкой можно заменить следующие 2
    /*StackItem* item = new StackItem; // создаем новый элемент стека
    item->point = point; //инициализируем данные в элементе
    item->next = stack; //корректируем указатель на следующий элемент*/
    stack = item; // теперь вершина стека указывает на добавленный элемент
}

Point Pop() // извлекает элемент из стека и возвращает его значение
{
    Point result; // здесь будет результат
    StackItem* temp; // временная переменная
    if (stack == nullptr) // если стек пуст
    {
        throw std::runtime_error("Невозможно извлечь элемент. Стек пуст.");
       /* result.x = 0;   // то операция извлечения невозможна
        result.y = 0;   // пока мы не умеем реагировать на такую ситуацию
        return result;  // поэтому пока возвращаем Point {0,0}*/
    }
    result = stack->point; //записываем возвращаемые данные
    temp = stack;   // запоминаем элемент на вершине стека
    stack = temp->next; // перемещаем вершину стека на следующий за извлекаемым элемент
    delete temp;    // освобождаем память, занятую элементом на вершине
    return result; // возвращаем результат
}

void Print(Point point) // для визуализации содержимого стека
{
    cout << "x: " << point.x << ", y: " << point.y << endl;
}

int main()
{
    setlocale(LC_ALL, "");
    try
    {
        Push(Point{ 1,1 });
        Push(Point{ 10,-7 });
        Push(Point{ 0,0 });
        auto p1 = Pop();
        auto p2 = Pop();
        auto p3 = Pop();
        auto p4 = Pop();
        Print(p1);
        Print(p2);
        Print(p3);
        cout << IsEmpty();
    }

    catch (const std::runtime_error& err)
    {
        cout << "runtime error " <<err.what() << endl;
    }
    catch (const std::exception& err)
    {
        cout << "Произошла какая-то ошибка." << endl;
    }
}