
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);
	CascadeClassifier cascade;
	vector<Rect> faces;
	Mat img;
	if (!cascade.load("C:\\openCV\\build\\etc\\haarcascades\\haarcascade_frontalface_alt2.xml"))
		return 1;
	while (true)
	{
		auto ret = cap.read(img);
		if (!ret) break;
		cascade.detectMultiScale(img, faces, 1.3, 1, 0, Size(10,10), Size(150,150));
		for (auto& face : faces)
		{
			rectangle(img, face, Scalar(255, 30, 0), 2);
		}
		imshow("Faces", img);
		if (waitKey(1) == 27) break;
	}
	cap.release();
	destroyAllWindows();
}