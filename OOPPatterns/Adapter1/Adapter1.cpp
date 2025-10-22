#include <iostream>
using namespace std;

class ITransport
{
public:
    virtual void Drive() = 0;
};

// класс машины
class Auto : public ITransport
{
public:
    void Drive() override
    {
        cout << "Машина едет по дороге\n";
    }
};

class Driver
{
public:
    void Travel(ITransport* transport)
    {
        transport->Drive();
    }
};

// интерфейс животного
class IAnimal
{
public:
    virtual void Move() = 0;
};

// класс верблюда
class Camel : public IAnimal
{
public:
    void Move() override
    {
        cout << "Верблюд идет по пескам пустыни\n";
    }
};

// Адаптер от Camel к ITransport
class CamelToTransportAdapter : public ITransport
{
    Camel* camel;
public:
    CamelToTransportAdapter(Camel* c)
    {
        camel = c;
    }
    virtual ~CamelToTransportAdapter()
    {
        delete camel;
    }
    void Drive() override
    {
        camel->Move();
    }
};



int main()
{
    setlocale(LC_ALL, "");
    // путешественник
    Driver* driver = new Driver();
    // машина
    Auto* car = new Auto();
    // отправляемся в путешествие
    driver->Travel(car);
    // встретились пески, надо использовать верблюда
    Camel* camel = new Camel();
    // используем адаптер
    ITransport* camelTransport = new CamelToTransportAdapter(camel);
    // продолжаем путь по пескам пустыни
    driver->Travel(camelTransport);
    delete  car;
    delete driver;
    delete camelTransport;
}
