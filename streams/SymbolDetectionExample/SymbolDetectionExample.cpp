#include <iostream>
#include <locale>
using namespace std;

int main()
{
    string s = "Это__''> text...";
    locale loc("ru-RU");
    int count = 0;
/*    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i], loc))
            count++;
    }*/
    for (char c : s)
    {
        if (isalpha(c, loc))
            count++;
    }
    std::cout << "symbols count=" << count;
}
