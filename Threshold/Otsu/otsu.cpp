#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using std::cout;

int main(int argc, const char** argv)
{
    Mat input_image = imread(argv[1], IMREAD_GRAYSCALE);
    Mat output;
    threshold(input_image, output, 0, 255, THRESH_OTSU);
    imshow("Original", input_image);
    imshow("Otsu", output);
    waitKey(0);
}
