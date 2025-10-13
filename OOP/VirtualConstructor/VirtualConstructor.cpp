#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

enum WarriorId
{
    InfanrtumanId,
    ArcherId,
    HorsemanId,
};

class Warrior
{
    Warrior* p;
public:
    Warrior(): p(nullptr) {}
    Warrior(WarriorId id);
    virtual void info() { p->info(); }
    virtual int getHealth() { return p->getHealth(); }
    //.. Иные виртуальные функции, реализующие интерфейс взаимодействия с воином
    virtual ~Warrior() { delete p; p = nullptr; }
};

class Infantruman : public Warrior
{
    Infantruman(): Warrior() {}
    Infantruman(const Infantruman& other);
    Infantruman operator = (const Infantruman& other);
    friend class Warrior;
public:
    void info() override { cout << "Infantruman\n"; }
    int getHealth() override { return 100; }
};

class Archer : public Warrior
{
    Archer() : Warrior() {}
    Archer(const Archer& other);
    Archer operator = (const Archer& other);
    friend class Warrior;
public:
    void info() override { cout << "Archer\n"; }
    int getHealth() override { return 90; }
};

class Horseman : public Warrior
{
    Horseman() : Warrior() {}
    Horseman(const Horseman& other);
    Horseman operator = (const Horseman& other);
    friend class Warrior;
public:
    void info() override { cout << "Horseman\n"; }
    int getHealth() override { return 80; }
};

Warrior::Warrior(WarriorId id): p(nullptr)
{
    switch (id)
    {
    case InfanrtumanId:
        p = new Infantruman;
        break;
    case ArcherId:
        p = new Archer;
        break;
    case HorsemanId:
        p = new Horseman;
        break;
    default:
        assert(false);
    }
}

int main()
{
    vector<Warrior*> v;
    v.push_back(new Warrior(InfanrtumanId));
    v.push_back(new Warrior(ArcherId));
    v.push_back(new Warrior(HorsemanId));
    for (auto w : v)
    {
        w->info();
        cout << w->getHealth() << endl;
        cout << endl;
    }
    for (auto w : v)
        delete w;
}