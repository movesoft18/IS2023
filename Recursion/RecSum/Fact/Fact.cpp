#include <iostream>
using namespace std;

double factorial(double n)
{
    if (n < 0) return 0;
    if (n <= 1) return 1;
    return factorial(n - 1) * n;
}

int main()
{
    std::cout << factorial(90) << endl;
}

