#include <ranges>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> Split(const string& s, char delimiter)
{
    vector<string> result;
    result.reserve(10);
    auto list = views::split(s, delimiter);
    for (const auto& s : list)
        result.emplace_back(s.begin(), s.end());
    return result;
}

int main()
{
    setlocale(LC_CTYPE, "");
    string text = "Это просто набор слов, разделенных пробелом";
    auto list = views::split(text, ' ');
    for (const auto& s : list)
        cout << string(s.begin(), s.end()) << endl;
    auto res = Split(text, ' ');
    for (const auto& s : res)
        cout << s << endl;
}