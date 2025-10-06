#include <iostream>
#include <string>
using namespace std;

class Animal abstract
{
protected:
    string name;
    double weight;
    bool isPredator;
public:
    Animal(string n, double w, bool p) : name(n), weight(w), isPredator(p) {}
    Animal() : Animal("Безымянный", 0, false) {}

    void Info()
    {
        cout << "Имя: " << name << " Вес: " << weight << "кг. Хищник: " << (isPredator ? "Да" : "Нет") << endl;
    }

    virtual void Say() = 0;
    //virtual void Say() abstract;

};

void Animal::Say()
{
    cout << "Мяу" << endl;
}

class Cat : public Animal
{
public:
    Cat(double weight) : Animal("Кошка", weight, true) {}
    void Say() override
    {
        //cout << "Мяу!" << endl;
        Animal::Say();
    }
};


class Dog : public Animal
{
public:
    Dog(double weight) : Animal("Собака", weight, true) {}
    void Say() override
    {
        cout << "Гав!" << endl;
    }

};


class Cow : public Animal
{
public:
    Cow(double weight) : Animal("Корова", weight, true) {}
    void Say() override
    {
        cout << "Му-у!" << endl;
    }
};
class Tiger : public Cat
{
public:
    Tiger(double weight) : Cat(weight)
    {
        name = "Тигр";
    }

    void Say() override
    {
        cout << "Рррр-ааа-рр!" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "");
    Animal* animals[5];
    //animals[4] = new Animal();
    animals[0] = new Cat(3); // заметьте – создаем кошку, а результат помещаем в указатель на базовый класс Animal (Upcast по умолчанию)
    animals[1] = new Cow(300); // заметьте – создаем корову, а результат помещаем в указатель на базовый класс Animal (Upcast по умолчанию)
    animals[2] = new Dog(30); // заметьте – создаем собаку, а результат помещаем в указатель на базовый класс Animal (Upcast по умолчанию)
    animals[3] = new Tiger(150); // заметьте – создаем тигра, а результат помещаем в указатель на базовый класс Animal (Upcast по умолчанию)
    for (int i = 0; i < 4; i++)
    {
        animals[i]->Info();
        animals[i]->Say(); // благодаря полиморфизму каждое животное разговаривает по-своему,
        //не смотря на то, что мы пользуемся только базовым классом
    }
    for (int i = 0; i < 4; i++)
    {
        delete animals[i];
    }
}