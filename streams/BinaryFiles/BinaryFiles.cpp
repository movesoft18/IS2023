#include <iostream>
#include <fstream>
using namespace std;

struct Roots
{
    int rootsCount; // количество корней 
    double x1, x2; // корни
};

Roots GetQuadraticEquationRoots(double a, double b, double c)
{
    double d = b * b - 4 * a * c;
    if (d > 0)
        return Roots{ 2,(-b + sqrt(d)) / (2 * a),(-b - sqrt(d)) / (2 * a) };
    if (d == 0)
        return Roots{ 1, -b / (2 * a), 0 };
    return Roots{ 0,0,0 };
}

int main()
{
    setlocale(LC_ALL, "");
    ifstream fin("..\\data.txt");
    ofstream fout("results.bin", ios::binary);
    if (fin && fout)
    {
        double a, b, c;
        while (fin >> a >> b >> c)
        {
            auto result = GetQuadraticEquationRoots(a, b, c);
            fout.write((char*)&result, sizeof(Roots));
        }
        fin.close();
        fout.close();
    }
}

