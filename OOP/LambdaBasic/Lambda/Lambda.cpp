#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

bool greater1(int a, int b)
{
    return a < b;
}

void foo()
{
    cout << "foo";
}


void BubbleSort(int* a, int count, bool (*predicate)(int, int))
{
    int i = 0;
    // ....
    if (predicate(a[i], a[i + i]))
    {
        // ...
    }
    // ....
}

void BubbleSort1(int* a, int count, 
    std::function<bool(int, int)> predicate)
{
    int i = 0;
    // ....
    if (predicate(a[i], a[i + i]))
    {
        // ...
    }
    // ....
}

int main()
{
    int a[10]{ 1,2,3,4,5,6,7,8,9,0 };
    BubbleSort(a, 10, greater1);
    BubbleSort1(a, 10, greater1);
    BubbleSort(a, 10, [](int a, int b) {return a > b; });

    bool (*comparer)(int, int ) = &greater1;
    //bool (*comparer1)(int, int) = &foo; // неправильно !!
    void (*fooptr)() = &foo;

    std::function<bool(int, int)> myComparer = &greater1;
    std::function<void()> myFoo = &foo;

    bool res = comparer(10, 29);
    vector<int> v{ 9,7,5,3,5,6,7,4,4 };
    std::sort(v.begin(), v.end(), comparer);
    sort(v.begin(), v.end(), [](auto a, auto b)
        {
            return a < b;
        }
    );
    for (auto e : v)
        cout << e << ' ';
    cout << endl;
    auto result = std::find_if(v.begin(), v.end(), [](auto a) {
        return a == 7;
        });
    if (result != v.end())
    {
        cout << *result << " index= " << result - v.begin() << endl;
    }
    else
        cout << "not found\n";
}


