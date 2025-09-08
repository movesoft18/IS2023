#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/cvconfig.h"

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	Mat edges, edgesC, edgesH;
	namedWindow("Порог1");
	namedWindow("Порог2");
	int t1min = 0, t1max = 255;
	int t2min = 0, t2max = 255;
	createTrackbar("T1:", "Порог1", &t1min, t1max);
	//createTrackbar("T1 max:", "Порог1", &t1max, t1max);
	//createTrackbar("T2 min:", "Порог2", &t2min, t2max);
	createTrackbar("T2:", "Порог2", &t1max, t1max);

	VideoCapture cap(0);
	cap.set(CAP_PROP_FRAME_WIDTH, 640);
	cap.set(CAP_PROP_FRAME_HEIGHT, 480);
	cout << cap.get(CAP_PROP_FRAME_WIDTH) << " " << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;
	while (true)
	{
		cap >> img;
		//img = imread("test.jpg");
		imshow("Оригинал", img);
		cvtColor(img, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(29, 29), 0);
		imshow("ЧБ", edges);

		Canny(edges, edgesC, t1min, t1max);
	
		imshow("Canny", edgesC);
		auto c = waitKey(10);
		if (c == 27) break;
	}
	return 0;
	cap.release();
	destroyAllWindows();
}
