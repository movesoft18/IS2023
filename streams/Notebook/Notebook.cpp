#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push,1)

struct Notes {    // структура данных записной книжки
    char Name[60];   // Ф.И.О.
    char Phone[16];  // телефон
    int  Age;        // возраст
};

#pragma pack(pop)

void CreateNotebook()
{
    Notes  Note1{ "Грозный Иоанн Васильевич", "не установлен", 60 };
    Notes  Note2{ "Годунов Борис Федорович ", "095-111-2233 ", 30 };
    Notes  Note3{ "Романов Петр Михайлович ", "812-333-2211 ", 20 };
    ofstream ofile("Notebook.dat", ios::binary);

    // обратите внимание (char*)&Note1 - это преобразование указателя ни Note1
    // к указателю на char*
    // & - операция взятия адреса
    ofile.write((char*)&Note1, sizeof(Notes));     // 1-й блок
    ofile.write((char*)&Note2, sizeof(Notes));     // 2-й блок
    ofile.write((char*)&Note3, sizeof(Notes));     // 3-й блок
    ofile.close();                    // закрыть записанный файл
}

void ReadNotebook()
{
    ifstream ifile("Notebook.dat", ios::binary);
    Notes  Note;                   // структурированная переменная
    //char str[80];                  // статический буфер строки
    // Считывать и отображать строки в цикле, пока не eof

    while (ifile.read((char*)&Note, sizeof(Notes)))
    {
        cout << "Имя " << Note.Name << endl;
        cout << "Телефон " << Note.Phone << endl;
        cout << "Возраст " << Note.Age << endl;
        //cout << str << endl;
    }
    ifile.close();                 // закрыть прочитанный файл
}

void ChangeRecord(int recNum)
{
    fstream f("Notebook.dat", ios::binary | ios::in | ios::out);
    if (f)
    {
        Notes note;
        f.seekg(recNum * sizeof(Notes));
        f.read((char*)&note, sizeof(Notes));
        //strcpy_s(note.Phone, "89121112233");
        note.Age = 200;
        f.seekg(recNum * sizeof(Notes));
        f.write((char*)&note, sizeof(Notes));
        f.close();
    }
}

int main() {
    setlocale(LC_ALL, "ru-Ru");
    //CreateNotebook();
    ReadNotebook();
    //ChangeRecord(2);
}