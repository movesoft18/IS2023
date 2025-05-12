#include <iostream>
#include <cpr/cpr.h> // библиотека http запросов
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    auto r = cpr::Get(cpr::Url("https://vudgu.ru")); // get запрос по url https://vudgu.ru
    if (r.status_code == 200) // проверяем код статуса, если 2хх - то запрос успешен
    {
        std::cout << r.text << endl; // r.text содержит полученные данные в виде строки или массива байт
    }
    else
    {
        cout << "Ошибка: " << r.error.message << endl; // иначе ошибка, печатаем сообщение в консоль
    }
    

    // пример закачки изображения
    auto image = cpr::Get(cpr::Url("https://vudgu.ru/upload/resize_cache/iblock/eac/500_250_2/22oiqou8cf2pescxz2swujzbvsxths6j.png"));
    if (image.status_code == 200)
    {
        ofstream f("image.png", ios::binary); // открываем файл для записи
        f.write((char*)image.text.data(), image.text.size()); // записываем массив байт в файл (строку text следкет рассматривать как массив байт
        f.close();
    }

    // Но есть специальный способ закачки cpr::Download  и cpr::DownloadAsync
    ofstream f("image1.png", ios::binary); // файл для записи
    // скачиваем, первый параметр - передаем поток ofstream, 2-й url закачки
    r = cpr::Download(f, cpr::Url{ "https://vudgu.ru/upload/resize_cache/iblock/eac/500_250_2/22oiqou8cf2pescxz2swujzbvsxths6j.png" });
    std::cout << "http status code = " << r.status_code << std::endl << std::endl; // проверяем статус код
    f.close();

    // асинхронный вариант закачки
    // передаем первым параметром путь к сохраняемому файлу, используа std::filesystem::path
    // вторым параметром - url закачки
    auto ra = cpr::DownloadAsync(filesystem::path("image2.png"), cpr::Url{ "https://vudgu.ru/upload/resize_cache/iblock/eac/500_250_2/22oiqou8cf2pescxz2swujzbvsxths6j.png" });
    cout << "Делаю чтото еще...\n"; // пока скачивается, главный поток может чтото делать еще
    r = ra.get(); // получаем результат асинхронной операции
    std::cout << "http status code = " << r.status_code << std::endl << std::endl; // проверяем статус код

}