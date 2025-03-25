// Ranges.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

struct Person
{
    int id;
    string name;
    int age;
};

bool ageMoreThen30(const Person& p){return p.age > 30;}

int main()
{
    vector<Person> person
    {
        Person{1, "Tom", 20},
        Person{2, "Kate", 31},
        Person{3, "Bob", 40},
    };

    //  вариант копирования
 /*   vector<Person> person31;

    for (auto& p : person)
    {
        if (p.age > 30)
            person31.push_back(p);
    }

    for (auto& p : person31)
        cout << p.id << ' ' << p.name << ' ' << p.age << endl;
 */
    auto view1 = person 
        | views::filter(ageMoreThen30);
    auto view2 = person
        | views::filter([](auto& p) {return p.age > 30; });
    for (const auto& v : view1)
    {
        cout << v.id << ' ' << v.name << ' ' << v.age << endl;
    }

}
