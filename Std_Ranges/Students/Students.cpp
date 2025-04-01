#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

int id = 0;

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


bool selectStudent(const Student& s) { return s.specId == id ; }
bool OlderThen17(const Student& s) { return s.age > 17; }
bool selectACS(const Speciality & s) { return s.name == "Прикладная информатика"; }
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
        Speciality {4, "Прикладная информатика"},
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

    auto acsList = spec
        | views::filter(selectACS)
        | views::take(1)
        ;
    //int id = 0;
   /* vector<Speciality> spec1;
    ranges::copy(acsList, std::back_inserter(spec1));
    id = spec1[0].id;*/
    for (const auto& s : acsList) id = s.id;

    auto olderThet17_2 = students
        | views::filter(selectStudent)
   //     | views::drop(2)
   //     | views::transform(IdAndName);
    ;
    print(olderThet17_2);
/*
    for (const auto& p : olderThet17_2)
    {
        cout << "Ид: " << p.id << " ФИО:" << p.name << endl;
    }
    */
}

