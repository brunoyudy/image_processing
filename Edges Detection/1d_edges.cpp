#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <opencv2/features2d.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

using namespace cv;
using namespace std;

vector<int> get_distance(int x1, int x2, int y1, int y2)
{
    vector<int> distance;
    distance.push_back(x1 - x2);
    distance.push_back(y1 - y2);
    return distance;
}

vector<int> get_gradients(vector<int> pixel_values)
{
    vector<int> output;
    for (int i = 0; i < pixel_values.size(); i++)
    {
        int gradient = (int)pixel_values[i+1] - (int) pixel_values[i-1];
        output.push_back(gradient);
    }
    return output;
}

vector<vector<int>> get_neighbor(vector<vector<int> > sorted_vector, vector<vector<int> > pos)
{
    int counter = 0;
    for (int j = 0; j < pos.size() - 2; j++)
    {
        vector<int> value = sorted_vector.back();
        for (int i = 0; i < pos.size(); i++)
        {
            int distance1 = abs(value[0] - pos[i][0]);
            int distance2 = abs(value[1] - pos[i][1]);

            vector<int> distance = get_distance(value[0], pos[i][0], value[1], pos[i][1]);
            if(distance1 <= 1 && distance2 <= 1)
            {
                vector<int> pos1;
                pos1.push_back(pos[i][0]);
                pos1.push_back(pos[i][1]);
                //cout << pos1[0] << ' ';
                //cout << pos1[1] << endl;
                if (find(sorted_vector.begin(), sorted_vector.end(), pos1) != sorted_vector.end())
                {}
                else
                {
                    sorted_vector.push_back(pos1);
                }
            }
        }
    }
    return sorted_vector;
}


int main(int argc, const char** argv)
{
    Mat binary, canny_out, output;
    Mat input_image = imread(argv[1], 0);
    threshold(input_image, binary, 127, 255, THRESH_BINARY_INV);
    cvtColor(binary, output, COLOR_GRAY2BGR);
    Canny(binary, canny_out, 100, 300);
    vector< vector<Point> > contours;
    findContours(canny_out, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
    vector< vector<Point> > contours_poly(contours.size());
    vector< Point2f > centers(contours.size());
    vector< float > radius (contours.size());
    for (size_t i = 0; i < contours.size(); i++)
    {
        approxPolyDP(contours[i], contours_poly[i], 0, true);
        minEnclosingCircle(contours_poly[i], centers[i], radius[i]);
    }
    Mat drawing = Mat::zeros(canny_out.size(), CV_8U);
    for (size_t i = 0; i < contours.size(); i++)
    {
        if(radius[i] >= 80)
        {
        radius[i] -= 12;
        circle(drawing, centers[i], (int) radius[i], 100, 0);
        }
    }
    vector<int> coord;
    vector< vector<int> > pos;
    std::cout << "Cols " << drawing.cols << std::endl;
    std::cout << "Rows " << drawing.rows << std::endl;
    for (int row = 0; row < drawing.rows; row++)
    {
        for (int col = 0; col < drawing.cols; col++)
        {
            //cout << "Row: " << row << ", Col: " << col << std::endl;
            if(drawing.at<uchar> (row, col) == 100)
            {
                coord.push_back(row);
                coord.push_back(col);
                //std::cout <<"row: " << row;
                //std::cout << " col: " << col << std::endl;
                pos.push_back(coord);
                coord.clear();
            }
        }
    }

    vector<vector<int> > sorted_pixels;
    sorted_pixels.push_back(pos[0]);
    vector<vector<int> > sorted_vector = get_neighbor(sorted_pixels, pos);
    vector<int> pixel_values;
    for (int i = 0; i < sorted_vector.size(); i++)
    {
        int value = binary.at<uchar> (sorted_vector[i][0], sorted_vector[i][1]);
        cout << value << endl;
        pixel_values.push_back(value);
    }
    vector<int> gradients = get_gradients(pixel_values);

    for (int k = 0; k < gradients.size(); k++)
    {
        if(gradients[k] != 0)
        {
            Point center;
            center.x = sorted_vector[k][1]; 
            center.y = sorted_vector[k][0];
            circle(binary, center, 1, 127, 4 );
        }
    }

    std::cout<< "sorted vector size " << sorted_vector.size()<<std::endl;
    namedWindow("Contours", WINDOW_NORMAL);
    namedWindow("Output", WINDOW_NORMAL);
    //std::cout << pos.size() << std::endl;
    //imshow("Canny", canny_out);
    imshow("Contours", drawing);
    imshow("Output", binary);
    waitKey(0);
}