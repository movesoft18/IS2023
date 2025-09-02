#include <iostream>
using namespace std;

class MyPoint
{
    // поля
    const int ttt;
    int x = 0, y = 0; 
    int color = 0;
    bool visible = false;
    // методы
    // сеттеры
public:
    MyPoint(int x, 
        int y, 
        int color = 15, 
        bool visible = true) : ttt{ 12 }, x {x},
                                y{ y }, color(color),
                                visible(visible)
    {
        /*
        this->x = x;
        this->y = y;
        this->color = color;
        this->visible = visible;
        */
    }

   /* MyPoint() : MyPoint(0, 0, 0, false)
    {
        //MyPoint(0, 0, 0, false); - ошибка, будет создан временный объект
    }
    */
    ~MyPoint()
    {
        if (visible) hide();
    }

    void setColor(int color)
    {
        this->color = color;
        if (visible) show();
    }

    MyPoint& moveTo(int newX, int newY) 
    {
        bool vis = getVisibility();
        if (vis) hide();
        x = newX;
        y = newY;
        if (vis) show();
        return *this;
    }
    void setX(int newX);
    void setY(int newY);

    void show(){}
    void hide(){}
    // геттеры
    int getColor() const {}
    int getX() const {}
    int getY() const {}
    bool getVisibility() const {}
};

class MyCircle : public MyPoint
{
    int radius;

    void setRadius(int newRadius);
    int getRadius() const;

    MyCircle(int x,
        int y,
        int radius,
        int color,
        bool visible = false): MyPoint(x,y,color, visible),
                            radius(radius)
    {

    }
};

void MyPoint::setX(int newX)
{
    bool vis = getVisibility();
    if (vis) hide();
    x = newX;
    if (vis) show();
}

void MyPoint::setY(int newY)
{
    bool vis = getVisibility();
    if (vis) hide();
    y = newY;
    if (vis) show();
}




int main()
{
    MyPoint point1(10,10, 2);

    point1.moveTo(100, 100).moveTo(200, 45).moveTo(30, 89);
    //point1.visible = true;
    //point1.x = 600;
    point1.show();
    MyPoint* point2 = new MyPoint;
    point2->moveTo(300, 450);
    point2->show();
    delete point2;
}


