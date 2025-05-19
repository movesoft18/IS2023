#include <iostream>

using namespace std;

void Print(int* a, int count)
{
	for (int i = 0; i < count; i++)
		cout << a[i] << endl;
	cout << endl;
}

void Inc(int* a, int count)
{
	for (int i = 0; i < count; i++)
		a[i]++;
}

void Sqr(int* a, int count)
{
	for (int i = 0; i < count; i++)
		a[i] *= a[i];
}

void Div2(int* a, int count)
{
	for (int i = 0; i < count; i++)
		a[i] /= 2;
}

int CallbackPrint(int a)
{
	cout << a << endl;
	return a;
}


int CallbackSqr(int a)
{
	return a * a;
}

int CallbackInc(int a)
{
	return a+1;
}

int CallbackDiv2(int a)
{
	return a / 2;
}


void MyFunc(int* a, int count, int (*MyCallbackFunction)(int x))
{
	for (int i = 0; i < count; i++)
		a[i] = MyCallbackFunction(a[i]);
}

int arr[10] = {1,2,3,4,5,6,7,8,9,10};

int main()
{
	auto printHello = []() {cout << "Привет, я рад вас видеть!\n"; };
	printHello();
	MyFunc(arr, 10, [](int x) {
		if (x % 2) cout << x << endl;
		else cout << "\t" << x << endl;
		return x;
		});

	int x = 10;

	MyFunc(arr, 10, [](int a) {return a * a; });
	MyFunc(arr, 10, CallbackPrint);
	MyFunc(arr, 10, CallbackInc);
	MyFunc(arr, 10, CallbackPrint);
	MyFunc(arr, 10, CallbackSqr);
	MyFunc(arr, 10, CallbackPrint);
	MyFunc(arr, 10, CallbackDiv2);
	MyFunc(arr, 10, CallbackPrint);
	MyFunc(arr, 10, [](int x) { return x * x * x; });
	MyFunc(arr, 10, CallbackPrint);

	auto calc = [&x](int a) mutable -> int
	{
		x++;
		return x * a; 
	};
	auto b = calc(10);
	cout << b << " " << x << endl;
	cin.get();
}





