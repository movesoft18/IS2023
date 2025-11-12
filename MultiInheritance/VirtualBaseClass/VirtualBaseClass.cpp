#include <iostream>
#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

// обратите внимание: PoweredDevice теперь является виртуальным базовым классом
class Scanner : virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        // эта строка требуется для создания объектов Scanner,
        // но в данном случае игнорируется
        : PoweredDevice{ power }
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

// обратите внимание: PoweredDevice теперь является виртуальным базовым классом
class Printer : virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
        // эта строка требуется для создания объектов Printer,
        // но в данном случае игнорируется
        : PoweredDevice{ power }
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : PoweredDevice{ power }, // PoweredDevice создается здесь
        Scanner{ scanner, power }, Printer{ printer, power }
    {
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

