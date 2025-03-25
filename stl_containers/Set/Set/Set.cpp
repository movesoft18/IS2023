#include <iostream>
#include <set>

using namespace std;

template<typename T>
void printSet(const set<T>& s)
{
    for (auto i : s)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    set<int> numbers{1,4,7,4};
    printSet(numbers);

    cout << numbers.size() << endl;
    cout << numbers.empty() << endl;
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(30);
    numbers.insert(10);
    printSet(numbers);
    numbers.erase(4);
    printSet(numbers);
    cout << (numbers.count(10)) << endl;
}
