// VectorSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    int course;
};

void print(const vector<int>& n)
{
    for (auto i : n)
        cout << i << ' ';
    cout << "\n";
}

void print_stud(const vector<Student>& n)
{
    for (auto i : n)
        //cout << i.id << i.name << i.age << i.cource << ' ';
        printf("id=%d ФИО=%s, возраст=%d, курс=%d\n", i.id, i.name.c_str(), i.age, i.course);
    
}

void print_studl(const list<Student>& n)
{
    for (auto i : n)
        //cout << i.id << i.name << i.age << i.cource << ' ';
        printf("id=%d ФИО=%s, возраст=%d, курс=%d\n", i.id, i.name.c_str(), i.age, i.course);

}

bool compareStudents(const Student& a, const Student& b)
{
    return a.name < b.name;
}

bool predicate(int value)
{
    //return value > 5;
    return value % 2 == 0;
}
bool pred1(const Student& s)
{
    return s.course == 2;
}

int main()
{
    setlocale(LC_ALL, "");
    vector<int> numbers{3,65,4,2,-1,5,78,3,-5,6,4};
    print(numbers);
    sort(numbers.begin(), numbers.end());
    print(numbers);
    
    auto result = find(numbers.begin(), numbers.end(), -100);
    if (result != numbers.end())
    {
        cout << "Найдено под номером " << result - numbers.begin() << endl;
        //*result = 100;
    }
    else cout << "Число не найдено\n";
    print(numbers);

    result = find_if(numbers.begin(), numbers.end(), predicate);
    while (result != numbers.end())
    {
        cout << *result << endl;
        result = find_if(result+1, numbers.end(), predicate);
    }
    vector<Student> students
    {
        Student {1,"Рульков", 18,2},
        Student {3,"Петров", 19,3},
        Student {7,"Сидоров", 32,4},
        Student {2,"Иванов", 17,1},
    };
    print_stud(students);
    sort(students.begin(), students.end(), compareStudents);
    cout << endl;
    print_stud(students);

    list<Student> students1
    {
        Student {1,"Рульков", 18,2},
        Student {3,"Петров", 19,3},
        Student {7,"Сидоров", 32,4},
        Student {2,"Иванов", 17,2},
    };
    print_studl(students1);
    stable_sort(students1.begin(), students1.end(), compareStudents);
    cout << endl;
    print_studl(students1);

    //auto stud = find_if(students1.begin(), students1.end(), [](const Student& e) {return e.course == 2; });
    auto stud = find_if(students1.begin(), students1.end(), pred1);
    while (stud != students1.end())
    {
        cout << stud->name << endl;
        stud = find_if(++stud, students1.end(), pred1);
    }

    int a[10]{3,54,7,4,3,5,7,4,6,78};
    sort(std::begin(a), std::end(a));
}

