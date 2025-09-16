#include <iostream>

class Values; // предварительное объявление класса Values

class Display
{
private:
	bool m_displayIntFirst;

public:
	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
	//void SomeMethod(Values& value)
	//{
	//	value.m_dValue += 10;
	//}

	void displayItem(Values& value); // предварительное объявление, приведенное выше, требуется для этой строки
};

class Values // полное определение класса Values
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
	// Делаем метод Display::displayItem() другом класса Values
	friend void Display::displayItem(Values& value);
};

// Теперь мы можем определить метод Display::displayItem(), которому требуется увидеть полное определение класса Values
void Display::displayItem(Values& value)
{
	if (m_displayIntFirst)
		std::cout << value.m_intValue << " " << value.m_dValue << '\n';
	else // или выводим сначала double
		std::cout << value.m_dValue << " " << value.m_intValue << '\n';
}

int main()
{
	Values value(7, 8.4);
	Display display(false);

	display.displayItem(value);

	return 0;
}
