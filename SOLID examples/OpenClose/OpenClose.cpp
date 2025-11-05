
#include <iostream>
#include <vector>
using namespace std;

class Cook
{
public:
    string Name;
    Cook(string name)
    {
        this->Name = name;
    }

    void MakeDinner()
    {
        cout << "Чистим картошку\n";
        cout << "Ставим почищенную картошку на огонь\n";
        cout << "Сливаем остатки воды, разминаем варенный картофель в пюре\n";
        cout << "Посыпаем пюре специями и зеленью\n";
        cout << "Картофельное пюре готово\n";
    }
};

class IMeal
{
public:
    virtual void Make() = 0;
};

class PotatoMeal : public IMeal
{
public:
    void Make() override
    {
        cout << "Чистим картошку\n";
        cout << "Ставим почищенную картошку на огонь\n";
        cout << "Сливаем остатки воды, разминаем варенный картофель в пюре\n";
        cout << "Посыпаем пюре специями и зеленью\n";
        cout << "Картофельное пюре готово\n";
    }
};
class SaladMeal : public IMeal
{
public:
    void Make() override
    {
        cout << "Нарезаем помидоры и огурцы\n";
        cout << "Посыпаем зеленью, солью и специями\n";
        cout << "Поливаем подсолнечным маслом\n";
        cout << "Салат готов\n";
    }
};


class PizzaMeal : public IMeal
{
public:
    void Make() override
    {
        cout << "Раскатываем тесто\n";
        cout << "Ложим колбасу, огурцы, грибы\n";
        cout << "Поливаем майонезом и соусом\n";
        cout << "Ставим в печь\n";
        cout << "Пицца готова\n";
    }
};

class Cook
{
public:
    string Name;

    Cook(string name)
    {
        Name = name;
    }

    void MakeDinner(IMeal* meal)
    {
        meal->Make();
        delete meal;
    }
};


class MealBase
{
public:
    void Make()
    {
        Prepare();
        Cook();
        FinalSteps();
    }
    virtual void Prepare() = 0;
    virtual void Cook() = 0;
    virtual void FinalSteps() = 0;
};

class PotatoMeal : public MealBase
{
    void Cook() override
    {
        cout << "Ставим почищенную картошку на огонь\n";
        cout << "Варим около 30 минут\n";
        cout << "Сливаем остатки воды, разминаем варенный картофель в пюре\n";
    }

    void FinalSteps() override
    {
        cout << "Посыпаем пюре специями и зеленью\n";
        cout << "Картофельное пюре готово\n";
    }

    void Prepare() override
    {
        cout << "Чистим и моем картошку\n";
    }
};

class SaladMeal : public MealBase
{
    void Cook() override
    {
        cout << "Нарезаем помидоры и огурцы\n";
        cout << "Посыпаем зеленью, солью и специями\n";
    }

    void FinalSteps() override
    {
        cout << "Поливаем подсолнечным маслом\n";
        cout << "Салат готов\n";
    }

    void Prepare() override
    {
        cout << "Моем помидоры и огурцы\n";
    }
};

class Cook
{
public:
    string Name;

    Cook(string name)
    {
        Name = name;
    }

    void MakeDinner(vector<MealBase*> menu)
    {
        for (MealBase* meal : menu)
            meal->Make();
    }
};


int main()
{
    vector<MealBase*> menu { new PotatoMeal(), new SaladMeal() };

    Cook cook("Bob");
    bob.MakeDinner(menu);
}

int main()
{
    Cook cook("Bob");
    cook.MakeDinner(new PotatoMeal());
    cook.MakeDinner(new SaladMeal());
    cook.MakeDinner(new PizzaMeal());
}


int main()
{
    Cook cook("Bob");
    cook.MakeDinner();
}
