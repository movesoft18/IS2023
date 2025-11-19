// LambdaInCpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
using namespace std;

class SomeLambda
{
public:
    bool operator () (int x) const
    {
        return x == 7;
    }
};

class SomeLambdaWithCapture
{
    const int value;
public:
    SomeLambdaWithCapture(int value) : value(value) {}
    bool operator () (int x) const
    {
        return x == value;
    }
};

class SomeLambdaWithMutable
{
    int sum;
public:
    SomeLambdaWithMutable(int value) : sum(value) {}
    bool operator () (int x)
    {
        for (int i = 0; i < 10; i++)
            sum += i;
    }
};

class SomeLambdaWithCap
{
    int& sum;
public:
    SomeLambdaWithCap(int& value) : sum(value) {}
    bool operator () (int x)
    {
        for (int i = 0; i < 10; i++)
            sum += i;
    }
};

class Exam8
{
    const int a, b, c;
    char& d, & e;
public:
    Exam8(int a, int b, int c, char& d, char& e) :a(a), b(b), c(c), d(d), e(e) {}
    auto operator () () const
    {
        ++e;
        return a + b + c + d + e;
    }
};

void Example1()
{
    SomeLambda lambda;
    int a[10]{ 1,2,3,4,5,6,7,5,4,8 };
    auto index = find_if(a, a + 10, [](int x) {return x == 7; });
    index = find_if(a, a + 10, lambda);
    auto index1 = find(a, a + 10, 5);
    int intindex = index - a;
    if (index != end(a))
        cout << *index << endl;
}
void Example2()
{
    int a[10]{ 2,4,6,8,12,60,70,50,40,80 };

    auto condition = all_of(a, a + 10, [](int x) {return x % 2 == 0; });
    cout << condition << endl;
}

void Example3()
{
    int a[10]{ 2,2,2,2,2,2,2,2,2,2 };
    int value = 2;
    auto condition = all_of(a, a + 10, [value](int x) {return x == value; });
    cout << condition << endl;
}

void Example4()
{
    int a[10]{ 2,2,2,2,2,2,2,2,2,2 };
    int value = 3;
    SomeLambdaWithCapture lambda(value);
    auto condition = all_of(a, a + 10, lambda);
    cout << condition << endl;
}

void Example5()
{
    int sum = 0;
    auto lambda = [sum]() mutable
    {
        for (int i = 0; i < 10; i++)
            sum += i;
    };
    lambda();
    cout << sum << endl;
}

void Example6()
{
    int sum = 0;
    auto lambda = [&sum]()
    {
        for (int i = 0; i < 10; i++)
            sum += i;
    };
    lambda();
    cout << sum << endl;
}

void Example7()
{
    int a = 0, b = 1, c = 2;
    char d = 3, e = 4;
    auto lambda = [=]()
    {
        return a + b + c + d + e;
    };
    
    cout << lambda() << endl;
}

void Example8()
{
    int a = 0, b = 1, c = 2;
    char d = 3, e = 4;
    auto lambda = [=, &d, &e](){
        e++;
        return a + b + c + d + e;
    };

    cout << lambda() << ' ' << (int)e << endl;
    cout << int(e) << endl;
    e--;
    Exam8 l(a, b, c, d, e);
    cout << l() << ' ';
    cout << (int)e << endl;
}

class SomeClass
{
    int a, b;
    int arr[10]{ 0 };
public:
    SomeClass(int a, int b) : a(a), b(b) {}
    void operator ()()
    {
        generate(arr, arr + 10, [this]() {
            return rand() % (b - a) + a;
            });
    }

    /*void printItem(int a)
    {
        cout << a << endl;
    }*/

    void Print()
    {
        //for (int i = 0; i < 10; i++) cout << a << endl;
        for_each(arr, arr + 10, [](int a) {cout << a << endl; });
        //for_each(arr, arr + 10, printItem);
    }
};

void Example9()
{
    SomeClass sc(5, 10);
    sc();
    sc.Print();
}

void Example10()
{
    auto l = [](int i, double j) -> int {return i + j; };
    l(2, 2.1);
}

int main()
{
    Example1();
    Example2();
    Example3();
    Example4();
    Example5();
    Example6();
    Example7();
    Example8();
    Example9();
    Example10();
}
