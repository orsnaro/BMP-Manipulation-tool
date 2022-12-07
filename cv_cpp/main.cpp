#include <bits/stdc++.h>
#include "C:\opencv_cpp\opencv\build\include\opencv2\لاةحopencv.hpp"

using namespace cv;
int main(int argc, char** argv )
{

    Mat image;
    image = imread("C:/Users/kemik/OneDrive/Skrivebord/Images/lenna.png");
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}