#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <forward_list>
using namespace std;


int main()
{
	vector<int> numbers{ 1,2,3,4,5,6,7,8,9 };
	list<int> numbers1{ 1,2,3,4,5,6,7,8,9 };
	forward_list<int> numbers3{ 1,2,3,4,5,6,7,8,9 };
	const array<int,9> numbers2{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int n : numbers)
		cout << n << "\t";
	cout << endl;
	for (int n : numbers1)
		cout << n << "\t";
	cout << endl;
	for (int n : numbers2)
		cout << n << "\t";
	cout << endl;
	for (int n : numbers3)
		cout << n << "\t";
	cout << endl;
	for (vector<int>::iterator iter = numbers.begin();
		iter != numbers.end(); ++iter)
	{
		cout << *iter << "\t";
	}
	cout << endl;
	for (list<int>::reverse_iterator iter = numbers1.rbegin();
		iter != numbers1.rend(); ++iter)
	{
		cout << *iter << "\t";
	}
	cout << endl;

	for (array<int,9>::const_iterator iter = numbers2.cbegin();
		iter != numbers2.cend(); ++iter)
	{
		cout << *iter << "\t";
	}
	cout << endl;
}
