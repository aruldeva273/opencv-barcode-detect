#include  <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat img = imread("C:\\Users\\lenova\\Documents\\HIROTEC\\filescpp\\OIP (2).jpg");
    if (img.empty())
        return -1;

    Mat gray, reduced_h;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    gray = gray > 127;
    Mat kernel(5, 1, CV_8U, Scalar(1));
    erode(gray, gray, kernel,Point(-1,-1),4);

    reduce(gray, reduced_h, 0, REDUCE_AVG);

    Mat reduced_h_graph = img.clone();
    copyMakeBorder(reduced_h_graph, reduced_h_graph, 0, 100, 0, 0,BORDER_CONSTANT,Scalar(0,0,0));

    for (int i = 0; i < img.cols; i++)
    {
        if (reduced_h.at<uchar>(0, i) > 150)
        line(reduced_h_graph, Point(i, reduced_h_graph.rows-101), Point(i, reduced_h_graph.rows), Scalar(255, 255, 255), 1);
    }

    imshow("reduced_h_graph", reduced_h_graph);
    waitKey(0);
    return 0;
}