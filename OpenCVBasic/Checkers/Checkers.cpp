#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

int main()
{
    Point minLoc, maxLoc;
    double minVal, maxVal;
    Mat result;
    Mat field = imread("s1.png");
    Mat tmp = imread("red.png");
    Mat mask = imread("red_mask_gray.png");
    imshow("mask1", mask);
    resizeWindow("mask1", Size(200, 200));
    //cvtColor(mask, mask, COLOR_BGR2GRAY);
    matchTemplate(field, tmp, result, TM_CCORR_NORMED);
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
    cout << "val=" << maxVal << " x=" << maxLoc.x <<
        " y=" << maxLoc.y << endl;
    circle(field, maxLoc, 5, Scalar(255, 0, 0), -1);
    imshow("result", result);
    imshow("field", field);
    imshow("tmp", tmp);
    imshow("mask", mask);
    resizeWindow("mask", Size(200, 200));
    waitKey();
    destroyAllWindows();
}
