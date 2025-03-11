#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<int> list1{ 1,2,3,4,5,6,7,8,9 };
    list<int> list2{ 1,2,3,4,5,6,7,8,9 };
    cout << (list1 == list2) << endl;
    vector<int> n{ 10,20,30,40,50 };
    list1.push_back(100);
    list1.push_front(100);
    cout << list1.size() << endl;
    auto iter = ++(++(++list1.begin()));
    iter = list1.insert(iter, 300);
    iter = list1.insert(iter,10, 400);
    iter = list1.insert(iter, n.begin()+1, n.end());
    list1.pop_back();
    list1.pop_front();
    list1.clear();

}
