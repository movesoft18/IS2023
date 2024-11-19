// Matrix2DTemplate.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

template<typename T>
T** Create2DArray(int cols, int rows) // функция возвращает указатель на созданный в куче двумерный массив
{
    if (rows <= 0 || cols <= 0) return nullptr; // проверка размеров матрицы на допустимые величины
    T** m = new T * [rows];
    for (int i = 0; i < rows; i++)
        m[i] = new T[cols];
    return m;
}

template<typename T>
void Print2DIntArray(T** m, int cols, int rows)
{
    if (rows <= 0 || cols <= 0 || m == nullptr) return; // проверка размеров матрицы на допустимые величины, а также является ли указатель на матрицу пустым
    for (int j = 0; j < rows; j++)
    {
        if (m[j] != nullptr)
            for (int i = 0; i < cols; i++)
                cout << m[j][i] << " ";
        cout << endl;
    }
}

template<typename T>
void Destroy2DIntArray(T** m, int rows)
{
    if (rows <= 0 || m == nullptr) return;
    for (int i = 0; i < rows; i++)
        delete[] m[i];
    delete[] m;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int multiplier = -7;
    int cols = 3, rows = 2;
    int** m1 = Create2DArray<int>(cols, rows); // создаем двумерный массив 5 стр, 4 столбцов
    int** destMatrix = Create2DArray<int>(cols, rows);

    if (m1 && destMatrix)// если массив создан, то m1 != nullptr
    {
        //...
        for (int j = 0; j < rows; j++)
            for (int i = 0; i < cols; i++)
                cin >> m1[j][i]; // j - строка i - столбец 

        for (int j = 0; j < rows; j++)
            for (int i = 0; i < cols; i++)
                destMatrix[j][i] = multiplier * m1[j][i];

        cout << "Исходная матрица:\n";
        Print2DIntArray(m1, cols, rows); // печатаем в консоль его содержимое
        cout << "Результирующая матрица:\n";
        Print2DIntArray(destMatrix, cols, rows); // печатаем в консоль его содержимое
        Destroy2DIntArray(m1, rows); // освобождаем
        Destroy2DIntArray(destMatrix, rows); // освобождаем
        m1 = destMatrix = nullptr;
    }
}

