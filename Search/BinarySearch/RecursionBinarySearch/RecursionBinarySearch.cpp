#include <iostream>
#include <conio.h>
using namespace std;

int BinarySearch(int array[], int count, int element, int left, int right)
{
    if (array[left] == element)
        return left;
    if (left < right)
    {      
        int middle = (right + left) / 2;
        if (element <= array[middle])
            return BinarySearch(array, count, element, left, middle);
        else 
            return BinarySearch(array, count, element, middle + 1, right);
    }
    return -1;
}

int RecursionBinarySearch(int array[], int count, int element)
{
    if (array == nullptr || count < 1) return -1;
    return BinarySearch(array, count, element, 0, count - 1);
}

int main()
{
    setlocale(LC_ALL, "");
    int m[] = { 1,2,4,5,5,6,6,6,7,7,7,8,12,16,17,17,29 };
    int size = sizeof(m) / sizeof(int);
    int value = 17;
    int index = RecursionBinarySearch(m, size, value);
    if (index == -1)
        cout << "Элемент не найден\n";
    while (index < size && m[index] == value)
    {
        cout << "Элемент найден под индексом " << index << endl;
        index++;
    }
}
