#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

Mat image, gray, edged, kernel, closed;
vector<vector<Point>> cnts;
int main()
{
	image = imread("image.jpg");
	cvtColor(image, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, gray, Size(3, 3), 0);
	//adaptiveThreshold(gray, gray, 255, 0, 0, 199, 5);
	imwrite("gray.jpg", gray);
	imshow("gray", gray);
	Canny(gray, edged, 10, 200);
	imwrite("edged.jpg", edged);
	imshow("edged", edged);
	kernel = getStructuringElement(MORPH_RECT, Size(7, 7));
	morphologyEx(edged, closed, MORPH_CLOSE, kernel);
	imwrite("closed.jpg", closed);
	imshow("closed", closed);
	findContours(closed, cnts, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	int total = 0;
	vector<Point> approx;
	vector<vector<Point>> drawing;	
	for (auto &c : cnts)
	{
		double peri = arcLength(c, true);
		approxPolyDP(c, approx, 0.02 * peri, true);
		if (approx.size() == 4)
		{
			drawing.push_back(approx);
			total++;
		}
	}
	if (drawing.size() > 0) 
		drawContours(image, drawing, -1, Scalar(0, 255, 0), 4);
	cout << "Found " << total << " books in this image" << endl;
	imshow("result", image);
	imwrite("output.jpg", image);
	waitKey(0);
	destroyAllWindows();
	return 0;
}


/*
Мы нашли контуры объектов на изображениях. Однако, как вы видите, некоторые из контуров 
не закрыты — между контурами существуют промежутки. Чтобы убрать промежутки между белыми 
пикселями изображения, мы применим операцию «закрытия»:

Для каждого из контуров мы вычисляем периметр, используя cv2.arcLength, а затем аппроксимируем 
(сглаживаем) контур, используя cv2.approxPolyDP.
Причина, по которой мы аппроксимируем контур, заключается в том, что он может не быть идеальным 
прямоугольником. Из-за зашумления и теней на фото вероятность того, что у книги будет ровно 4 
вершины, невелика. Аппроксимируя контур, мы решаем эту проблему.

Наконец, мы проверяем, что у аппроксимируемого контура действительно четыре вершины. Если это так,
то мы рисуем контур вокруг книги, а затем увеличиваем счётчик общего количества книг.
*/