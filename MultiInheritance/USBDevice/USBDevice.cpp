#include <iostream>

class USBDevice
{
private:
    long m_id;

public:
    USBDevice(long id)
        : m_id(id)
    {
    }

    long getID() { return m_id; }
};

class NetworkDevice
{
private:
    long m_id;

public:
    NetworkDevice(long id)
        : m_id(id)
    {
    }

    long getID() { return m_id; }
};

class WirelessAdapter : public USBDevice, public NetworkDevice
{
public:
    WirelessAdapter(long usbId, long networkId)
        : USBDevice(usbId), NetworkDevice(networkId)
    {
    }
};

int main()
{
    WirelessAdapter c54G(5442, 181742);
    std::cout << c54G.getID(); // какую getID() мы вызываем?

    return 0;
}

//Когда c54G.getID() компилируется, компилятор проверяет, содержит ли WirelessAdapter функцию с именем getID().Ее у него нет.Затем компилятор проверяет, есть ли в каком - либо из родительских классов функция с именем getID().Видите здесь проблему ? Проблема в том, что c54G на самом деле содержит ДВЕ функции getID() : одна унаследована от USBDevice, а другая – от NetworkDevice.Следовательно, этот вызов функции неоднозначен, и вы получите ошибку компиляции, если попытаетесь скомпилировать этот код.

//Однако есть способ обойти эту проблему : вы можете явно указать, какую версию вы хотели вызвать :

int main()
{
    WirelessAdapter c54G(5442, 181742);
    std::cout << c54G.USBDevice::getID();

    return 0;
}