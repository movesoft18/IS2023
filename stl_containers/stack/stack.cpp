#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	if (s.empty())
	{
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
	}
	//auto iter = s.begin(); // Так не работатет
	/*
	for (auto e : s)		// Так не работатет
	{
		cout << e << endl;
	}
	*/
	while (!s.empty())
	{
		int value = s.top();
		s.pop();
		cout << value << endl;
	}
}

