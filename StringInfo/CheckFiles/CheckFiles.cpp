#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    string files[]{
        "file1.jpg",
        "file3.jpg",
        "f1.jpg",
        "file2.txt",
        "file4.doc",
        "image6.jpg",
        "file6437.exe",
        "hgsdgh.jpg",
    };
    
    cout << "Файлы, начинающиеся на <file>:";
    for (const auto &s: files)
    {
        /*if (files[i].find("file") == 0)
            cout << files[i] << endl;*/
        if (s.starts_with("file"))
            cout << s << endl;

    }
    cout << "Файлы, заканчивающиеся на <.jpg>:";
    for (auto& s : files)
    {
        /*if (files[i].rfind(".jpg") == files[i].length() - 4)
            cout << files[i] << endl;*/
        if (s.ends_with(".jpg"))
            cout << s << endl;
    }
}

