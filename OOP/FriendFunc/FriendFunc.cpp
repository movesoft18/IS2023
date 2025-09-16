#include <iostream>
#include <string>
class Counter
{
private:
    int m_value;
public:
    Counter() { m_value = 0; }
    void add(int value) { m_value += value; }
    int getCounter() const { return m_value; }

    // Делаем функцию reset() дружественной классу Counter
    friend void reset(Counter& counter);
};

class Point
{
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}
    //...
    /*void toString()
    {
        std::cout << "(" << x << "," << y << ")";
    }*/
    friend void toString(Point& point);
    friend bool isEqual(const Point& p1, const Point& p2);
};

// (3,4)
// (x:3, y:4)
// [x:3, y:4]
// {x=3, y=4}


// Функция reset() теперь является другом класса Counter
void reset(Counter& counter)
{
    // И мы имеем доступ к закрытым членам объектов класса Counter
    counter.m_value = -10;
}

void toString(Point& point)
{
    //point.x++;
    //point.y++;
    std::cout << "[" << point.x << "," << point.y << "]";
}

bool isEqual(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

int main()
{
    Counter one;
    one.add(4); // добавляем 4 к m_value
    reset(one); // сбрасываем m_value в 0
    Point p(20, 30);
    //p.toString();
    toString(p);
    return 0;
}
