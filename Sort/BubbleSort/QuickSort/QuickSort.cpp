#include <iostream>
void SortPart(int* a, int left, int right)
{
    int temp;
    int x = a[left + (right - left) / 2]; // вычисляем средний элемент
    //запись эквивалентна (l+r)/2,
    //но не вызывает переполнения на больших данных
    int i = left;
    int j = right;
    while (i <= j) // основной цикл обмена
    {
        while (a[i] < x) i++; // пропускаем слева все элементы, которые меньше опорного - они не интересы
        while (a[j] > x) j--; // пропускаем справа все элементы, которые больше опорного - они не интересы
        if (i <= j) // если правая и левая граница еще не сошлись, то мы нашли элементы, которые подлежат обмену
        {
            temp = a[i]; // меняем их местами
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right) SortPart(a, i, right); // рекурсивно сортируем правую часть подмассива
    if (left < j) SortPart(a, left, j); // рекурсивно сортируем левую часть подмассива
}

void QuickSort(int* array, int count)
{
    SortPart(array, 0, count - 1);
}





int main()
{
    int m[]{ 4,11,7,8,4,7,9,4,-5,-34, 0, 45, 211, -65 };
    int size = sizeof(m) / sizeof(int);
    for (int i = 0; i < size; i++)
        std::cout << m[i] << ' ';
    std::cout << '\n';
    QuickSort(m, size);
    for (int i = 0; i < size; i++)
        std::cout << m[i] << ' ';
}