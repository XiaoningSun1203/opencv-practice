#include<iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

//交换通道
cv::Mat channel_swap(cv::Mat img){
    int x,y;
    int width=img.cols;
    int height=img.rows;
    cv::Mat out=cv::Mat::zeros(height,width,CV_8UC3);
    for (y=0; y<height; y++) {
        for (x=0; x<width; x++) {
            out.at<cv::Vec3b>(y,x)[0]=img.at<cv::Vec3b>(y,x)[2];
            out.at<cv::Vec3b>(y,x)[1]=img.at<cv::Vec3b>(y,x)[0];
            out.at<cv::Vec3b>(y,x)[2]=img.at<cv::Vec3b>(y,x)[1];
        }
    }
    return out;
}
int main(int argc,const char*argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);
    cv::Mat out=channel_swap(img);

    cv::imshow("sample",out);
    cv::waitKey(0);
    return 0;
}
