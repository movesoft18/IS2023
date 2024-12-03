#include <iostream>
#include <fstream>
using namespace std;

struct Roots
{
    int rootsCount; // количество корней 
    double x1, x2; // корни
};

void DoSomething(
    int count,
    double x1 = 0,
    double x2 = 0)
{
    //..
    switch (count)
    {
    case 0:
        cout << " 0\n";
        break;
    case 1:
        cout  << " 1 " << x1 << "\n";
        break;
    case 2:
        cout << " 2 " << x1
            << " " << x2 << "\n";
        break;
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "");
    ifstream fin("..\\BinaryFiles\\results.bin", ios::binary);
    if (fin)
    {
        Roots roots;
        while (fin.read((char*)&roots, sizeof(Roots)))
        {
            DoSomething(
                roots.rootsCount,
                roots.x1,
                roots.x2);
        }
        fin.close();
    }
}
