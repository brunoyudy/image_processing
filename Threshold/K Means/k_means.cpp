#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace cv;

int main(int argc,const char** argv)
{
    Mat reshaped_image, output;
    Mat input_image = imread(argv[1], IMREAD_GRAYSCALE);
    output = imread(argv[1], IMREAD_GRAYSCALE);

    int nRows = input_image.rows;
    int nCols = input_image.cols;

    reshaped_image = input_image.reshape(1, nRows*nCols); //reshape to get 1 feature, the pixel value
    Mat centers;
    std::vector<int> labels;

    reshaped_image.convertTo(reshaped_image,CV_32F); //converting to the format using by kmeans

    kmeans(reshaped_image, 2, labels, TermCriteria(TermCriteria::EPS+TermCriteria::COUNT, 10, 1.), 10, KMEANS_PP_CENTERS, centers);

    for (int i = 0; i < nRows*nCols; ++i)
    {
        if(labels[i] == 1)
        {
            output.at<uchar>(i) = 0; //manual thresholding
        }
        else
        {
            output.at<uchar>(i) = 255; //manual thresholding
        }
        
    }

    imshow("Original", input_image);
    imshow("KMeans", output);
    waitKey(0); 
}
