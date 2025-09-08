#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/cvconfig.h"

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	Mat edges, edgesC, edgesH;
	//img = imread("test.jpg");
	img = imread("image.jpg");
	GaussianBlur(img, img, Size(3, 3), 0);
	imshow("Оригинал", img);
	cvtColor(img, edges, CV_BGR2GRAY);
	imshow("ЧБ", edges);

	Canny(edges, edgesC, 50, 120);
	
	imshow("Canny", edgesC);
	waitKey();

	destroyAllWindows();
}
