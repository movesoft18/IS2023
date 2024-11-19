#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, s;
	cout << "Программа суммирования двух чисел" << endl;
	cout << "Введите 1-е число:";
	cin >> a;
	cout << "Введите 2-е число:";
	cin >> b;
	s = a + b;
	cout << "Сумма = " << s << endl;
}