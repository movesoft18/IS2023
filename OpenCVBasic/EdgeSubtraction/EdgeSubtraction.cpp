#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void RecordVideo()
{
	Mat image, gray, edges, dst;
	VideoCapture capture(0);
	auto width = capture.get(CAP_PROP_FRAME_WIDTH);
	auto height = capture.get(CAP_PROP_FRAME_HEIGHT);
	int codec = VideoWriter::fourcc('X', 'V', 'I', 'D');
	VideoWriter writer("myvideo.avi", codec, 30, Size(width, height), true);
	if (capture.isOpened() && writer.isOpened())
	{
		while (true)
		{
			if (waitKey(10)==27) break;
			capture >> image;
			if (image.empty())
			{
				break;
			}
			imshow("Original", image);
			cvtColor(image, gray, COLOR_BGR2GRAY);
			Canny(gray, edges, 50, 100);
			cvtColor(edges, edges, COLOR_GRAY2BGR);
			subtract(image, edges, dst);
			imshow("Result", dst);
			writer.write(dst);
		}

	}
	capture.release();
	writer.release();
	destroyAllWindows();
}

int main()

{
	/*
	Mat image, gray, edges, dst;
	image = imread("director.jpg");
	imshow("Original", image);
	cvtColor(image, gray, COLOR_BGR2GRAY);
	Canny(gray, edges, 200, 250);
	imshow("Edges", edges);
	cvtColor(edges, edges, COLOR_GRAY2BGR);
	subtract(image, edges, dst);
	imshow("Result", dst);
	*/
	RecordVideo();
	waitKey();
	destroyAllWindows();
}

