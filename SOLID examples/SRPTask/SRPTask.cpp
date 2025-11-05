#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class QuadraticEquation
{
    double _a, _b, _c;
    vector<double> results;
public:
    QuadraticEquation(double a, double b, double c): _a(a), _b(b), _c(c){}
    virtual void Solve()
    {
        results.clear();
        double d = _b * _b - 4 * _a * _c;
        if (d > 0)
        {
            results.push_back((-_b + sqrt(d) / (2 * _a)));
            results.push_back((-_b - sqrt(d) / (2 * _a)));
        }
        else if (d == 0)
        {
            results.push_back((-_b / (2 * _a)));
        }
    }
    const vector<double>& GetResults() const
    {
        return results;
    }
    void SetA(double a) { _a = a; }
    void SetB(double b) { _b = b; }
    void SetC(double c) { _c = c; }
    double GetA() const { return _a; }
    double GetB() const { return _b; }
    double GetC() const { return _c; }
    bool SaveResults(string filename) const
    {
        ofstream f(filename);
        if (f)
        {
            f << _a << " " << _b << " " << _c << " ";
            for (auto r : results)
            {
                f << r << " ";
            }
            f << endl;
            f.close();
            return f.fail();
        }
        return false;
    }
    void PrintResult() const
    {
        cout << _a << " " << _b << " " << _c << " ";
        for (auto r : results)
        {
            cout  << r << " ";
        }
        cout << endl;
    }
    void InputData()
    {
        cout << "Введите коэф. a: ";
        cin >> _a;
        cout << "Введите коэф. b: ";
        cin >> _b;
        cout << "Введите коэф. c: ";
        cin >> _c;
    }
};

int main()
{
    QuadraticEquation e(1, 2, -2);
    e.Solve();
    e.PrintResult();
    e.SaveResults("1.txt");
    e.InputData();
    e.Solve();
    e.PrintResult();
}

