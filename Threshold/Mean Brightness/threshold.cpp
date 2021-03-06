#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;


int MeanBrightness( Mat image)
{
  int nRows = image.rows;
  int nCols = image.cols;
  int image_size = nRows * nCols; //number of pixels
  int soma;
  for(int i = 0; i < image.rows; ++i)
  {
    for (int j = 0; j < image.cols; j++)
    {
      soma += image.at<uchar>(i,j); //getting the sum of all pixel values
    }
  }
  int value = soma/image_size; //get the mean of pixel values
  return value;
}


int main(int argc,const char** argv){
  Mat input_image = imread(argv[1], 1);
  Mat gray_image;
  Mat output;
  cvtColor(input_image,gray_image, COLOR_BGR2GRAY);
  int value = MeanBrightness(gray_image);
  threshold( gray_image, output, 100, 255, THRESH_BINARY);
  imshow("Original", input_image);
  imshow("Threshold", output);
  waitKey(0);
  return 0;
}

