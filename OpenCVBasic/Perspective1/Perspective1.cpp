#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

struct Coords
{
    int stage = 0;
    Point2f source[4];
    Mat* drawing;
};

void startWarpPerspective(
    const cv::Mat& image,
    const Point2f sourcePoints[],
    const Point2f destPoints[],
    cv::Mat& out
)
{
    cv::Mat transformMatrix;
    transformMatrix = cv::getPerspectiveTransform(
        sourcePoints,
        destPoints
    );
    cv::warpPerspective(
        image, out, transformMatrix,
        image.size()
    );
}

void onMouse(
    int event,
    int x, int y,
    int flags,
    void* userData = nullptr
)
{
    Coords* c = static_cast<Coords*>(userData);
    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        if (c->stage > 3) break;
        c->source[c->stage] = Point2f(x, y);
        c->stage++;
        circle(*(c->drawing), Point(x, y),
            3, Scalar(0, 0, 255), -1);
        break;
    /*case EVENT_MOUSEMOVE:
        circle(*(c->drawing), Point(x, y),
            3, Scalar(0, 255, 255), -1);
        break;
        */
    }
}

int main()
{
    
    setlocale(LC_ALL, "");
    Mat image, tmp, edited;

    Coords coords{
        0,
        Point2f(0,0),
        Point2f(0,0),
        Point2f(0,0),
        Point2f(0,0),
        &tmp,
    };
    Point2f source[4], dest[4];


    image = imread("checkers.jpg");
    tmp = image.clone();
    imshow("Original", tmp);
    setMouseCallback("Original", onMouse, &coords);
    cout << "Выберите угловые точки исходного объекта на изображении\n";
    while (coords.stage < 4)
    {
        waitKey(2);
        imshow("Original", tmp);
    }
    for (int i = 0; i < 4; i++)
    {
        cout << "x=" << coords.source[i].x <<
            " y=" << coords.source[i].y << endl;
        source[i] = coords.source[i];
    }
    tmp = image.clone();
    coords.stage = 0;
    cout << "Выберите угловые точки прямоугольника на результирующем изображении\n";
    while (coords.stage < 4)
    {
        waitKey(200);
        imshow("Original", tmp);
    }
    for (int i = 0; i < 4; i++)
    {
        cout << "x=" << coords.source[i].x <<
            " y=" << coords.source[i].y << endl;
        dest[i] = coords.source[i];
    }
    startWarpPerspective(image, source, dest, edited);
    imshow("Corrected image", edited);
    waitKey();
    destroyAllWindows();
}
