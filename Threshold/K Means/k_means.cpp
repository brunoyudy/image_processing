#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace cv;

int main()
{
    Mat input_image = imread("tooth.png", IMREAD_GRAYSCALE);
    Mat reshaped_image, output, gray_image, clustered;

    int nRows = input_image.rows;
    int nCols = input_image.cols;

    //cvtColor(input_image, gray_image, COLOR_BGR2GRAY);

    reshaped_image = input_image.reshape(1, nRows*nCols);
    Mat centers;
    std::vector<int> labels;

    reshaped_image.convertTo(reshaped_image,CV_32F);

    kmeans(reshaped_image, 2, labels, TermCriteria(TermCriteria::EPS+TermCriteria::COUNT, 10, 1.), 10, KMEANS_PP_CENTERS, centers);

    std::cout << labels.size() << std::endl;
    for (int i = 0; i < nRows*nCols; ++i)
    {
        if(labels[i] == 1)
        {
            input_image.at<uchar>(i) = 0;
        }
        else
        {
            input_image.at<uchar>(i) = 255;
        }
        
    }


    /*
    std::cout << "Labels Size1: " << labels.size() << std::endl;
    labels.resize(nRows, nCols);
    std::cout << "Labels resized: " << labels.size() << std::endl;

    for (int row = 0; row < nRows; ++row)
    {
        for (int col = 0; col < nCols; ++col)
        {
            if (labels[row, col] == 1)
            {
                //std::cout<<"1"<<std::endl;
                input_image.at<uchar>(row, col) = 0;
            }
            else
            {
                std::cout<<"0"<<std::endl;
                input_image.at<uchar>(row, col) = 0;
            }
        }
    }
    */
    
    std::cout<<"Labels size: "<< labels.size() << std::endl;
    output = reshaped_image.reshape(0, nRows);
    std::cout<<"Reshaped size: "<< output.size() << std::endl;

    //reshaped_image.convertTo(reshaped_image, 0);
    //output = reshaped_image.reshape(nRows, nCols);

    imshow("Original", input_image);
    waitKey(0); 
}