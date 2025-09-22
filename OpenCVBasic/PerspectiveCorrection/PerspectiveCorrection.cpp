#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img, corrected;
	img = imread("image.jpg");
	imshow("Original", img);
	const Point2f source[]{
		Point2f(173, 44),
		Point2f(67, 835),
		Point2f(669, 835),
		Point2f(595, 42),
	};
	const Point2f dest[]{
		Point2f(67, 44),
		//Point2f(7, 44),
		Point2f(67, 835),
		Point2f(669, 835),
		Point2f(669, 42),
		//Point2f(770, 42),
	};
	Mat matrix = getPerspectiveTransform(source, dest);
	warpPerspective(img, corrected, matrix, img.size());
	imshow("Corrected", corrected);
	waitKey();
	destroyAllWindows();
}

