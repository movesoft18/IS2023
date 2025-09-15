#include <iostream>
using namespace std;
class SomeClass
{
public:
    // указатель на строку в динамической памяти
    // из-за этого указателя и будут все наши проблемы
    char* str;
    // конструктор 1
    SomeClass()
    {
        // инициализируем строку по умолчанию
        str = new char[100] {"Hello, world"};
    }
    // конструктор 2
    SomeClass(const char* c)
    {
        // выделяем память под строку
        str = new char[strlen(c) + 1];
        //копируем в эту область памяти данные из строки, переданной в качестве параметра
        strcpy_s(str, strlen(c) + 1, c);
    }

    // конструктор копирования принимает константную ссылку на объект того же
    // класса, что и сам создаваемый объект.
    // при этом this - указатель на создаваемый объект, other - ссылка на объект,
    // копию которого создаем
    SomeClass(const SomeClass& other)
    {
        // выделяем память для хранения строки и записываем ее адрес в указатель str
        this->str = new char[strlen(other.str) + 1];
        // копируем в выделенную область памяти строку копируемого объекта
        strcpy_s(this->str, strlen(other.str) + 1, other.str);
        // на самом деле this в этом примере можно и не использовать
        // но я считаю, что так проще различить поля создаваемого и копируемого объектов
    }

    ~SomeClass()
    {
        // в деструкторе удаляем струку из памяти
        delete[] str;
    }
    void SetText(const char* newText)
    {
        // при установке нового текста мы сначала удаляем старую строку из памяти
        delete[] str;
        // потом выделяем память для новой строки
        str = new char[strlen(newText) + 1];
        // потом копируем в нее новый текст
        strcpy_s(str, strlen(newText) + 1, newText);
    }

    void OutStr()
    {
        // выводим строку в консоль
        cout << str << endl;
    }
};

int main()
{
    SomeClass* C = new SomeClass("My name is Vasya");
    C->OutStr();
    SomeClass* D = new SomeClass(*C);
    D->OutStr();
    D->SetText("Petya");
    D->OutStr();
    C->OutStr();
    delete D;
    delete C;
    cin.get();
}