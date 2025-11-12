#include <iostream>
#include "MyListLib2.h"

int main()
{
    MyList<int> list;
    list.Add(3);
    list.Add(2);
    list.Add(1);
    for (int i = 0; i < list.Length(); i++)
    {
        std::cout << list[i] << std::endl;
    }
}

