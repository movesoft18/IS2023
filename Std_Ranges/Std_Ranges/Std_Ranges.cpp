#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    int specId;
    bool isMale;
};

struct StudentPart
{
    int id;
    string name;
};

struct Speciality
{
    int id;
    string name;
};

template <typename T>
void print(T& data)
{
    for (const auto& p : data)
    {
        cout << "Ид: " << p.id << " ФИО:" << p.name << " Возраст:" << p.age 
            << " Специальность: " << p.specId << " Мужской пол: " << p.isMale << endl;
    }
    cout << endl;
}

bool OlderThen17(const Student& s) { return s.age > 17; }
StudentPart IdAndName(const Student& s)
{
    return StudentPart{ s.id, s.name };
}

int main()
{
    vector<Speciality> spec
    {
        Speciality {1, "Прикладная информатика"},
        Speciality {2, "ИСиП"},
        Speciality {3, "РиЭНГМ"},
    };
    vector<Student> students
    {
        Student{1, "Иванов", 17, 2, true},
        Student{2, "Петров", 18, 1, true},
        Student{3, "Сидоров", 19, 1, true},
        Student{4, "Иванова", 20, 2, false},
        Student{5, "Петрова", 18, 3, false},
        Student{6, "Сидорова", 21, 3, false},
        Student{7, "Книгина", 20, 2, false},
    };
    setlocale(LC_CTYPE, "");
    vector<Student> olderThen17;

    for (auto& s : students)
        if (s.age > 17)
            olderThen17.push_back(s);
    print(olderThen17);
    vector<Student>olderThen17_3;
    for (int i = 0; i < olderThen17.size() && i < 3; i++)
    {
        olderThen17_3.push_back(olderThen17[i]);
    }

    auto olderThet17_2 = students
        | views::filter(OlderThen17)
        | views::drop(2)
        | views::transform(IdAndName);
    ;

    for (const auto& p : olderThet17_2)
    {
        cout << "Ид: " << p.id << " ФИО:" << p.name << endl;
    }
}

