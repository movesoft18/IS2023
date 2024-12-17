#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

bool isBMPFile(const string& filename)
{
    fs::path bmpFile(filename);
    if (bmpFile.extension() == ".bmp")
        return true;
    return false;
}


int main()
{
    setlocale(LC_ALL, "");
    fs::path file_path("dir1/dir2/file.txt");
    cout << file_path << endl; // Базовое имя файла
    cout << file_path.parent_path() << endl; // Родительская папка
    cout << file_path.filename() << endl; // Имя файла
    cout << file_path.extension() << endl; // расширение

    cout << isBMPFile("/dir1/dir2/file.b4mp") << endl;

    file_path.replace_filename("file2.txt"); // меняем имя файла
    file_path.replace_extension(".cpp");    // меняем расширение файла
    cout << file_path << endl; // Новое имя

    fs::path curr_path = fs::current_path(); // получаем имя текущей папки
    cout << curr_path << endl; // текущая папка
    //curr_path.append("filesystem_example.cpp"); // Добавляем новый фрагмент пути
    curr_path /= "filesystem_example.cpp";
    cout << curr_path << endl; // текущий файл кода

    if (fs::exists(curr_path))
    {
        cout << "Файл " << curr_path.filename() << " существует\n";
    }
    auto stat = fs::status(curr_path);
    if (fs::is_directory(curr_path.parent_path()))
    {
        cout << "Объект " << curr_path.parent_path() << " является папкой\n";

    }
    if (fs::is_regular_file(curr_path))
    {
        cout << "Объект " << curr_path.filename() << " является файлом\n";
    }
    fs::create_directory("dir");
    fs::create_directories("dir/dir1/dir2/dir3");

    //Нерекурсивный обход
    cout << "\n\n\n";
    for (auto& p : fs::directory_iterator(fs::current_path()))
    {
        cout << p.path() << endl;
    }

    //Pекурсивный обход
    cout << "\n\n\n";
    for (auto& p : fs::recursive_directory_iterator(fs::current_path()))
    {
        cout << p.path() << endl;
    }
    bool result = fs::copy_file(
        curr_path,
        "dir/dir1/dir2/dir3/filesystem.cpp",
        fs::copy_options::overwrite_existing
        );
    cout << "Размер файла " << 
        fs::file_size("dir/dir1/dir2/dir3/filesystem.cpp") << endl;
    fs::rename("dir/dir1/dir2/dir3/filesystem.cpp", 
        "dir/dir1/dir2/dir3/filesystem.bak");
    fs::remove_all("dir");
}