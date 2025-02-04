#include <iostream>
void SelectionSort(int* array, int count)
{
    int i, k;
    int minI = 0; // индекс минимального найденного элемента
    int minVal = 0;  // значение минимального найденного элемента
    for (i = 0; i < count; i++) // для сортировки используем столько проходов основного цикла, сколько в массиве элементов
    {
        minVal = array[i]; // предполагаем, что минимальный элемент - это первый в последовательности
        for (int k = i; k < count; k++) // цикл поиска минимума в массиве
        {
            if (array[k] < minVal) // если очередной элемент меньше запомненного
            {
                minVal = array[k]; // обновляем значение минимума
                minI = k;                  // и запоминаем его индекс
            }
        }
        if (array[i] > minVal) // если минимальный элемент - не первый в списке
        {
            int t = array[i];          // то обмениваем значение первого элемента в списке
            array[i] = array[minI];    // с найденным минимальным
            array[minI] = t;
        }
    }
}
int main()
{
    int m[]{ 4,11,7,8,4,7,9,4,-5,-34, 0, 45, 211, -65 };
    int size = sizeof(m) / sizeof(int);
    for (int i = 0; i < size; i++)
        std::cout << m[i] << ' ';
    std::cout << '\n';
    SelectionSort(m, size);
    for (int i = 0; i < size; i++)
        std::cout << m[i] << ' ';

}