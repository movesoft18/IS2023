#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Observer
{
public:
    virtual void Update(string message) = 0;
    virtual ~Observer() {}
};

class Account // Subject
{
    vector<Observer*> _observers;
    double _sum;

public:
    void Register(Observer* obj)
    {
        _observers.push_back(obj);
    }
    void Unregister(Observer* obj)
    {
        for (auto o = _observers.begin(); o != _observers.end(); o++)
        {
            if (*o == obj)
            {
                _observers.erase(o);
                break;
            }
        }
    }
    Account(double sum = 0)
    {
        _sum = sum;
    }

    virtual ~Account()
    {
        if (_observers.size() > 0)
            _observers.clear();
    }
    double Sum() { return _sum; }

    void Notify(string message)
    {
        for (auto& o : _observers)
        {
            o->Update(message);
        }
    }

    void Put(double sum)
    {
        _sum += sum;
        Notify("Сумма " + to_string(sum) +
            " поступила на счет. Остаток на счете "
            + to_string(_sum) + "руб.\n");
    }

    void Withdraw(double sum)
    {
        if (sum <= _sum)
        {
            _sum -= sum;
            Notify("Сумма " + to_string(sum) + 
                " снята со счета. Остаток на счете " 
                + to_string(_sum) + "руб.\n");
        }
        else
        {
            Notify("Недостаточно денег на счете\n");
        }
    }
};


class SmsObserver : public Observer
{
    double _sum = 0;
    Account* subject;
public:
    SmsObserver(Account* account)
    {
        subject = account;
        subject->Register(this);
    }
    void Update(string message) override
    {
        cout << "Пришло смс - " << message;// код отправки смс на телефон
        _sum = subject->Sum();
    }
    ~SmsObserver() override
    {
        subject->Unregister(this);
    }
};

class PushObserver : public Observer
{
    double _sum = 0;
    Account* subject;
public:
    PushObserver(Account* account)
    {
        subject = account;
        subject->Register(this);
    }
    void Update(string message) override
    {
        cout << "Пришло push уведомление - " << message;
        _sum = subject->Sum();
    }
    ~PushObserver() override
    {
        subject->Unregister(this);
    }
};


int main()
{
    setlocale(LC_ALL, "");
    Account* account = new Account(100);
    
    SmsObserver smso(account);

    account->Put(100);
    account->Withdraw(150);
    
    PushObserver pusho(account);
    account->Withdraw(100);
    account->Put(200);
    account->Withdraw(50);
    cin.get();
}

