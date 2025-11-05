#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Rectangle
{
    int _width;
    int _height;
public:
    virtual int GetWidth() { return _width; }
    virtual int GetHeight() { return _height;}
    virtual void SetWidth(int width) { _width = width; }
    virtual void SetHeight(int heigth) { _height = heigth; }
    int GetArea()
    {
        return _width * _height;
    }
};

class Square : public Rectangle
{
public:
    void SetWidth(int width) override
    {
        Rectangle::SetWidth(width);
        Rectangle::SetHeight(width);
    }
    void SetHeight(int height) override
    {
        Rectangle::SetHeight(height);
        Rectangle::SetWidth(height);
    }
};

//void TestRectangleArea(Rectangle* rect)
//{
//    rect->SetHeight(5);
//    rect->SetWidth(10);
//    string name = typeid(*rect).name();
//    if (name == "class Square")
//    {
//        if (rect->GetArea() != 100)
//            throw runtime_error("Некорректная площадь!");
//    } else if (rect->GetArea() != 50)
//        throw runtime_error("Некорректная площадь!");
//}

void TestRectangleArea(Rectangle* rect)
{
    rect->SetHeight(5);
    rect->SetWidth(10);
    if (rect->GetArea() != 50)
        throw runtime_error("Некорректная площадь!");
}

/*class Account
{
public:
    int Capital;

    virtual void SetCapital(int money)
    {
        if (money < 0)
            throw runtime_error("Нельзя положить на счет меньше 0");
        this->Capital = money;
    }
};

class MicroAccount : public Account
{
public:
    void SetCapital(int money) override
    {
        if (money < 0)
            throw runtime_error("Нельзя положить на счет меньше 0");

        if (money > 100)
            throw runtime_error("Нельзя положить на счет больше 100");

        this->Capital = money;
    }
};

float GetMedium(vector<float> numbers)
{
    if (numbers.size() == 0)
        throw runtime_error("длина массива равна нулю");
    float sum = 0;
    for (auto n : numbers)
        sum += n;
    float result = sum / numbers.size();
    
    if (result < 0)
        throw runtime_error("Результат меньше нуля");
    return result;
}

class Account
{
public:
    virtual float GetInterest(float sum, int month, int rate)
    {
        // предусловие
        if (sum < 0 || month >12 || month < 1 || rate < 0)
            throw runtime_error("Некорректные данные");

        float result = sum;
        for (int i = 0; i < month; i++)
            result += result * rate / 100;

        // постусловие
        if (sum >= 1000)
            result += 100; // добавляем бонус

        return result;
    }
};

class MicroAccount : public Account
{
public:
    float GetInterest(float sum, int month, int rate)override
    {
        if (sum < 0 || month > 12 || month < 1 || rate < 0)
            throw runtime_error("Некорректные данные");

        float result = sum;
        for (int i = 0; i < month; i++)
            result += result * rate / 100;

        return result;
    }
};

class User
{
protected:
    int age;
public:
    User(int age)
    {
        if (age < 0)
            throw runtime_error("возраст меньше нуля");

        this->age = age;
    }

    int GetAge() { return age; }
    void SetAge(int age)
    {
        if (age < 0)
            throw runtime_error("возраст меньше нуля");
        this->age = age;
    }
};

class Account
{
protected:
    int capital;
public:
    Account(int sum)
    {
        if (sum < 100)
            throw runtime_error("Некорректная сумма");
        this->capital = sum;
    }

    virtual int GetCapital() { return capital; }
    virtual void SetCapital(int capital)
    {
        if (capital < 100)
            throw runtime_error("Некорректная сумма");
        this->capital = capital;
    }
};

class MicroAccount : public Account
{
public:
    MicroAccount(int sum) : Account(sum)
    {
    }

    int GetCapital() override { return capital; }
    void SetCapital(int capital) override
    {
        this->capital = capital;
    }
};

void InitializeAccount(Account* account)
{
    account->SetCapital(200);
    cout << account->Capital;
}

void CalculateInterest(Account* account)
{
    float sum = account->GetInterest(1000, 1, 10); // 1000 + 1000 * 10 / 100 + 100 (бонус)
    if (sum != 1200) // ожидаем 1200
    {
        throw runtime_error("Неожиданная сумма при вычислениях");
    }
}

int main()
{
    Account* acc = new MicroAccount();
    CalculateInterest(acc); // получаем 1100 без бонуса 100
    delete acc;
}
*/
int main()
{
    Square rect;
    TestRectangleArea(&rect);
}