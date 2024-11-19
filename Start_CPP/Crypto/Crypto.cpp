#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    string s = "Мама мыла раму";
    char key = '!';
    for (int i = 0; i < s.length(); i++)
        s[i] ^= key;
    cout << s << endl;
    _getch();
    for (int i = 0; i < s.length(); i++)
        s[i] ^= key;
    cout << s << endl;
}

