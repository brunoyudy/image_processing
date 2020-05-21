#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <vector>
using namespace cv;
using namespace std;

Mat preprocessing(Mat image)
{
    Mat pixel_values = image.reshape(1, image.rows*image.cols);
    return pixel_values;
}

vector<int> get_number_of_pixels(Mat image)
{
    vector<int> number_of_pixels;

    for (int value = 0; value < 256; value ++)
    {
        int counter = 0;
        for(int i = 0; i < image.rows; ++i)
        {
            for (int j = 0; j < image.cols; j++)
            {
                if( image.at<uchar>(i,j) == value)
                {
                    counter++;
                }

            }
        }
        number_of_pixels.push_back(counter);
    }
    return number_of_pixels;
}

int compute_mean(vector<int> lista)
{
    int soma = 0;
    for ( int i = 0; i < lista.size(); i++)
    {
        soma += lista[i];
    }
    float mean = soma/lista.size();
}

template<typename T>
vector<T> slice(vector<T> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    vector<T> vec(first, last);
    return vec;
}

vector<int> smoothing( vector<int> number_of_pixels, int number_of_bins)
{
    vector<int> smoothed_values;
    int values_per_interval = 256/number_of_bins;

    for (int i = 0; i < number_of_bins; i++)
    {
        int first = i*values_per_interval;
        int last = (i+1)*values_per_interval;
        vector<int> sliced_vector = slice(number_of_pixels, first, last);
        smoothed_values.push_back(compute_mean(sliced_vector));
    }
    return smoothed_values;
}

vector<int> get_peaks(vector<int> smoothed_values)
{
    vector<int> peaks;
    for (int i = 0; i < smoothed_values.size(); i++)
    {
        if (i == 0 or i == smoothed_values.size() - 1)
        {
            if (i == 0)
            {
                if ( smoothed_values[i] > smoothed_values[i+1])
                {
                    peaks.push_back(i);
                }
            }
            else
            {
                if( smoothed_values[i] > smoothed_values[i - 1] )
                {
                    peaks.push_back(i);
                }
            }
        }
        else
        {
            if ( smoothed_values[i] > smoothed_values[i - 1] && smoothed_values[i] > smoothed_values[i + 1] )
            {
                peaks.push_back(i);
            }
        }
        
    }
    return peaks;
}

void thresholding(Mat image)
{
    Mat output;
    Mat pixel_values = preprocessing(image);
    vector<int> peaks;
    vector<int> number_of_pixels = get_number_of_pixels(pixel_values);
    vector<int> possible_number_of_bins = {256, 128, 64, 32, 16, 8, 4, 2};
    int values_per_interval;
    for (int i = 0; i < possible_number_of_bins.size(); i++)
    {
        vector<int> smoothed_values = smoothing(number_of_pixels, possible_number_of_bins[i]);
        values_per_interval = 256/possible_number_of_bins[i];
        peaks = get_peaks(smoothed_values);
        if (peaks.size() == 2)
        {
            break;
        }
    }
    int threshold_value = (peaks[0] + peaks[1])*values_per_interval / 2;
    cout << threshold_value << endl;
    threshold(image, output, threshold_value, 255, THRESH_BINARY);
    imshow("Original", image);
    imshow("Output", output);
    waitKey(0);
}


int main(int argc, const char** argv)
{
    Mat input_image = imread(argv[1], IMREAD_GRAYSCALE);
    thresholding(input_image);
    return 0;
}
