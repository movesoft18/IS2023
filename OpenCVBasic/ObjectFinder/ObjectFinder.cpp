#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void FindObject(Mat* img, Mat* temp, int &x, int &y, double &probability)
{
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    Mat result;
    matchTemplate(*img, *temp, result, TM_CCORR_NORMED);
    //imshow("Карта вероятностей", result);
    //waitKey();
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
    probability = maxVal;
    x = maxLoc.x;
    y = maxLoc.y;
    rectangle(*img, maxLoc, Point(x + temp->cols, y + temp->rows), Scalar(255,255,255), -1);
    return;

}

int main()
{
    /*
    vector<int> coords;
    double probability = 1;
    int x, y;
    Mat img = imread("field1.jpg");
    Mat result = imread("field1.jpg");
    Mat temp = imread("template.jpg");
    if (img.empty()  || temp.empty())
    {
        cout << "Can't read one of the images" << endl;
        return 1;
    }

    while (probability >= 0.87)
    {
        FindObject(&img, &temp, x, y, probability);
        if (probability >= 0.87)
        {
            coords.push_back(x);
            coords.push_back(y);
            ellipse(result, Point(x + temp.rows / 2, y + temp.cols / 2), Size(temp.rows / 2, temp.cols / 2), 0, 0, 360, Scalar(255, 0, 255), 2);
        }
        imwrite("result.jpg", result);
        imshow("Result", result);
    }
    for (auto i = 0; i < coords.size()/2; i++)
    {
        cout << coords[i * 2] << ' ' << coords[i * 2 + 1] << endl;
    }
    */
    Mat result;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    Mat img = imread("field.jpg");
    Mat temp = imread("template.jpg");
    matchTemplate(img, temp, result, TM_CCORR_NORMED);
    imshow("results", result);
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
    double probability = maxVal;
    int x = maxLoc.x;
    int y = maxLoc.y;
    ellipse(img, Point(x + temp.rows / 2, y + temp.cols / 2), 
        Size(temp.rows / 2, temp.cols / 2), 0, 0, 360, Scalar(255, 0, 255), 2);
    imshow("Image", img);
    waitKey(0);

}

