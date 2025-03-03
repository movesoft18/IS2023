#include <iostream>
void BubbleSort1(int* array, int count)
{
    bool exchange = false; // признак того, что за один проход цикла были найдены элементы
    // подлежащие обмену
    int n = count - 1;
    do
    {
        exchange = false; //  в начале цикла полагаем, что обменов не будет
        for (int i = 0; i < n; i++)  // цикл перебора элементов массива
        {
            if (array[i] > array[i + 1]) // если текущий элемент больше следующего
            {
                int t = array[i]; // меняем их местами
                array[i] = array[i + 1];
                array[i + 1] = t;
                exchange = true; // обозначаем, что перестановка была - значит, возможно элементы массива еще полностью не отсортированы
            }
        }
        n--;    // в первого прохода самый большой элемент встает на свое место
        // соответственно в следующий раз его уже проверять не нужно  -
        // уменьшаем количество проверяемых элементов на 1
    } while (exchange); // повторяем, если за цикл была хотя бы одно перестановка
}  // если перестановок не было - то массив отсортирован

void BubbleSort2(int* array, int count)
{
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - 1; j++)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
                //int tmp = array[j];
                //array[j] = array[j + 1];
                //array[j + 1] = tmp;
}

int main()
{
    int m[]{ 4,11,7,8,4,7,9,4,-5,-34, 0, 45, 211, -65 };
    int size = sizeof(m) / sizeof(int);
    for (int i = 0; i < size; i++)
        std::cout << m[i] << ' ';
    std::cout << '\n';
    BubbleSort1(m, size);
    for (int i = 0; i < size; i++)
        std::cout << m[i] << ' ';
}