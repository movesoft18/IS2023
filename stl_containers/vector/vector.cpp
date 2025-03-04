#include <iostream>
#include <vector>
using namespace std;

struct product
{
	int id;
	string name;
	float price;
	float count;
};

int main()
{
	vector<product> products
	{
		{1, "Яблоки", 120, 34},
		{2, "Бананы", 100, 334},
		{3, "Груши", 250, 340},
		{4, "Апельсины", 130, 256},
	};

	std::vector<int> v1; // пустой вектор
	std::vector<int> v2(v1); // вектор v2 - копия вектора v1
	std::vector<int> v3 = v1; // вектор v3 - копия вектора v1
	std::vector<int> v4(5); // вектор v4 состоит из 5 чисел, каждое число равно 0
	std::vector<int> v5(5, 2); // вектор v5 состоит из 5 чисел, каждое число равно 2
	std::vector<int> v6{ 1, 2, 4, 5 }; // вектор v6 состоит из чисел 1, 2, 4, 5
	std::vector<int> v7 = { 1, 2, 3, 5 }; // вектор v7 состоит из чисел 1, 2, 4, 5

	std::vector<int> v8(5); // вектор состоит из 5 чисел, каждое число в векторе равно 0
	std::vector<int> v9{ 5 }; // вектор состоит из одного числа, которое равно 5
	std::vector<int> v10(5, 2); // вектор состоит из 5 чисел, каждое число равно 2
	std::vector<int> v11{ 5, 2 }; // вектор состоит из двух чисел 5 и 2

	std::vector<double> v{ 5 };



	vector<int> numbers{ 1,2,3,4,5,6,7,8,9 };

	int first = numbers.front(); // 1
	int last = numbers.back(); // 5
	int second = numbers[1]; // 2
	std::cout << "first: " << first << std::endl;
	std::cout << "second: " << second << std::endl;
	std::cout << "last: " << last << std::endl;
	cout << numbers.size() << endl;
	numbers[0] = 6; // изменяем значение
	for (int n : numbers)
		cout << n << "\t";
	cout << endl;
	for(int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << "\t";
	cout << endl;

	for (vector<int>::iterator iter = numbers.begin();
		iter != numbers.end(); ++iter)
	{
		cout << *iter << "\t";
	}
	cout << endl;
	for (vector<int>::reverse_iterator iter = numbers.rbegin();
		iter != numbers.rend(); ++iter)
	{
		cout << *iter << "\t";
	}
	cout << endl;
	for (auto iter = numbers.begin();iter != numbers.end(); iter++)
	{
		cout << *iter << "\t";
	}
	cout << endl;
	cout << numbers.at(8) << endl;
	cout << numbers[8] << endl;
	try
	{
		int n = numbers.at(10);
	}
	catch (std::out_of_range e)
	{
		std::cout << "Incorrect index" << std::endl;
	}
}
/*

Обращение к элементам и их перебор
Для обращения к элементам вектора можно использовать разные способы :
[index] : получение элемента по индексу(также как и в массивах), индексация начинается с нуля
at(index) : функция возвращает элемент по индексу
front() : возвращает первый элемент
back() : возвращает последний элемент
*/
