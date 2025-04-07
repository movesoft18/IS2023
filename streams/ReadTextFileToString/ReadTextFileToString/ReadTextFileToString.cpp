#include <iostream>
#include <fstream>
using namespace std;

string ReadAllText(const string& fileName)
{
    ifstream f(fileName, ios::binary | ios::ate);
    size_t size = f.tellg();
    string result(size, '\0');
    f.seekg(0);
    f.read(&result[0], size);
    return result;
}

int main()
{
    string cppFile = ReadAllText("ReadTextFileToString.cpp");
    cout << cppFile << endl;
}

