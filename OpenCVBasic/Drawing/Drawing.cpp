
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    //setlocale(LC_ALL, "");
    Mat image = Mat::zeros(600, 800, CV_8UC3);
    circle(image,           // где рисуем
        Point(400, 300),    // центр
        100,                // радиус
        Scalar(200, 200, 0),// цвет
        -1);                // толщ линии (-1 - закрашенный)
    line(image,             // где рисуем
        Point(0, 0),        // старт точка
        Point(700, 100),    //кон точка
        Scalar(255, 255, 255),  // цвет
        10);                // толщ линии (-1 - закрашенный)
    rectangle(image,        // где рисуем
        Rect(100, 100, 200, 150), // область рисования (x,y,ширина, высота)
        Scalar(0, 0, 255),  // цвет
        20);                // толщ линии (-1 - закрашенный)
    ellipse(image,          // где рисуем
        Point(600, 250),    // центр
        Size(100, 150),     // размеры осей x, y
        30,                 // угол поворота
        0,                  // старт угол рисования
        260,                // кон угол рисования
        Scalar(40, 167, 120),// цвет
        -1);                // толщ линии (-1 - закрашенный)
    drawMarker(image, Point(300,300), Scalar(240,20,100),
        MARKER_STAR, 50, 10);
    putText(image, // где рисуем
        "Hello, world! Привет",    // текст
        Point(0, 200),    // коорд вывода текста (нижний левый угол первой буквы)
        FONT_HERSHEY_COMPLEX, // шрифт
        3,              // масштаб текста
        Scalar(255, 255, 255), // цвет
        2                   // толщ. линии
    );
    imshow("Image", image);
    waitKey();
    destroyAllWindows();
}

