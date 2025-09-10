#include <iostream>

using namespace std;

class StaticExample
{
    int id;
    static int generatorId;
public:
    static int field;
    static const int value = 333;
    StaticExample() { id = generatorId++; }
    int getId() { return id; }
    static int getGeneratorId() { return generatorId; }
    static int getNextId();
};

int StaticExample::generatorId = 1;
int StaticExample::field = 0;

int StaticExample::getNextId()
{
    return generatorId;
}

int main()
{
    StaticExample se1, se2, se3, se4;
    cout << se1.getId() << endl;
    cout << se2.getId() << endl;
    cout << se3.getId() << endl;
    cout << se4.getId() << endl;
    cout << StaticExample::getGeneratorId() << endl;
    //cout << se4.getGeneratorId() << endl;

    se1.field = 2;
    StaticExample::field = 10;
}


