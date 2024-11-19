#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    double a, b, result;
    char operation;
    cout << "Введите выражение для вычисления, отделяя операнды и операции пробелом,\n";
    cout << "Например 12 + 7: ";
    cin >> a >> operation >> b;
    switch (operation)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
    case '.':
        result = a * b;
        break;
    case '/':
    case '\\':
        result = a / b;
        break;
    case '^':
        result = pow(a, b);
        break;
    default:
        cout << "Неизвестная операция " << operation << endl;
        operation = ' ';
    }
    if (operation != ' ')
        cout << a << operation << b << "=" << result << endl;


    /*if (operation == '+')
    {
        cout << a << operation << b << "=" << a + b << endl;
    } 
    else if (operation == '-')
    {
        cout << a << operation << b << "=" << a - b << endl;
    }
    else if (operation == '*')
    {
        cout << a << operation << b << "=" << a * b << endl;
    }
    else if (operation == '/')
    {
        cout << a << operation << b << "=" << a / b << endl;
    }
    else
        cout << "Неизвестная операция " << operation << endl;
*/

}


