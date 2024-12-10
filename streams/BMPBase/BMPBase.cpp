#include <iostream>
#include "SFML\Graphics.hpp"
#include <fstream>
#include "windows.h"
using namespace std;
using namespace sf;

#pragma pack (push,1) // обязательно выключаем выравнивание элементов структур по умолчанию
struct BitmapFileHeader
{
    char  bfType[2];  // сигнатура файла "BM"
    unsigned long bfSize; // размер файла в байтах
    unsigned short  bfReserved1;
    unsigned short  bfReserved2;
    unsigned long bfOffBits; // смещение относительно начала файла в байтах, где располагаются растровые данные
};

struct BitmapInfoHeader
{
    unsigned long biSize; // размер структуры BitmapInfoHeader == 40 байт
    long biWidth;
    long biHeight; // высота изображения в пикселах
    unsigned short biPlanes; // число цветовых планов == 1
    unsigned short biBitCount; // число бит на пиксель
    unsigned long biCompression; // тип сжатия изображения
    unsigned long biSizeImage; //размер растрового изображения в байтах
    long biXPelsPerMeter;  // разрешение изображения по ширине
    long biYPelsPerMeter;  // разрешение изображения по высоте
    unsigned long biClrUsed; // число испольщуемых цветов изображения, если == 0, то используются все доступные цвета
    unsigned long biClrImportant;  // число важных цветов изображения

};



struct RGBQuad  // структура элемента таблицы палитры
{
    unsigned char blue;  // интенсивность синего
    unsigned char green; // интенсивность зеленого
    unsigned char red;   // интенсивность красного
    unsigned char reserved; // не используется, служит для выравнивания структуры на 4-х байтную границу
};
#pragma pack(pop)

RenderWindow window(VideoMode(1024, 768), "BMP Test");

void Show24BitImage(BitmapFileHeader& BFH, BitmapInfoHeader& BIH, ifstream& f)

{

    // эту функцию вы должны будете реализовать сами

}



void Show8BitImage(BitmapFileHeader& BFH, BitmapInfoHeader& BIH, ifstream& f)

{

    // эту функцию вы должны будете реализовать сами

}





// вывод 16-ти цветного изображения. Каждая точка кодируется 4-мя битами. 1 байт содержит данные о 2-х
// соседних точках изображения
// функция принимает ссылки на заголовки файла и ссылку на файловый поток с растровыми данными
void Show4BitImage(BitmapFileHeader& BFH, BitmapInfoHeader& BIH, ifstream& f)
{
    CircleShape point(1.f);// объявляем объект SFML - окружность дияметром 1, т.к. объекта-точки в SFML нет
    // вычисляем количество используемых цветов. Если biClrUsed == 0, используются все доступные цвета
    int colors = (BIH.biClrUsed == 0) ? 16 : BIH.biClrUsed;
    RGBQuad* palette = new RGBQuad[sizeof(RGBQuad) * colors];// выделяем память для палитры. Количество элементов равно количесвту цветов
    f.read((char*)palette, sizeof(RGBQuad) * colors);// читаем палитру. Она иет сразу за BitmapInfoHeader
    f.seekg(BFH.bfOffBits);// позиционируем указатель файла на начало растровых данных
    int rowLength = BIH.biWidth / 2 + BIH.biWidth % 2;// вычисляем длину строки изображения в байтах
    if (rowLength % 4 != 0) // она должна быть кратна 4-м.
        rowLength = rowLength / 4 * 4 + 4;
    unsigned char* bits = new unsigned char[rowLength];// выделяем память для растровых данных
    for (int y = BIH.biHeight - 1; y >= 0; y--) // цикл вывода строк. Строки располагаются снизу-вверх
    {
        f.read((char*)bits, rowLength); // для каждой строки читаем растровые данные в память
        for (int x = 0; x < BIH.biWidth; x++) // цикл вывода пикселей строки
        {
            // вычисляем индекс цвета colorIndex
            // индекс цвета может располагаться в 4-х старших или 4-х младших битах проверемого байта
            // проверяемый байт выичляется x/2, где х - координата х выводимого пикселя
            // если х кратен 2-м, то берем старшие 4 бита, если не кратен, то младшие 4 бита.
            //старшие 4 бита берутся путем битового сдвига байта вправо на 4 бита (остаются только старшие 4 бита, младшие исчезают за границами разрядной сетки)
            // младшие 4 бита можно получить путем побитовой операции И нашего байта с маской 0x0f (00001111)
            unsigned char colorIndex = (x % 2 == 0) ? (bits[x / 2] >> 4) : (bits[x / 2] & 0x0f);
            // выбираем из палитрыы элементы с вычисленным индексом и помещаем их в переменные blue, green, red

            unsigned char blue = palette[colorIndex].blue;
            unsigned char green = palette[colorIndex].green;
            unsigned char red = palette[colorIndex].red;
            point.setFillColor(Color(red, green, blue));// задаем цвет нашей единичной окружности
            point.setPosition(x, y); // позиционируем окружность в нужную точку окна
            window.draw(point); // рисуем точку
        }
    }
    delete[] bits; // освобождаем память, выделенную под строку растра
    delete[] palette; // освобождаем память, выделенную для палитры
}


// вывод монохромного изображения. Каждый бит растровых данных кодирует одну точку
// функция принимает ссылки на заголовки файла и ссылку на файловый поток с растровыми данными
void Show1BitImage(const BitmapFileHeader& BFH, const BitmapInfoHeader& BIH, ifstream& f)
{
    CircleShape point(0.5f); // объявляем объект SFML - окружность дияметром 1, т.к. объекта-точки в SFML нет
    // вычисляем количество используемых цветов. Если biClrUsed == 0, используются все доступные цвета
    int colors = (BIH.biClrUsed == 0) ? 2 : BIH.biClrUsed;

    RGBQuad* palette = new RGBQuad[sizeof(RGBQuad) * colors]; // выделяем память для палитры. Количество элементов равно количесвту цветов
    f.read((char*)palette, sizeof(RGBQuad) * colors); // читаем палитру. Она иет сразу за BitmapInfoHeader
    f.seekg(BFH.bfOffBits); // позиционируем указатель файла на начало растровых данных

    int rowLength = BIH.biWidth / 8 + (int)(BIH.biWidth % 8 != 0); // вычисляем длину строки изображения в байтах
    if (rowLength % 4 != 0) // она должна быть кратна 4-м.
        rowLength = rowLength / 4 * 4 + 4;

    unsigned char* bits = new unsigned char[rowLength]; // выделяем память растровых данных

    for (int y = BIH.biHeight - 1; y >= 0; y--) // цикл вывода строк. Строки располагаются снизу-вверх
    {
        f.read((char*)bits, rowLength); // для каждой строки читаем растровые данные в память
        unsigned char mask = 128; // задаем маску для определения бита изображения. Первый пиксель выделяется маской 10000000b == 128
        for (int x = 0; x < BIH.biWidth; x++) // цикл вывода пикселей строки
        {
            if (x % 8 == 0) // проверяем, закончили ли разбирать очередной байт растровых данных
                mask = 128; // если да, то маска сбрасывается в первоначальное состояние
         // вычисляем индекс цвета colorIndex в зависимости от значенияя бита в байте
         // х/8 - выражение для вычисления номера байта
         // bits[x / 8] & mask - выражение для вычисления кстановлен ли соответствующий бит или сброшен
         // например проверим 6 бит:
         // байт                    01011001
         // маска            01000000 - в маске должно быть такое число, в котором установлен лишь тот бит, номер которого мы хотим проверить в интересующем байте
         // результат 01000000 - если результат == 0, то проверемй бит тоже 0, если результат != 0, то бит == 1
            unsigned char colorIndex = (bits[x / 8] & mask) != 0 ? 1 : 0;
            // выбираем из палитрыы элементы с вычисленным индексом и помещаем их в переменные blue, green, red
            unsigned char blue = palette[colorIndex].blue;
            unsigned char green = palette[colorIndex].green;
            unsigned char red = palette[colorIndex].red;
            point.setFillColor(Color(red, green, blue));// задаем цвет нашей единичной окружности
            point.setPosition(x, y); // позиционируем окружность в нужную точку окна
            window.draw(point); // рисуем точку
            mask >>= 1; // сдвигаем маску вправо на 1 двоичный разряд, чтобы обеспечить проверку следующей по счету точки растровых данных

        }
    }
    delete[] bits; // освобождаем память, выделенную под строку растра
    delete[] palette; // освобождаем память, выделенную для палитры
}

bool ReadAndShowBMP(const string& filename)
{
    BitmapFileHeader BFH; // объявляем переменную для хранения заголовка BitmapFileHeader
    BitmapInfoHeader BIH; // объявляем переменную для хранения заголовка BitmapInfoHeader
    ifstream f(filename, ios::binary); // открываем для фтения файл в бинарном режиме
    if (!f) // если файл не открыт
        return false; // выходим с отрицательным результатом
    f.read((char*)&BFH, sizeof(BitmapFileHeader)); // читаем из файла заголовок BitmapFileHeader в переменную BFH
    f.read((char*)&BIH, sizeof(BitmapInfoHeader));       // читаем из файла заголовок BitmapInfoHeader в переменную BIH
    
    // Здесь должна быть проверка корректности файла

    switch (BIH.biBitCount) // в зависимости от количества бит на пиксель вызываем разные функции отрисовки изображения
    {
    case 1:
        Show1BitImage(BFH, BIH, f); // монохромное
        break;
    case 4:
        Show4BitImage(BFH, BIH, f); // 16-ти цветное
        break;
    case 8:
        Show8BitImage(BFH, BIH, f); // 256-ти цветное
        break;
    case 24:
        Show24BitImage(BFH, BIH, f); // полноцветное
        break;
    }
    f.close(); // закрываем файл
}

int main()
{
    //window.setFramerateLimit(1);
    window.clear(); // очищаем окно
    ReadAndShowBMP("4.bmp"); // вызываем нашу функцию вывода bmp файла
    window.display(); // отображаем построенное изображение нв экране
    cin.get();
    //while (window.isOpen()) // ждем закрытия окна
    //{
    //    Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == Event::Closed)
    //            window.close();
    //    }
    //}
}