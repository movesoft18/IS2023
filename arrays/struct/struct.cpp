#include <iostream>
using namespace std;

struct Student
{
	int id;
	string family;
	string name;
	string middleName;
	char gender;
	int age;
	string speciality;
	int course;
};

int main()
{
	Student s1;
	Student s2{2, "Иванов","Иван","Иванович", 'М', 19, "ИСиП", 3 };
	Student students[2000];
	s1.id = 1;
	s1.family = "Петров";
	s1.middleName = "Петрович";
	s1.name = "Петр";
	s1.gender = 'М';
	s1.age = 18;
	s1.speciality = "ИСиП";
	s1.course = 2;
}

