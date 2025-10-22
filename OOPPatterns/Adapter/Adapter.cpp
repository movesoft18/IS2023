#include <iostream>
using namespace std;

// Уже существующий класс температурного датчика окружающей среды
class FahrenheitSensor
{
public:
    // Получить показания температуры в градусах Фаренгейта
    float getFahrenheitTemp() {
        float t = 32.0;
        // ... какой то код
        return t;
    }
};

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual float getTemperature() = 0;
};

class Adapter : public Sensor
{
public:
    Adapter(FahrenheitSensor* p) : p_fsensor(p) {
    }
    ~Adapter() {
        delete p_fsensor;
    }
    float getTemperature() {
        return (p_fsensor->getFahrenheitTemp() - 32.0) * 5.0 / 9.0;
    }
private:
    FahrenheitSensor* p_fsensor;
};


class FahrenheitSensor1
{
public:
    float getFahrenheitTemp() {
        float t = 32.0;
        // ...
        return t;
    }
protected:
    void adjust() {} // Настройка датчика (защищенный метод)
};

class Sensor1
{
public:
    virtual ~Sensor1() {}
    virtual float getTemperature() = 0;
    virtual void adjust() = 0;
};

class Adapter1 : public Sensor1, private FahrenheitSensor1
{
public:
    Adapter1() { }
    float getTemperature() {
        return (getFahrenheitTemp() - 32.0) * 5.0 / 9.0;
    }
    void adjust() {
        FahrenheitSensor1::adjust();
    }
};

int main()
{
    Sensor* p = new Adapter(new FahrenheitSensor);
    cout << "Celsius temperature = " << p->getTemperature() << endl;
    delete p;

    Sensor1* p1 = new Adapter1();
    p1->adjust();
    cout << "Celsius temperature = " << p1->getTemperature() << endl;
    delete p1;
}