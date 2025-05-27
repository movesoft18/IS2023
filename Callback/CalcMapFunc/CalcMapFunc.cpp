// calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include <map>
#include <stack>
//#include <functional>
using namespace std;


stack<double> st;


//map<char, std::function<double(double, double)>> operations
//{
//	{'+', [](double a, double b) {return a + b; }},
//	{'-', [](double a, double b) {return a - b; }},
//	{'*', [](double a, double b) {return a * b; }},
//	{'/', [](double a, double b) {return a / b; }},
//};

map<char, double(*)(double, double)> operations
{
	{'+', [](double a, double b) {return a + b; }},
	{'-', [](double a, double b) {return a - b; }},
	{'*', [](double a, double b) {return a * b; }},
	{'/', [](double a, double b) {return a / b; }},
	{'^', [](double a, double b) {return pow(a, b); }},
	{'%', [](double a, double b) {return round(a / b); }},
};

double Compute(const char* str)
{
	char part[100];
	istringstream s(str);
	while (s >> part)
	{
		int len = strlen(part);
		if (len == 1)
		{
			char e = part[0];
			if (operations.count(e) > 0)
			{
				auto b = st.top();
				st.pop();
				auto a = st.top();
				st.pop();
				st.push(operations[e](a, b));
				continue;
			}
		}
		double num = atof(part);
		st.push(num);
	}
	auto res = st.top();
	st.pop();
	return res;
}

int main()
{
	cout << Compute("10 20 + 3 * 2 % 1 - 2 ^") << endl;
}
