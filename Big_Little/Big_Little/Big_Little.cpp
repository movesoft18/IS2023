// Big_Little.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "winsock.h"
using namespace std;
int main()
{
    short int x = 0x1122;
    unsigned char* byte = (unsigned char*)& x;
    cout << hex << (int)byte[0] << " " << hex << (int)byte[1] << " " 
          << endl;
    if (byte[0] == 0x22 && byte[1] == 0x11)
        cout << "little endian\n";
    else
        cout << "big endian\n";
   
}
