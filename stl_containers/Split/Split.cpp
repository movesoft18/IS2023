﻿
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

//Эта функция должна       поделить строку на части.
vector<string> split(const string& str, char delimiter = ' ')
{
    vector<string> result;
    string part;
    size_t startPos = 0;
    size_t pos = str.find(delimiter);
    while (pos != std::string::npos)
    {
        part = str.substr(startPos, pos - startPos);
        if (part.length() > 0)
            result.push_back(part);
        startPos = pos + 1;
        pos = str.find(delimiter, pos + 1);
    }
    part = str.substr(startPos, str.length() - startPos);
    if (part.length() > 0)
        result.push_back(part);
    return result;
}

size_t multifind(const string& str, const set<char>& delimiters , size_t startPos = 0)
{
    for (size_t i = startPos; i < str.length(); i++)
    {
        if (delimiters.count(str[i]) > 0)
            return i;
    }
    return std::string::npos;
}

vector<string> multisplit(const string& str, const set<char>& delimiters = {' '})
{
    vector<string> result;
    string part;
    size_t startPos = 0;
    size_t pos = multifind(str, delimiters);
    while (pos != std::string::npos)
    {
        part = str.substr(startPos, pos - startPos);
        if (part.length() > 0)
            result.push_back(part);
        startPos = pos + 1;
        pos = multifind(str, delimiters, pos + 1);
    }
    part = str.substr(startPos, str.length() - startPos);
    if (part.length() > 0)
        result.push_back(part);
    return result;
}

int main()
{
    setlocale(LC_CTYPE, "");
    string example = "192.56, -21.2, 17.08, 22.8, -0.01, 0.02, 33.2, 43.8, -12.1, 14.5";
    auto result = split(example, ',');
    for (auto& s : result)
        cout << s << endl;
    cout << endl;
    vector<double> numbers;
    for (auto& s : result)
    {
        double n = stod(s);
        numbers.push_back(n);
    }
    example = "Эта  функция,должна       поделить, строку.на.части.";
    auto result1 = multisplit(example, set<char> {' ', '.',','});
    for (auto& s : result1)
        cout << s << endl;
}

