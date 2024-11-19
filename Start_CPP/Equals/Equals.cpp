#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout.precision(17);
    double eps = 0.000000000001;
    double v = 0;
    for (double x = -1; x < 1; x += 0.1)
    {
        if (abs(x - v) < eps)
        {
            cout << "Ура, это ноль!\n";
        }
        cout << x << endl;
    }
}
