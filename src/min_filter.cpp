#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

  //最小值滤波器
void BGR2GRAY(cv::Mat& img,cv::Mat& result){
    int height=img.rows;
    int width=img.cols;
    result.create(height,width,img.type());

    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            result.at<uchar>(j,i)=0.0722*img.at<cv::Vec3b>(j,i)[0]+0.7152*img.at<cv::Vec3b>(j,i)[1]+0.2126*img.at<cv::Vec3b>(j,i)[2];
        }
    }
}
void min_filter(cv::Mat& img,cv::Mat&result,int kernel_size){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height,width,CV_8UC1);

    int pad=floor(kernel_size/2);
    int value=0;
    int vmin=255;
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            for (int c=0; c<channel; c++) {
                vmin=255;
                for (int dy=-pad; dy<pad+1; dy++) {
                    for (int dx=-pad; dx<pad+1; dx++) {
                        value=img.at<cv::Vec3b>(j+dy,i+dx)[c];
                        if (value<vmin) {
                            vmin=value;
                        }
                    }
                }
                result.at<cv::Vec3b>(j,i)[c]=(uchar)vmin;
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img2=cv::imread("//Users//sunxiaoning//Desktop//circuitboard-salt的副本.tif",cv::IMREAD_COLOR);
    cv::Mat gray;
    cv::Mat out;
    BGR2GRAY(img2,gray);
    min_filter(gray, out, 3);
    cv::imshow("min_filter result",out);
    cv::waitKey(0);
    return 0;
}
