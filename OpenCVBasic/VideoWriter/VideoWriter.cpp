#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
int main()
{
    setlocale(LC_ALL, "");
    Mat frame;
    VideoCapture cap(0);
    if (cap.isOpened())
    {
        cap.set(CAP_PROP_FRAME_WIDTH, 320);
        cap.set(CAP_PROP_FRAME_HEIGHT, 200);
        auto fps = 30; // cap.get(CAP_PROP_FPS);
        auto width = cap.get(CAP_PROP_FRAME_WIDTH);
        auto height = cap.get(CAP_PROP_FRAME_HEIGHT);
        int codec = VideoWriter::fourcc('X','V','I','D');
        VideoWriter writer("myvideo.avi", codec, fps, Size(width, height), true);
        if (writer.isOpened())
        {
            while (true)
            {
                bool success = cap.read(frame);
                if (success)
                {
                    writer.write(frame);
                    imshow("Video", frame);
                    if (waitKey(1000) == 27)
                        break;
                }
            }
            writer.release();
        }
        cap.release();
    }
}

