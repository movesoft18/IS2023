#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    // TODO: Загрузите в память изображение 1.jpg
    Mat img = imread("1.jpg");
    // TODO: Выведите изображение на экран
    imshow("kartinka",img);
    // TODO: Завершите программу после нажатия пользователем любой клавиши
   waitKey(0);
    // TODO: Освободите все занятые окнами ресурсы
   destroyAllWindows();

}
















/*
int main()
{
    Mat img1 = imread("1.jpg");
    Mat img2 = imread("3.jpg");
    Mat reset_center = imread("reset_center.jpg");
    Mat reset_around = imread("reset_around.jpg");
    Mat addW, withoutCenter, withoutAround, combo;
    addWeighted(img2, 0.7, img1, 0.3, 0, addW);
    bitwise_and(img1, reset_center, withoutCenter);
    bitwise_and(img2, reset_around, withoutAround);
    bitwise_or(withoutAround, withoutCenter, combo);
    imshow("Result1", addW);
    imshow("withoutCenter", withoutCenter);
    imshow("withoutAround", withoutAround);
    imshow("combo", combo);
    waitKey();
    destroyAllWindows();
    
}

/*
void addImageWatermark(cv::Mat& background, const cv::Mat& watermark) {
    // Изменяем размер водяного знака (например, 10% от ширины фона)
    int newWidth = background.cols * 0.1;
    cv::Mat resizedWatermark;
    cv::resize(watermark, resizedWatermark, cv::Size(newWidth,
        watermark.rows * newWidth / watermark.cols));

    // Позиция в нижнем правом углу
    int x = background.cols - resizedWatermark.cols - 10;
    int y = background.rows - resizedWatermark.rows - 10;

    // Область для водяного знака
    cv::Mat roi = background(cv::Rect(x, y, resizedWatermark.cols, resizedWatermark.rows));

    // Смешиваем с прозрачностью
    double alpha = 0.5;
    cv::addWeighted(roi, 1.0 - alpha, resizedWatermark, alpha, 0, roi);
}

int main() {
    cv::Mat background = cv::imread("1.jpg");
    cv::Mat watermark = cv::imread("3.jpg");

    if (background.empty() || watermark.empty()) return -1;

    addImageWatermark(background, watermark);
    cv::imwrite("image_watermark.jpg", background);

    return 0;
}
*/