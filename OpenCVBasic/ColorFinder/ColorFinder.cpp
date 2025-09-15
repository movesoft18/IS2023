/*Стандартный прием в OpenCV для решения поставленной задачи складывается из двух 
этапов. На первом этапе мы применяем цветовой фильтр и превращаем каждый кадр в 
черно - белую картинку.После наложения фильтра объект заданного цвета превращается
в белое пятно, а всё остальное заливается черным цветом.
На следующем этапе мы используем алгоритм вычисления моментов. Момент 
изображения — это суммарная характеристика пятна, представляющая собой сумму всех 
точек (пикселей) этого пятна. При этом, имеется множество подвидов моментов, 
характеризующие разные свойства изображения.

Например, момент нулевого порядка m00 — это количество всех точек, составляющих 
пятно. Момент первого порядка m10 представляет собой сумму X координат точек, 
а m01 — сумму Y координат. Имеются также моменты m11, m20, m02, m22 и т.д.
Формула для вычисления моментов очень проста, и мы можем посчитать пиксели вручную. 
Воспользуемся стандартной функцией для вычисления моментов кадра:

moments( кадр, двоичный )

Аргумент кадр представляет собой нашу предобработанную картинку. 
Аргумент двоичный определяет то, как алгоритм будет вычислять вес каждой точки. 
Напомню, что предыдущий метод inRange дал нам черно-белую картинку, в которой 
пиксели могут быть черными, белыми, а могут быть и серыми. Так вот, если аргумент 
двоичный равен 1, то вес всех точек с цветом, отличным от нуля будет равен единице. 
В противном случае, вес черной точки будет равен 0, а белой точки — 255.
Функция moments вернет нам массив моментов вплоть до третьего порядка. 
Но для вычисления координат центра пятна нам потребуются только моменты первого 
порядка m01 и m10, а также момент m00.
Чтобы получить координаты X и Y искомого пятна, нам следует поделить полученные 
моменты m10 и m01 на нулевой момент m00. Таким образом мы найдем средние координаты 
X и Y всех точек, а это и есть центр пятна.

x = dM10 / dArea
y = dM01 / dArea
*/

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	char mainWindow[] = "Main";
	char trackbarWindow[] = "Trackbar";
	char sizeWindow[] = "Size";
	char thresholdWindow[] = "Threshold";
	int min = 0, max = 10000;
	int hmin = 0, smin = 0, vmin = 0,
		hmax = 180, smax = 255, vmax = 255,
		x = 0, y = 0;
	Mat frame, HSV, threshold, blurred;
	namedWindow(trackbarWindow);
	namedWindow(thresholdWindow);
	namedWindow(mainWindow);
	namedWindow(sizeWindow);
	VideoCapture capture;
	createTrackbar("H min:", trackbarWindow, &hmin, hmax);
	createTrackbar("H max:", trackbarWindow, &hmax, hmax);
	createTrackbar("S min:", trackbarWindow, &smin, smax);
	createTrackbar("S max:", trackbarWindow, &smax, smax);
	createTrackbar("V min:", trackbarWindow, &vmin, vmax);
	createTrackbar("V max:", trackbarWindow, &vmax, vmax);
	createTrackbar("Size min:", sizeWindow, &min, max);
	createTrackbar("Size max:", sizeWindow, &max, max);

	capture.open(0);
	if (!capture.isOpened()) {
		cout << "Камера не может быть открыта." << endl;
		return 1;
	}

	for (;;) {
		capture >> frame;

		cvtColor(frame, HSV, COLOR_BGR2HSV);

		//medianBlur(HSV, blurred, 21);
		inRange(HSV, Scalar(hmin, smin, vmin), Scalar(hmax, smax, vmax), threshold);
		//medianBlur(threshold, threshold, 9);
		Moments mom = moments(threshold, true);
		double dM01 = mom.m01; 
		double dM10 = mom.m10;
		double dArea = mom.m00;
		//будем реагировать только на те моменты,
		//которые содержать больше заданного кол-ва пикселей
		if (dArea >= min && dArea < max)
		{
			x = dM10 / dArea;
			y = dM01 / dArea;
			circle(frame, Point(x, y), 10, Scalar(0, 0, 255), -1);
		}
		imshow(mainWindow, frame);
		imshow(thresholdWindow, threshold);
		if (waitKey(1) == 27) break;
	}
	capture.release();
	destroyAllWindows();
}

