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
    ofstream fout("results.txt", ios::app);
    if (fin && fout)
    {
        double a, b, c;
        while (fin >> a >> b >> c)
        { 
            auto result = GetQuadraticEquationRoots(a, b, c);
            switch (result.rootsCount)
            {
            case 0:
                fout << a << " " << b << " " << c
                    << " 0\n";
                break;
            case 1:
                fout << a << " " << b << " " << c
                    << " 1 " << result.x1 << "\n";
                break;
            case 2:
                fout << a << " " << b << " " << c
                    << " 2 " << result.x1
                    << " " << result.x2 << "\n";
                break;
            } 
        }
        fin.close();
        fout.close();
    }
}

