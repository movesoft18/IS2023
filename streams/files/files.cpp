#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    //ofstream f("example.txt", ios::app);
    ofstream f;

    f.open("example.txt", ios::app);
    if (f.is_open())
    {
        f << "Hi, World!\n";
        //f.flush();
        f.close();    
    }

    ifstream fin("example.txt");
    string data;
    if (fin)
    {
        //fin >> data;
        getline(fin, data);
        cout << data;
        fin.close();
    }

}