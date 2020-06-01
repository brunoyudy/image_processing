#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <opencv2/features2d.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using std::cout;
using std::endl;

Mat kmeans(Mat input_image)
{
    Mat output, reshaped_image;
    cvtColor(input_image, output, COLOR_BGR2GRAY);
    int nRows = input_image.rows;
    int nCols = input_image.cols;
    reshaped_image = input_image.reshape(3, nRows*nCols); //reshape to get 1 feature, the pixel value
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
    return output;
}



Mat Blobs(Mat image,int minThresh,int maxThresh, int minArea,int maxArea,int minCirc,int maxCirc,int minConvex,int maxConvex ,int minInertia,int maxInertia)
{
    SimpleBlobDetector::Params params;
    params.minThreshold = minThresh;
    params.maxThreshold = maxThresh;
    params.filterByArea = true;
    params.minArea = minArea;
    params.maxArea = maxArea;
    params.filterByCircularity = true;
    params.minCircularity = minCirc/100;
    params.maxCircularity = maxCirc/100;
    params.filterByConvexity = true;
    params.minConvexity = minConvex/100;
    params.maxConvexity = maxConvex/100;
    params.filterByInertia = true;
    params.minInertiaRatio = minInertia/100;
    params.maxInertiaRatio = maxInertia/100;
    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    std::vector<KeyPoint> keypoints;
    detector->detect( image, keypoints );
    Mat output;
    drawKeypoints(image, keypoints, output, Scalar(255,0,0), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    //cout << keypoints.size() << " Objects Detected." << endl;
    return output;
}

int main(int argc, const char** argv)
{
    Mat input_image = imread(argv[1], 1);
    Mat binary_image = kmeans(input_image);

    namedWindow("My Window", 1);
    int minThreshold = 0;
    int maxThreshold = 0;
    int minCirc = 0;
    int maxCirc = 0;
    int minConvex = 0;
    int maxConvex = 0;
    int minInertia = 0;
    int maxInertia = 0;
    int minArea = 0;
    int maxArea = 0;


    while(true)
    {
        createTrackbar("Min Threshold", "My Window", &minThreshold, 255);
        createTrackbar("Max Threshold", "My Window", &maxThreshold, 255);
        createTrackbar("Min Circularity", "My Window", &minCirc, 100);
        createTrackbar("Max Circularity", "My Window", &maxCirc, 100);
        createTrackbar("Min Convexity" , "My Window" , &minConvex, 100);
        createTrackbar("Max Convexity", "My Window" , &maxConvex, 100);
        createTrackbar("Min Inertia", "My Window", &minInertia, 100);
        createTrackbar("Max Inertia", "My Window", &maxInertia, 100);
        createTrackbar("Min Area", "My Window", &minArea, 5000);
        createTrackbar("Max Area", "My Window", &maxArea, 5000);
        Mat output = Blobs(binary_image, minThreshold, maxThreshold, minArea, maxArea, minCirc, maxCirc, minConvex, maxConvex, minInertia, maxInertia);
        imshow("Input", input_image);
        imshow("Output", output);
        int iKey = waitKey(50);
        if(iKey==27)
        {
            break;
        }
    }
    return 0;
}