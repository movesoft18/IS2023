#include <iostream>
#include <fstream>
using namespace std;

bool FileExists(string filename)
{
    ifstream f(filename);
    if (f)
    {
        f.close();
        return true;
    }
    return false;
}

int FileLength(string filename)
{
    ifstream f(filename);
    if (f)
    {
        f.seekg(0, ios_base::end);
        return f.tellg();
    }
    return -1;
}


int main()
{
    cout << FileLength("..\\SEFiles\\results.txt") << endl;
    ifstream f("..\\SEFiles\\results.txt");
    if (f)
    {
        double a, b, c;
        f.seekg(10);
        f >> a >> b >> c;
        int pos = f.tellg();

        cout << pos << endl;
        cout << a << " " << b << " " << c << endl;
        f.close();
    }
}

