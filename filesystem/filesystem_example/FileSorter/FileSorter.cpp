#include <iostream>
#include <filesystem>
using namespace std::filesystem;
using namespace std;

void SortFiles(const path& folder)
{
    path images_dir = folder.parent_path();
    path labels_dir = images_dir;
    images_dir /= "images";
    labels_dir /= "labels";
    // создаем папки для изображений и аннотаций
    create_directory(images_dir);
    create_directory(labels_dir);

    // сортировка
    for (auto& file : directory_iterator(folder))
    {
        path curr_file = file.path(); // получаем тек. объект
        if (exists(curr_file) &&
            is_regular_file(curr_file)
            ) // проверяем что он существует и это файл
        {
            bool res = false;
            if (curr_file.extension() == ".jpg")
            {
                // копируем в папку images
                path target_file = images_dir; // формируем имя
                target_file /= curr_file.filename(); // результирующего файла
                res = copy_file(curr_file, target_file,
                    copy_options::overwrite_existing);

            }
            else if (curr_file.extension() == ".txt")
            {
                // копируем в папку labels
                path target_file = labels_dir; // формируем имя
                target_file /= curr_file.filename(); // результирующего файла
                res = copy_file(curr_file, target_file,
                    copy_options::overwrite_existing);
            }
            if (res)
            {
                cout << "Файл " << curr_file.filename() << " скопирован" << endl;
                res = remove(curr_file);
                if (res) cout << "Файл " << curr_file.filename() << " удален из исходной папки" << endl;
            }
        }
    }
    
}

int main()
{
    setlocale(LC_ALL, "");
    path curr_dir = current_path();
    curr_dir /= "files";
    SortFiles(curr_dir);
}
