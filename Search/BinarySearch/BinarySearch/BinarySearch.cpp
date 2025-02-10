#include <iostream>
#include <conio.h>
using namespace std;

int BadBinarySearch(int* array, int count, int element)
{
    int left = 0;
    int right = count - 1;
    while (left < right)
    {
        int middle = (right + left) / 2;
        if (array[middle] == element)
            return middle;
        if (element < array[middle])
            right = middle;
        else left = middle + 1;
    }
    return -1;
}

int BinarySearch(int* array, int count, int element)
{
    int left = 0;
    int right = count - 1;
    while (left < right)
    {
        int middle = (right + left) / 2;
        if (element <= array[middle])
            right = middle;
        else left = middle + 1;
    }
    if (array[right] == element)
        return right;
    return -1;
}

int main()
{
    setlocale(LC_ALL, "");
    int m[] = { 1,2,4,5,5,6,6,6,7,7,7,8,12,16,17,17,29 };
    int size = sizeof(m) / sizeof(int);
    int value = 7;
    int index = BinarySearch(m, size, value);
    if (index == -1)
        cout << "Элемент не найден\n";
    while (index < size && m[index] == value)
    {
        cout << "Элемент найден под индексом " << index << endl;
        index++;
    }
}


/*          v
            v                                                             
1,2,4,5,5,6,7,7,7,7,7,8,12,16,17,17,29
               
0           6                   
            6
          */

