#include <iostream>

using namespace std;
int main()
{
    char str[]{ "Hello, world!!!" };
    char str1[] = "Hello, world!!!";
    char str2[] = { 'H','e','l','l','o'};
    char str3[] = { "Hello"};
    char str4[20] = { "Hello" };
    char* str10 = new char[100];
    int len = strlen(str3);
    std::cout << len << endl;
    strcpy_s(str, 6, str3);
    cout << strcmp(str1, str) << endl; // 0 если равны, -1 если str1 < str, 1 если str > st1
    str10 = strcat(str, str1);
    cout << str10 << endl;
    //str = str3;

}