#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

bool use_mask;
Mat img; Mat templ; Mat mask; Mat result;
const char* image_window = "Source Image";
const char* result_window = "Result window";
int match_method;
int max_Trackbar = 5;
vector<vector<Point>> cnts;

void MatchingMethod()
{
    Mat img_display;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    img.copyTo(img_display);
    int result_cols = img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;
    result.create(result_rows, result_cols, CV_32FC1);
    matchTemplate(img, templ, result, TM_CCORR_NORMED);
    //normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

    Point matchLoc;
    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
    matchLoc = maxLoc;
    cout << maxVal << endl;
    //rectangle(img, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar(255,255,255), 2);
    rectangle(img, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar(255, 255, 255), -1);
    rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(255), 2, 8, 0);
    imshow(image_window, img);
    imshow(result_window, result);
    return;
}
int main(int argc, char** argv)
{
    img = imread("image.jpg", IMREAD_GRAYSCALE);
    Mat img1 = imread("image.jpg");
    GaussianBlur(img, img, Size(9, 9), 1);
    Canny(img, img, 100, 255);

    templ = imread("tmp.jpg", IMREAD_GRAYSCALE);
    GaussianBlur(templ, templ, Size(9, 9), 1);
    Canny(templ, templ, 190, 220);
    Mat imgc = img(Rect(124, 133, 180, 110));
    auto kernel = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));
    morphologyEx(imgc, imgc, MORPH_CLOSE, kernel);
    imshow("res", imgc);
    findContours(imgc, cnts, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    drawContours(img1, cnts, -1, Scalar(0, 255, 0));
    //adaptiveThreshold(img, img, 255, 0, 0, 19, 13);
    imshow("res", img1);
    //adaptiveThreshold(templ, templ, 255, 0, 0, 19, 13);

    imshow("Template", templ);
    if (img.empty() || templ.empty())
    {
        cout << "Can't read one of the images" << endl;
        return EXIT_FAILURE;
    }
    namedWindow(image_window, WINDOW_AUTOSIZE);
    //namedWindow(result_window, WINDOW_AUTOSIZE);
    //const char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
    //createTrackbar(trackbar_label, image_window, &match_method, max_Trackbar, MatchingMethod);
    //MatchingMethod();
    //MatchingMethod();
    //MatchingMethod();
    waitKey(0);
    return EXIT_SUCCESS;
}

