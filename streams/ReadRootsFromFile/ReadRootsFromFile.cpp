#include <iostream>
#include <fstream>
using namespace std;

void DoSomething(
    double a,
    double b,
    double c,
    int count,
    double x1 = 0,
    double x2 = 0)
{
    //..
    switch (count)
    {
    case 0:
        cout << a << " " << b << " " << c
            << " 0\n";
        break;
    case 1:
        cout << a << " " << b << " " << c
            << " 1 " << x1 << "\n";
        break;
    case 2:
        cout << a << " " << b << " " << c
            << " 2 " << x1
            << " " << x2 << "\n";
        break;
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "");
    ifstream fin("..\\SEFiles\\results.txt");
    if (fin)
    {
        double a, b, c, x1, x2;
        int rootsCount;
        while (fin >> a >> b >> c >> rootsCount)
        {
            switch (rootsCount)
            {
            case 0:
                DoSomething(a, b, c, rootsCount);
                break;
            case 1:
                if (fin >> x1)
                {
                    DoSomething(a, b, c, rootsCount, x1);
                }
                else
                {
                    cout << "Файл поврежден, данные расчетов неверны.\n";
                }
                break;
            case 2:
                if (fin >> x1 >> x2)
                {
                    DoSomething(a, b, c, rootsCount, x1, x2);
                }
                else
                {
                    cout << "Файл поврежден, данные расчетов неверны.\n";
                }
                break;
            }
        }

        fin.close();
    }
}
