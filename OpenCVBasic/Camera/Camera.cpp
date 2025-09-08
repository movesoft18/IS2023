#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/cvconfig.h"

using namespace cv;
using namespace std;

int main()
{
	Mat frame;
	VideoCapture capture(0);
	//capture.set(CAP_PROP_FRAME_WIDTH, 320);
	//capture.set(CAP_PROP_FRAME_HEIGHT, 200);
	//capture.open(0);
	capture.set(CAP_PROP_FPS, 10);
	auto w = capture.get(CAP_PROP_FRAME_WIDTH);
	auto h = capture.get(CAP_PROP_FRAME_HEIGHT);
	auto fps = capture.get(CAP_PROP_FPS);
	cout << w << " " << h << " " << fps << endl;
	if (capture.isOpened())
	{
		while (true)
		{
			//capture >> frame;
			auto res = capture.read(frame);
			if (/*frame.empty()*/!res) break;
			imshow("Live video", frame);
			auto key = waitKey(1);
			if (key == 27) break;
		}
		capture.release();
	}
	destroyAllWindows();
}
