// RecSum.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int RecSum(int a[], int size)
{
	/*
	if (a == nullptr) return 0;
	int result = 0;
	for (int i = 0; i < size; i++)
		result += a[i];
	return result;*/
	if (size <= 0 || a == nullptr) return 0;
	if (size == 1) 
		return a[0];
	return RecSum(a, size - 1) + a[size-1];
}

int main()
{
	int a[]{ 5,13,88,22,6,1,1,2,3,4,5,6,7,8,9,9,0,1,2,3,4,5,56 };
	int s = RecSum(a, sizeof(a)/sizeof(int));
	cout << s << endl;
}

