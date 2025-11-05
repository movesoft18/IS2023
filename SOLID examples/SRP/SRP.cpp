
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
// Example 1 ---------------------
class Report
{
public:
    string _text;
    void GoToFirstPage()
    {
        cout << "Переход к первой странице\n";
    }

    void GoToLastPage()
    {
        cout << "Переход к последней странице\n";

    }

    void GoToPage(int pageNumber)
    {
        cout << "Переход к странице" << pageNumber << endl;
    }


    void Print()
    {
        cout << "Печать отчета\n";
        cout << _text << endl;
    }
};

// Example2 -------------------------
class Report
{
public:
    string _text;
    void GoToFirstPage()
    {
        cout << "Переход к первой странице\n";
    }

    void GoToLastPage()
    {
        cout << "Переход к последней странице\n";

    }

    void GoToPage(int pageNumber)
    {
        cout << "Переход к странице" << pageNumber << endl;
    }
};
//  обязанность - печать отчета
class Printer
{
    void PrintReport(Report report)
    {
        cout << "Печать отчета\n";
        cout << report._text << endl;
    }
};
// example 3 -------------------------
class Phone
{
public:
    string _model;
    int _price;
    Phone(string model, int price)
    {
        _model = model;
        _price = price;
    }
};

class MobileStore
{
public:
    vector<Phone> phones;
    void Process()
    {
        // ввод данных
        cout << "Введите модель:";
        string model;
        cin >> model;
        cout << "Введите цену:";
        int price;
        cin >> price;
        // валидация

        if (price <= 0 || model.empty())
        {
            throw runtime_error("Некорректно введены данные");
        }
        else
        {
            phones.push_back(Phone(model, price));
            // сохраняем данные в файл
            ofstream f("store.txt");
            f << model << " " << price << endl;
            f.close();
            cout << "Данные успешно обработаны\n";
        }
    }
};


class Phone
{
public:
    string _model;
    int _price;
    Phone(string model, int price)
    {
        _model = model;
        _price = price;
    }
};

class IPhoneBinder
{
public:
    virtual Phone CreatePhone(pair<string, int> data) = 0;
};

class IPhoneSaver
{
public:
    virtual void Save(Phone phone, string fileName) = 0;
};

class IPhoneReader
{
public:
    virtual pair<string, int> GetInputData() = 0;
};

class IPhoneValidator
{
public:
    virtual bool IsValid(Phone phone) = 0;
};


class MobileStore
{
public:
    vector<Phone> phones;

    IPhoneReader* reader;
    IPhoneBinder* binder;
    IPhoneValidator* validator;
    IPhoneSaver* saver;

    MobileStore(IPhoneReader* reader, IPhoneBinder* binder, IPhoneValidator* validator, IPhoneSaver* saver)
    {
        this->reader = reader;
        this->binder = binder;
        this->validator = validator;
        this->saver = saver;
    }

    void Process()
    {
        pair<string, int> data = reader->GetInputData();
        Phone phone = binder->CreatePhone(data);
        if (validator->IsValid(phone))
        {
            phones.push_back(phone);
            saver->Save(phone, "store.txt");
            cout << "Данные успешно обработаны\n";
        }
        else
        {
            cout << "Некорректные данные\n";
        }
    }
    virtual ~MobileStore()
    {
        delete reader;
        delete binder;
        delete saver;
        delete validator;
    }
};


class ConsolePhoneReader : public IPhoneReader
{
public:
    pair<string, int> GetInputData() override
    {
        cout << "Введите модель:";
        string model;
        cin >> model;
        cout << "Введите цену:";
        int price;
        cin >> price;
        return pair<string, int>(model, price);
    }
};

class GeneralPhoneBinder : public IPhoneBinder
{
public:
    Phone CreatePhone(pair<string, int> data) override
    {
        if (data.first.size() > 0 && data.second >= 0)
        {
            return Phone(data.first, data.second);

        }
        throw runtime_error("Ошибка привязчика модели Phone. Некорректные данные");
    }
};


class GeneralPhoneValidator : public IPhoneValidator
{
public:
    bool IsValid(Phone phone) override
    {
        return (phone._model.size() > 0 && phone._price >= 0);
    }
};

class TextPhoneSaver : public IPhoneSaver
{
public:
    void Save(Phone phone, string fileName) override
    {
        ofstream f(fileName);
        f << phone._model << " " << phone._price << endl;
        f.close();
    }
};


int main()
{
    MobileStore* store = new MobileStore(
        new ConsolePhoneReader(), new GeneralPhoneBinder(),
        new GeneralPhoneValidator(), new TextPhoneSaver());
    store->Process();
    //....
    delete store;
}