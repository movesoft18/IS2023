#include <iostream>
#include "SFML/Graphics.hpp"
#include "conio.h"

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(800, 600), "OOP Demo");

class PointBase
{
protected:
    float x, y; //координаты
    bool visible; // признак видимости

    CircleShape object; // вспомогательное поле - объект sfml
public:
    PointBase(float x, float y, bool visible) :
        x(x), y(y), visible(visible), object(CircleShape(1))
    {
        if (visible) show();
    }
    PointBase() : PointBase(0, 0, false) {}
    ~PointBase();
protected:
    void draw(bool visible);
public:
    void show();
    void hide();
    void move(float newX, float newY);
    void moveRel(float dx, float dy);
    void setX(float newX);
    void setY(float newY);

    bool getVisible() const;
    float getX() const;
    float getY() const;
};

PointBase::~PointBase()
{
    if (visible) hide();
}

void PointBase::draw(bool visible)
{
    auto col = Color::Transparent;
    if (visible)
        col = Color::White;
    //object.setRadius(1);
    object.setFillColor(col);
    object.setOutlineColor(col);
    object.setOutlineThickness(1);
    object.setPosition(x, y);
    window.draw(object);
}

void PointBase::show()
{
    draw(true);
    visible = true;
}

void PointBase::hide()
{
    draw(false);
    visible = false;
}

void PointBase::move(float newX, float newY)
{
    bool visState = visible;
    hide();
    x = newX;
    y = newY;
    if (visState) show();
}

void PointBase::moveRel(float dx, float dy)
{
    move(x + dx, y + dy);
   /* bool visState = visible;
    hide();
    x += dx;
    y += dy;
    if (visState) show();*/
}

void PointBase::setX(float newX)
{
    move(newX, y);
}

void PointBase::setY(float newY)
{
    move(x, newY);
}

bool PointBase::getVisible() const
{
    return visible;
}

float PointBase::getX() const
{
    return x;
}

float PointBase::getY() const
{
    return y;
}

int main()
{
    /*
    window.setFramerateLimit(1);
    window.clear(Color::Black);

    PointBase p1(100, 100, true), p2(10, 10, true), p3(50, 120, true);

    window.display();
    _getch();

    p1.move(200, 200);
    p2.moveRel(-5, 100);
    p3.move(120, 120);
    window.display();
    _getch();
    */
    const int count = 200; // количество отображаемых объектов
    window.clear();
    PointBase* points[count]; // массив указателей на объекты
    // генерируем случайные объекты
    for (int i = 0; i < count; i++)
    {
        float x = rand() % 800;
        float y = rand() % 600;
        points[i] = new PointBase(x, y, true);
    }
    window.display(); // отрисовываем окно
    _getch();
    window.clear();
    for (int i = 0; i < count; i++) // а здесь все точки, сместятся в новую позицию
        points[i]->moveRel(5, -3);
    window.display();
    _getch();
    window.clear();
    for (int i = 0; i < count; i++) // не забываем уничтожить объекты при завершении
        delete points[i];
    window.display(); // видим, что отработали деструкторы и объекты скылись
    _getch();

}


