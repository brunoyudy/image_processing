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