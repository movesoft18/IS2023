#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
    vector<int> numbers{ 1,2,3,4,5,6,7,8,9 };
    numbers.push_back(100);
    auto iter = numbers.begin();
    numbers.insert(iter, 200);
    int size = numbers.size();
    vector<int> n = numbers;
    iter = numbers.begin() + 5;
    numbers.insert(iter, 300);
    iter = numbers.begin() + 2;
    numbers.insert(iter, n.begin() + 3, n.end() - 2);
    n.clear();
    numbers.pop_back();
    iter = numbers.end() - 2;
    numbers.erase(iter);
    numbers.erase(numbers.begin() + 2, numbers.end()-2);
    numbers.resize(2);
    numbers.reserve(100);
    vector<int> n1{ 200, 1 };
    vector<int> n2{ 1, 1 };
    cout << (n1 == n2) << endl;
    cout << (n1 != n2) << endl;
    cout << (numbers == n1) << endl;
    n1.swap(n2);
    array<int, 10> items{ 1,2,3,4,5,6,7,8,9,0 };
}

