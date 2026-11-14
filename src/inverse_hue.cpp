#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<math.h>

  //HSV变换：未实现
// 下列 BGR2HSV 是原文件原样复用的输入准备函数。
cv::Mat BGR2HSV(cv::Mat img){
    float r,g,b;
    float h=0,s=0,v=0;
    float _max,_min;
    int height=img.rows;
    int width=img.cols;
    cv::Mat hsv(height, width, CV_32FC3);
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            r=(float)img.at<cv::Vec3b>(y,x)[2]/255;
            g=(float)img.at<cv::Vec3b>(y,x)[1]/255;
            b=(float)img.at<cv::Vec3b>(y,x)[0]/255;
            _max=fmax(r,fmax(g,b));
            _min=fmin(r,fmin(g,b));
            if (_min==_max) {
                h=0;
            }else if(_min==b){
                h=60*(g-r)/(_max-_min)+60;
            }else if(_min==r){
                h=60*(b-g)/(_max-_min)+180;
            }else if(_min==g){
                h=60*(r-b)/(_max-_min)+300;
            }
            s=_max-_min;
            v=_max;
            hsv.at<cv::Vec3f>(y,x)[0]=h;
            hsv.at<cv::Vec3f>(y,x)[1]=s;
            hsv.at<cv::Vec3f>(y,x)[2]=v;
        }
    }
    return hsv;
}

cv::Mat inverse_hue(cv::Mat& hsv){
    int height=hsv.rows;
    int width=hsv.cols;
    cv::Mat inverse_hsv=cv::Mat::zeros(height, width, CV_32FC3);
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            inverse_hsv.at<cv::Vec3f>(y,x)[0]=fmod(hsv.at<cv::Vec3f>(y,x)[0]+180, 360);
        }
    }
    return inverse_hsv;
}

int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);
    cv::Mat hsvimg=BGR2HSV(img);
    cv::Mat inverse_hsv=inverse_hue(hsvimg);
    cv::imshow("answer2",inverse_hsv);
    cv::waitKey(0);
    return 0;
}
