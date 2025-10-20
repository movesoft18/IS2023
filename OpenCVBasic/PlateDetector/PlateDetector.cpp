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
	CascadeClassifier cascade;
	vector<Rect> faces;
	Mat img =  imread("2.jpg");
	if (!cascade.load("C:\\openCV\\build\\etc\\haarcascades\\haarcascade_russian_plate_number.xml"))
		return 1;

	cascade.detectMultiScale(img, faces, 1.05, 3, 0, Size(10, 5), Size(300, 150));
	for (auto& face : faces)
	{
		rectangle(img, face, Scalar(255, 30, 0), 2);
	}
	imshow("Faces", img);
	waitKey(0);
	destroyAllWindows();
}