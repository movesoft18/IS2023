#include <iostream>
using namespace std;

class ConsolePrinter
{
public:
    void Print(string text)
    {
        cout << text << endl;
    }
};

class Book
{
public:
    string Text;
    ConsolePrinter Printer;

    void Print()
    {
        cout << Text << endl;
    }
};

class IPrinter
{
public:
    virtual void Print(string text) = 0;
};

class Book
{
public:
    string Text;
    IPrinter* Printer;

    Book(IPrinter* printer)
    {
        this->Printer = printer;
    }

    void Print()
    {
        Printer->Print(Text);
    }
    virtual ~Book()
    {
        delete Printer;
    }
};

class ConsolePrinter : public IPrinter
{
    void Print(string text) override
    {
        cout << "Печать на консоли\n";
    }
};

class HtmlPrinter : public IPrinter
{
    void Print(string text) override
    {
        cout << "Печать в html\n";
    }
};

int main()
{
    Book book(new ConsolePrinter());
    book.Print();
    book.Printer = new HtmlPrinter();
    book.Print();
}
