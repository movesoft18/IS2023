﻿#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    Mat img = imread("lion.png", IMREAD_COLOR);
    if (img.empty())
    {
        cout << "Error reading file!\n";
        return 1;
    }
    cout << "Ширина изображения: " << img.cols << endl;
    cout << "Высота изображения: " << img.rows << endl;

    imshow("Lion", img);

    Mat imgCopy = img.clone();
    imshow("Копия", imgCopy);

    Rect selected = selectROI("Выберите прямоугольную область", imgCopy);
    Mat imgCrop = imgCopy(selected);
    imshow("Вырезка", imgCrop);
    imwrite("lion_face.jpg", imgCrop);

    auto key = waitKey();
    Mat resized, rotated, gray, bilevel;
    resize(imgCrop, resized, Size(), 5, 5);
    imshow("Изменен размер", resized);
    waitKey();

    rotate(resized, rotated, ROTATE_90_COUNTERCLOCKWISE);
    imshow("Повернуто", rotated);

    cvtColor(rotated, gray, COLOR_BGR2GRAY);
    imshow("Серый", gray);

    threshold(gray, bilevel, 220, 255, THRESH_OTSU);
    imshow("ЧБ", bilevel);

    waitKey();

    destroyAllWindows();
}
