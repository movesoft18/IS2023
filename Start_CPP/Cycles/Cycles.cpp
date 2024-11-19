#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int i = 1;
    while (i <= 9)
    {
        cout << i << " * " << i << " = " << i * i << endl;
        i++;
    }

    i = 1;
    do
    {
        cout << i << " * " << i << " = " << i * i << endl;
        i++;
    } while (i < 10);

/*    int age = 0;
    do
    {
        cout << "Введите свой возраст, лет (18-100):";
        cin >> age;
        if (age < 18 || age > 100)
        {
            cout << "Указан некорректный возраст\n";
        }
    } while (age < 18 || age > 100);
    */
    for (int i = 2; i < 10; i += 2)
    {
        cout << i << " * " << i << " = " << i * i << endl;
    }
    i = 1;
    for (;i <= 9;)
    {
        cout << i << " * " << i << " = " << i * i << endl;
        i++;
    }

   /* while (0) // 0 раз
    {
        //...
    }

    while (true) // бесконечный
    {

    }
    do {
    //...
    } while (true); // бесконечный

    do {
    //...
    } while (false); // 1 раз

    */
}
