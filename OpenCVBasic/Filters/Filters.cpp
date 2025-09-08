#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    setlocale(LC_ALL, "");
    Mat img, medianImg, gaussImg, bilat, box;
    //img = imread("image.jpg");
    img = imread("eurobot.bmp");
    if (!img.empty())
    {
        imshow("Оригинал", img);
        GaussianBlur(img, gaussImg, Size(3, 3), 0);
        medianBlur(img, medianImg, 3);
        bilateralFilter(img, bilat, 3, 150, 150);
        boxFilter(img, box, 0, Size(3,3));
        imshow("Двусторонний фильтр", bilat);
        imshow("Медианный фильтр", medianImg);
        imshow("Фильтр гаусса", gaussImg);
        imshow("Фильтр Box", box);
        waitKey();
    }
    else
        cout << "Файл изображения не найден!!!";
}

