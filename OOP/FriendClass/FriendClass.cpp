#include <iostream>

class Values
{
private:
    int m_intValue;
    double m_dValue;
public:
    Values(int intValue, double dValue)
    {
        m_intValue = intValue;
        m_dValue = dValue;
    }

    // Делаем класс Display другом класса Values
    friend class Display;
};

class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }

    void displayItem(Values& value)
    {
        if (m_displayIntFirst)
            std::cout << value.m_intValue << " " << value.m_dValue << '\n';
        else // или сначала выводим double
            std::cout << value.m_dValue << " " << value.m_intValue << '\n';
    }

    friend class Values;
};

int main()
{
    Values value(7, 8.4);
    Display display(false);

    display.displayItem(value);

    return 0;
}
