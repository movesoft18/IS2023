// Functions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

bool IsLeapYear(int year)
{
	return false;
}

int Max(int array[], int size)
{
	//...
	int m = array[0];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > m)
		{
			m = array[i];
			index = i;
		}
	}
	return index;
}

double determinant(double m[3][3])
{
	m[2][2] = 100;
	return 0;
}

int main()
{
	double matrix[3][3]{
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	double d = determinant(matrix);
	int a[10] { 1,2,3,4,5,6,7,8,9,0 };
	int size = sizeof(a) / sizeof(int);
	int x = 10;
	int y = 20;
	swap(x, y);
	int m = Max(a, size);
	cout << IsLeapYear(x+400+y);
	cout << "x=" << x << " y=" << y << endl;
}
