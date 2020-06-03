#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;

Mat src, src_gray, auxiliar;
Mat dst, detected_edges;

int lowThreshold = 0;
int thresh_value = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;
const char* window_name = "Edge Map";

static void CannyThreshold(int, void*)
{
    threshold( src_gray, auxiliar, thresh_value, 255, 2 );
    blur(auxiliar, detected_edges, Size(3,3));
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
    dst = Scalar::all(0);
    src.copyTo(dst, detected_edges);
    namedWindow(window_name, WINDOW_NORMAL);
    imshow(window_name, detected_edges);
}

int main(int argc, char** argv)
{
    src = imread(argv[1], 1);
    dst.create(src.size(), src.type());
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    namedWindow(window_name, WINDOW_NORMAL);
    createTrackbar("Threshold Value: ", window_name, &thresh_value, 255, CannyThreshold);
    createTrackbar("Canny Min Value: ", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);
    CannyThreshold(0,0);
    waitKey(0);
    return 0;
}