#include <iostream>
#include <string>
using namespace std;

template <typename T> // Объявляем шаблонную функцию с параметром T
bool ReadValue(const std::string& source, T& result) // это второй параметр функции
{
    size_t errSymbolPos;
    try // защищаемый блок
    {
        // а вот здесь нам нужно определить тип передаваемого параметра T и в зависимости от него
        // вызвать нужную нам функцию преобразования. Узнать тип параметра нам поможет функция typeid()
        if (typeid(T) == typeid(double)) // если это double
            result = stod(source, &errSymbolPos); // то преобразуем в double
        else if (typeid(T) == typeid(float)) // если float
            result = stof(source, &errSymbolPos); // то во float
        else if (typeid(T) == typeid(int)) // если int
            result = stoi(source, &errSymbolPos); // то в int
        else throw std::invalid_argument("Invalid type"); // иначе генерируем исключение std::invalid_argument (поскольку мы не поддерживаем
        // другие типы чисел, хотя перечень можно и расширить
        if (errSymbolPos < source.length()) // весь остальной код вам уже знаком
        {
            result = 0;
            return false;
        }
    }
    catch (std::invalid_argument e)
    {
        result = 0;
        return false;
    }
    return true;
}

void Calculate1()
{
    double a = 0, b = 0, c = 0, d = 0;
    string source;      // строка, в которой будем получать значения с консоли
    cout << "Введите коэффициент a:";
    cin >> source; // читаем строку
    bool r = ReadValue(source, a); // преобразовываем ее в число
    if (!r) goto error; // если возвращено false - переходим к обработке ошибок в секцию с меткой error
    cout << "Введите коэффициент b:";
    cin >> source; // читаем строку
    r = ReadValue(source, b); // преобразовываем ее в число
    if (!r) goto error; // если возвращено false - переходим к обработке ошибок в секцию с меткой error
    cout << "Введите коэффициент c:";
    cin >> source; // читаем строку
    r = ReadValue(source, c); // преобразовываем ее в число
    if (!r) goto error; // если возвращено false - переходим к обработке ошибок в секцию с меткой error
    d = b * b - 4 * a * c;
    cout << " d = " << d << endl;
    return;
error:
    cout << "Ошибка ввода данных, вычисление невозможно";
}

int main()
{
    setlocale(LC_ALL, "");
    Calculate1();
}