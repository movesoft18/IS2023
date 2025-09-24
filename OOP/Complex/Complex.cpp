#include <iostream>
#include <sstream>
using namespace std;

class Complex
{
    double a; // действительная
    double b; // мнимая
    // (a + b * i)
public:
    Complex(double a = 0, double b = 0) : a(a), b(b) {}
    Complex& Add(const Complex& c);
    Complex& Sub(const Complex& c);
    Complex& Mul(const Complex& c);
    Complex& Div(const Complex& c);
    Complex& Add(double c);
    Complex& Sub(double c);
    Complex& Mul(double c);
    Complex& Div(double c);
    string ToString() const;
    double GetReal() const;
    double GetImag() const;

    // операции
    Complex& operator += (const Complex& c);
    Complex& operator -= (const Complex& c);
    Complex& operator *= (const Complex& c);
    Complex& operator /= (const Complex& c);
    Complex& operator += (double c);
    Complex& operator -= (double c);
    Complex& operator *= (double c);
    Complex& operator /= (double c);

    friend Complex operator + (double c1, const Complex& c2);
    friend istream& operator >> (istream& in, Complex& c);
};

Complex& Complex::Add(const Complex& c)
{
    a += c.a;
    b += c.b;
    return *this;
}

Complex& Complex::Sub(const Complex& c)
{
    a -= c.a;
    b -= c.b;
    return *this;

}

Complex& Complex::Mul(const Complex& c)
{
    a = a * c.a - b * c.b;
    b = a * c.b + c.a * b;
    return *this;

}

Complex& Complex::Div(const Complex& c)
{
    a = (a * c.a + b * c.b) / (c.a * c.a + c.b * c.b);
    b = (b * c.a - a * c.b) / (c.a * c.a + c.b * c.b);
    return *this;

}

Complex& Complex::Add(double c)
{
    a += c;
    return *this;

}

Complex& Complex::Sub(double c)
{
    a -= c;
    return *this;

}

Complex& Complex::Mul(double c)
{
    a *= c;
    b *= c;
    return *this;

}

Complex& Complex::Div(double c)
{
    this->Mul(1 / c);
    return *this;

}

string Complex::ToString() const
{
    ostringstream osst;
    char op = b >= 0 ? '+' : '-';
    osst << a << op << abs(b) << 'i';
    return osst.str();
}

double Complex::GetReal() const
{
    return a;
}

double Complex::GetImag() const
{
    return b;
}

Complex& Complex::operator+=(const Complex& c)
{
    return Add(c);
}

Complex& Complex::operator-=(const Complex& c)
{
    return Sub(c);
}

Complex& Complex::operator*=(const Complex& c)
{
    return Mul(c);
}

Complex& Complex::operator/=(const Complex& c)
{
    return Div(c);
}

Complex& Complex::operator+=(double c)
{
    return Add(c);
}

Complex& Complex::operator-=(double c)
{
    return Sub(c);
}

Complex& Complex::operator*=(double c)
{
    return Mul(c);
}

Complex& Complex::operator/=(double c)
{
    return Div(c);
}

/*
тип_результата operator + (список_параметров_операндов)
{

}
*/

Complex operator + (const Complex& c1, const Complex& c2)
{
    return Complex(
        c1.GetReal() + c2.GetReal(),
        c1.GetImag() + c2.GetImag()
    );
}

Complex operator + (const Complex& c1, double c2)
{
    return Complex(
        c1.GetReal() + c2,
        c1.GetImag()
    );
}

Complex operator + (double c1, const Complex& c2)
{
    return Complex(
        c2.a + c1,
        c2.b
    );
}

bool operator == (const Complex& c1, const Complex& c2)
{
    return c1.GetReal() == c2.GetReal() && c1.GetImag() == c2.GetImag();
}

bool operator != (const Complex& c1, const Complex& c2)
{
    return !(c1 == c2);
}

ostream& operator << (ostream& out, const Complex& c)
{
    out << c.ToString();
    return out;
}

istream& operator >> (istream& in, Complex& c)
{
    cout << "Введите действительную часть числа: ";
    in >> c.a;
    cout << "Введите мнимую часть числа: ";
    in >> c.b;
    return in;
}

int main()
{
    Complex x1(2, 4);
    Complex x2(3, 3);
    Complex x3(-7, -1);
    Complex x4;
    cin >> x4;
    cout << x4 << endl;
    cout << x1 << ' ' << x2 << ' ' << x3 << endl;
    //x3.Add(x1).Sub(x3).Div(x1).Mul(x2);
    //cout << x3.ToString() << '\n';
    //x2.Sub(x3);
    //cout << x2.ToString() << '\n';
    //x1.Mul(x2);
    //cout << x1.ToString() << '\n';
    
    x1 += x2;
    x1 = x1 + x2;
    cout << x1.ToString() << '\n';

    x3 = 777 + x3 + x1 + x2 + 555;
    cout << x3.ToString() << '\n';
}


