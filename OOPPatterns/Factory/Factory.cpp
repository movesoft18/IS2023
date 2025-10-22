#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Warrior
{
public:
    virtual void info() = 0;
    virtual ~Warrior() {}
};

class Infantryman : public Warrior
{
public:
    void info() { cout << "Infantryman" << endl; }
};

class Archer : public Warrior
{
public:
    void info() { cout << "Archer" << endl; }
};

class Horseman : public Warrior
{
public:
    void info() { cout << "Horseman" << endl; }
};

// Самый простой вариант - фабричная функция
enum Warrior_ID { Infantryman_ID = 0, Archer_ID, Horseman_ID };

Warrior* сreateWarrior(Warrior_ID id)
{
    Warrior* p;
    switch (id)
    {
    case Infantryman_ID:
        p = new Infantryman();
        break;
    case Archer_ID:
        p = new Archer();
        break;
    case Horseman_ID:
        p = new Horseman();
        break;
    default:
        assert(false);
    }
    return p;
}


//Классическая реализация паттерна Factory Method
// Фабрики объектов
class Factory
{
public:
    virtual Warrior* createWarrior() = 0;
    virtual ~Factory() {}
};

class InfantryFactory : public Factory
{
public:
    Warrior* createWarrior() override {
        return new Infantryman;
    }
};

class ArchersFactory : public Factory
{
public:
    Warrior* createWarrior() override{
        return new Archer;
    }
};

class CavalryFactory : public Factory
{
public:
    Warrior* createWarrior() override{
        return new Horseman;
    }
};


class Factory1
{
public:
    virtual Warrior* createWarrior(Warrior_ID id) = 0;
    virtual ~Factory1() {}
};


class FactoryBase : public Factory1
{
public:
    virtual Warrior* createWarrior(Warrior_ID id);
    virtual ~FactoryBase() {}
};

Warrior* FactoryBase::createWarrior(Warrior_ID id)
{
    Warrior* p;
    switch (id)
    {
    case Infantryman_ID:
        p = new Infantryman();
        break;
    case Archer_ID:
        p = new Archer();
        break;
    case Horseman_ID:
        p = new Horseman();
        break;
    default:
        assert(false);
    }
    return p;
}


int main()
{
    Warrior* w1 = сreateWarrior(Infantryman_ID);

    InfantryFactory* infantry_factory = new InfantryFactory;
    ArchersFactory* archers_factory = new ArchersFactory;
    CavalryFactory* cavalry_factory = new CavalryFactory;

    vector<Warrior*> v;
    v.push_back(infantry_factory->createWarrior());
    v.push_back(archers_factory->createWarrior());
    v.push_back(cavalry_factory->createWarrior());


    auto universalFactory = new FactoryBase();
    v.push_back(universalFactory->createWarrior(Infantryman_ID));

    for (int i = 0; i < v.size(); i++)
        v[i]->info();
    // ...


}

