#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>
#include <windows.h>
#include <string.h>
#include <cstring>
#include <bits.h>
#include<atlstr.h>
#include<stdio.h>
#include<conio.h>
//#include<stdc++.h>
using namespace cv;
using namespace std;
int closehandel = 0;
int main()
{
    double area_red = 0, area_blue = 0, area_green = 0;
    Mat image1, image2;
    VideoCapture cap(0);
    while (1)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty())
            break;
        imshow("frame", frame);
        Rect RectangleToDraw((frame.rows / 2) - 100, (frame.cols / 2) - 100, 200, 200);
        rectangle(frame, RectangleToDraw.tl(), RectangleToDraw.br(), Scalar(0, 0, 255), 2, 8, 0);
        imshow("DrawRectangle", frame);
        cv::Mat image = frame(RectangleToDraw);
        image.copyTo(image1);
        char c = (char)waitKey(25);
        //if (c = 27)
        //break;
        //waitKey(25);
        if (c == 97)
            break;
    }
    image1.copyTo(image2);
    Mat image3,image4,bin_;
    imshow("image2",image2);
    inRange(image2, Scalar(30, 28, 116), Scalar(75, 112, 255), image3);
    bitwise_and(image2, image2, image4, image3);
    imshow("red", image4);
    Canny(image4, bin_, 150.0, 200.0, 3);
    vector<vector<Point>> countours;
    vector<Vec4i> hierarchy;
    RNG rng(12345);
    findContours(bin_, countours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
    for (int i = 0; i < countours.size(); i++)
    {
        double area = contourArea(countours[i]);
        area_red += area;
        //cout << "area" << area;
        //printf("area: %lf\n", area);

    }
    Mat image5, image6, bin__;
    inRange(image2, Scalar(115, 104, 28), Scalar(255, 244, 74), image5);
    bitwise_and(image2, image2, image6, image5);
    imshow("blue", image6);
    Canny(image6, bin__, 150.0, 200.0, 3);
    //imshow("vatsa", bin__);
    vector<vector<Point>> countours1;
    vector<Vec4i> hierarchy1;
    RNG rng1(12345);
    findContours(bin__, countours1, hierarchy1, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
    for (int i = 0; i < countours1.size(); i++)
    {
        double area1 = contourArea(countours1[i]);
        area_blue += area1;
        //cout << "area1" << area1;
        //printf("area1: %lf\n", area1);

    }
    Mat image7,image8, bin___;
    inRange(image2, Scalar(28, 115, 33), Scalar(74, 255, 110), image7);
    bitwise_and(image2, image2, image8, image7);
    imshow("green", image8);
    Canny(image8, bin___, 150.0, 200.0, 3);
    //imshow("vatsa", bin___);
    vector<vector<Point>> countours2;
    vector<Vec4i> hierarchy2;
    RNG rng2(12345);
    findContours(bin___, countours2, hierarchy2, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
    for (int i = 0; i < countours2.size(); i++)
    {
        double area2 = contourArea(countours2[i]);
        area_green += area2;
        //cout << "area2" << area2;
        //printf("area2: %lf\n", area2);

    }
    printf("area_red=%lf ,area_blue=%lf ,area_green=%lf\n", area_red, area_blue, area_green);
    output=maximum(area_red, area_blue, area_green);
    printf("%c", output);

    waitKey(0);
}