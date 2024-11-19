#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int i = 1;
    /*char answer = 'Н';
    while (true)
    {
        cout << i << " * " << i << " = " << i * i << endl;
        i++;
        cout << "Продолжить? (Y/N)";
        cin >> answer;
        if (answer != 'Y') break;
    }
    */
    i = 0;
    while (i < 1000)
    {
        i++;
        if (i % 17 != 0) continue;
        cout << i << " * " << i << " = " << i * i << endl;
    }
}


// break
// continue