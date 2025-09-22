#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img, rotated;
	img = imread("image.jpg");
	imshow("Original", img);
	Point center = Point2d(img.cols / 2, img.rows / 2);
	double angle = 1;
	while (true)
	{
		Mat matrix = getRotationMatrix2D(center, angle+=0.5, 1);
		warpAffine(img, rotated, matrix, Size(img.cols, img.rows));
		imshow("Rotated", rotated);
		if (waitKey(1) == 27) break;
	}
	waitKey();
	destroyAllWindows();
}

