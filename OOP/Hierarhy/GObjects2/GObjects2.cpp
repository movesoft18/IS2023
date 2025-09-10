#include <iostream>
#include <conio.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
// Окно рендеринга (глобальный параметр)
RenderWindow window(VideoMode(800, 600), "OOP Demo");

// базовый класс
class PointBase
{
protected:
    // основные поля
    float x, y;
    bool visible;
    // вспомогательные поля
    CircleShape object;
    static sf::RenderWindow* window; // статическое поле (указатель), ссылающееся на окно рендеринга
public:
    // статический метод, позволяющий для всех объектов задать единое окно рендеринга
    static void SetRenderWindow(sf::RenderWindow* win)
    {
        window = win;
        // PointBase::window = win; // или так, через имя класса;
    }

    // конструктор с параметрами
    PointBase(float x, float y, bool visible) : x(x), y(y), visible(visible), object(CircleShape(1))
    {
        if (visible) Show();
    }
    // конструктор по умолчанию
    PointBase() :PointBase(0, 0, false)
    {
    }
    // деструктор (всегда делаем виртуальным)
    virtual ~PointBase()
    {
        if (visible)
            Hide();

    }
    // метод отрисовки объекта - виртуальный метод

    virtual void Draw(bool show)
    {
        if (!window) return;
        if (show)
        {
            object.setFillColor(Color::White);
            object.setOutlineColor(Color::White);
        }
        else
        {
            object.setFillColor(Color::Black);
            object.setOutlineColor(Color::Black);
        }
        object.setOutlineThickness(1);
        object.setPosition(x, y);
        window->draw(object); // обращаемся уже к статическому полю класса
    }

    // метод отображения точки

    void Show()

    {

        Draw(true);

        visible = true;

    }

    // метод скрытия точки

    void Hide()

    {

        Draw(false);

        visible = false;

    }

    // метод перемещения точки в новую абсолютную позицию

    void Move(int newX, int newY)

    {

        bool visibleState = visible;

        Hide();

        x = newX;

        y = newY;

        if (visibleState) Show();

    }



    // метод перемещения точки в новую относительную позицию

    void MoveRel(int dx, int dy)

    {

        bool visibleState = visible;

        Hide();

        x += dx;

        y += dy;

        if (visibleState) Show();

    }



    // геттеры - получение защищенных полей

    bool GetVisible()

    {

        return visible;

    }



    float GetX()

    {

        return x;

    }



    float GetY()

    {

        return y;

    }

    // сеттеры - изменение защищенных полей

    void SetX(float newX)

    {

        Move(newX, y); // используем готовый метод перемещения точки

    }

    void SetН(float newY)

    {

        Move(x, newY); // используем готовый метод перемещения точки

    }

};



// класс, реализующий цветную точку - наследуем его от базового PointBase

class ColorPoint : public PointBase

{

protected:

    // добавляем новое свойство - цвет

    Color color;

public:

    // конструкторы не наследуются, поэтому заводим конструктор с параметром

    // в списке инициализации вызываем конструктор базового класса, не забываем !!!

    ColorPoint(int x, int y, Color color = Color(255, 255, 255), bool visible = true) :PointBase(x, y, false), color(color)

    {

        if (visible) Show();

    }

    // деструктор

    ~ColorPoint() override

    {

        // в принципе в данной схеме нам новый деструктор не нужен, нормально отработает и

        // деструктор базового класса

        // однако приучите себя создавать всегда деструктор в унаследованном классе

        if (visible) Hide();

    }

    // переопределяем виртуальный метод отрисовки точки,

    // т.к. каждый объект отрисовывает себя по своему

protected:

    void Draw(bool show) override

    {

        if (!window) return;

        if (show)

        {

            object.setFillColor(color);

            object.setOutlineColor(color);

        }

        else

        {

            object.setFillColor(Color::Black);

            object.setOutlineColor(Color::Black);

        }

        object.setOutlineThickness(1);

        object.setPosition(x, y);

        window->draw(object);// обращаемся уже к статическому полю класса

    }

};





class Circle : public ColorPoint

{

protected:

    float radius;



    void Draw(bool show) override

    {

        if (!window) return;

        // устанавливаем прозрачный цвет фона

        object.setFillColor(Color::Transparent);

        // задаем радиус

        object.setRadius(radius);

        if (show)

        {

            object.setOutlineColor(color);

        }

        else

        {

            object.setOutlineColor(Color::Black);

        }

        object.setOutlineThickness(1);

        object.setPosition(x, y);

        window->draw(object);

    }



public:

    Circle(float x, float y, float radius, Color color = Color::White, bool visible = false) :

        ColorPoint(x, y, color, false), radius(radius)

    {

        if (visible) Show();

    }

    ~Circle()

    {

        if (visible) Hide();

    }



};



class FillCircle : public Circle

{

protected:

    Color fillColor;



    void Draw(bool show) override

    {

        if (!window) return;

        // задаем радиус

        object.setRadius(radius);

        if (show)

        {

            object.setFillColor(fillColor);

            object.setOutlineColor(color);

        }

        else

        {

            object.setFillColor(Color::Black);

            object.setOutlineColor(Color::Black);

        }

        object.setOutlineThickness(1);

        object.setPosition(x, y);

        window->draw(object);

    }



public:

    FillCircle(float x, float y, float radius, Color color = Color::White, Color fillColor = Color::Black, bool visible = false) :

        Circle(x, y, radius, color, false), fillColor(fillColor)

    {

        if (visible) Show();

    }

    ~FillCircle()

    {

        if (visible) Hide();

    }



};
// инициализация статического поля
sf::RenderWindow* PointBase::window = nullptr;

int main()
{
    const int count = 200; // количество отображаемых объектов
    window.clear();
    PointBase::SetRenderWindow(&window); // задаем окно рендеринга
    PointBase* points[count]; // массив указателей на объекты
    // генерируем случайные объекты

    for (int i = 0; i < count; i++)

    {

        float x = rand() % 800;

        float y = rand() % 600;

        int objectType = rand() % 6;

        switch (objectType)

        {

        case 0:

            points[i] = new PointBase(x, y, true);

            break;

        case 1:

            // заметьте, мы присваиваем созданный объект, независимо от его типа указателю на базовый класс

            points[i] = new ColorPoint(x, y, Color::Red, true);

            break;

        case 2:

            // заметьте, мы присваиваем созданный объект, независимо от его типа указателю на базовый класс

            points[i] = new Circle(x, y, rand() % 40, Color::Red, true);

            break;

        case 3:

            // заметьте, мы присваиваем созданный объект, независимо от его типа указателю на базовый класс

            points[i] = new FillCircle(x, y, rand() % 40, Color::Red, Color::Blue, true);

            break;

        default:

            points[i] = new PointBase(x, y, true);

        }

    }

    window.display(); // отрисовываем окно

    _getch();

    window.clear();

    for (int i = 0; i < count; i++) // а здесь все точки, независимо от их типа сместятся в новую позицию

        points[i]->MoveRel(5, -3);

    window.display();

    _getch();

    window.clear();

    for (int i = 0; i < count; i++) // не забываем уничтожить объекты при завершении

        delete points[i];

    window.display(); // видим, что отработали деструкторы и объекты скрылись

    _getch();



}