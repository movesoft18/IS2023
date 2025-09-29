#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    
    vector<int> coords;
    double corr = 1;
    int x, y;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    Mat img = imread("field1.jpg");
    Mat copy = imread("field1.jpg");
    Mat temp = imread("template.jpg");
    Mat mask = imread("mask.jpg");
    Mat result;
    if (img.empty()  || temp.empty())
    {
        cout << "Can't read one of the images" << endl;
        return 1;
    }
    matchTemplate(img, temp, result, TM_CCORR_NORMED);

    while (corr >= 0.87)
    {
        minMaxLoc(result, &minVal, &corr, &minLoc, &maxLoc);
        x = maxLoc.x;
        y = maxLoc.y;
       // result.at<float>(maxLoc) = 0.f;
        if (corr >= 0.87)
        {
            circle(result, Point(maxLoc), temp.cols / 2,
                Scalar(0, 0, 0), -1);
            coords.push_back(x);
            coords.push_back(y);
            rectangle(copy, Rect(x, y, temp.cols, temp.rows), Scalar(255, 0, 255), 2);
            //ellipse(result, Point(x + temp.rows / 2, y + temp.cols / 2), Size(temp.cols / 2, temp.rows / 2 ), 0, 0, 360, Scalar(255, 0, 255), 2);
        }
        imshow("corr", result);
        imwrite("result.jpg", result);
        imshow("Result", copy);
        waitKey();
    }
    for (auto i = 0; i < coords.size()/2; i++)
    {
        cout << coords[i * 2] << ' ' << coords[i * 2 + 1] << endl;
    }
    
   /* Mat result;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    Mat img = imread("field.jpg");
    Mat temp = imread("template.jpg");
    matchTemplate(img, temp, result, TM_CCORR_NORMED);
    imshow("results", result);
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
    double corr = maxVal;
    int x = maxLoc.x;
    int y = maxLoc.y;
    ellipse(img, Point(x + temp.rows / 2, y + temp.cols / 2), 
        Size(temp.rows / 2, temp.cols / 2), 0, 0, 
        360, Scalar(255, 0, 255), 2);
    imshow("Image", img);
    cout << "x=" << x << " y=" << y << " corr=" << corr << endl;
    waitKey(0);
    */
}

