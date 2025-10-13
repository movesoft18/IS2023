#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

constexpr int thresh = 100;

int main()
{
	Mat frame1, frame2, gray, bin, diff;
	VideoCapture capture(0);
	auto w = capture.get(CAP_PROP_FRAME_WIDTH);
	auto h = capture.get(CAP_PROP_FRAME_HEIGHT);
	capture >> frame1;
	cvtColor(frame1, frame1, COLOR_BGR2GRAY);
	threshold(frame1, frame1, 0, 255, THRESH_OTSU);
	resize(frame1, frame1, Size(80, 60));
	namedWindow("Difference");
	resizeWindow("Difference", 200, 200);
	if (capture.isOpened())
	{
		while (true)
		{
			auto res = capture.read(frame2);
			if (!res) break;
			imshow("Original", frame2);
			cvtColor(frame2, gray, COLOR_BGR2GRAY);
			threshold(gray, bin, 0, 255, THRESH_OTSU);
			resize(bin, bin, Size(80, 60));
			absdiff(bin, frame1, diff);
			Moments m = moments(diff, true);
			auto pixelsDiff = m.m00;
			if (pixelsDiff > thresh)
			{
				cout << "Alarm !!!\n";
			}
			cout << pixelsDiff << endl;
			imshow("Difference", diff);
			auto key = waitKey(200);
			if (key == 27) break;
			bin.copyTo(frame1);
		}
		capture.release();
	}
	destroyAllWindows();

}
