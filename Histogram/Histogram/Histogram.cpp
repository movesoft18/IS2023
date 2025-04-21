#include <iostream>
#include <map>
using namespace std;

void PrintHistogram(
    const char histogramSymbol, 
    const char symbol,
    int maxLength,
    int totalSymbolsCount,
    int symbolsCount
    )
{
    int length = (double)symbolsCount / totalSymbolsCount * maxLength;
    cout << symbol << " - " << symbolsCount << '\t';
    if (length > 0)
        for (int i = 0; i < length; i++)
            cout << histogramSymbol;
    else
        cout << (char)221;
    cout << ' ' << (double)symbolsCount / totalSymbolsCount * 100<< " %";
    cout << endl;
}

int main()
{
    int total = 100000;
    map<char, int> m
    {
        {'a', 80000},
        {'b', 3000},
        {'c', 6000},
        {'d', 1000},
        {'e', 1200},
    };
    for (auto& e : m)
        PrintHistogram(219, e.first, 50, 100000, e.second);

  /* for (int i = 0; i < 255; i++)
        cout << i << ' ' << (char)i << ' '; */
}
