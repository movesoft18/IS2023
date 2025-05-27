#include <iostream>
using namespace std;

void Encrypt(string& source, int key, char (*method)(char c, int key))
{
    for (auto& c : source)
        c = method(c, key);
}

char Caesar(char c, int key)
{
    char alphabetic[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return alphabetic[(c - 65 + key) % strlen(alphabetic)];
}

char XorMethod(char c, int key)
{
    return c ^ (char(key));
}

int main()
{
    int caesarKey = 1;
    int xorKey = 111;
    string source = "HELLOWORLD";
    Encrypt(source, caesarKey, Caesar);
    std::cout << source << endl;
    Encrypt(source, -caesarKey, Caesar);
    std::cout << source << endl;
    source = "Hello, world!!!";
    Encrypt(source, xorKey, XorMethod);
    std::cout << source << endl;
    Encrypt(source, xorKey, [](char c, int key) -> char { return c ^ (char(key)); });
    std::cout << source << endl;
}

