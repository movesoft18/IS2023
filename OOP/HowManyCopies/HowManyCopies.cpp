#include <iostream>
#include <vector>
using namespace std;
class A
{
public:
    int x, y, z;
    A(int x, int y, int z) : x(x), y(y), z(z) {}
    A() : x(0), y(0), z(0) {}
public:
    A(const A& other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        cout << "Объект A скопирован\n";
    }
public:
    void print() const
    {
        cout << x << " " << y << " " << z << endl;
    }
};

void Print(const A& object)
{
    object.print();
}
int main()
{
    vector<A> array;
    array.reserve(10);
    setlocale(LC_ALL, "");
    A a(1, 2, 3);
    A a1;
    a.print();
    a1.print();
    a1 = a;
    a1.print();
    A a2 = a1;
    a2.print();
    Print(a2);
    array.push_back(a);
    array.push_back(a1);
    array.push_back(a2);
    array.push_back(a2);
}