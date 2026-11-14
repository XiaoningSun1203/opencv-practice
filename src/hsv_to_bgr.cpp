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

void HSV2BGR(const cv::Mat& img,cv::Mat& bgr){
    int height=img.rows;
    int width=img.cols;
    int _H;//作为选择条件
    float h,s,v;
    float r=0,g=0,b=0;
    double _h;
    double _x;
    bgr.create(height, width, CV_8UC3);
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            h=(float)img.at<cv::Vec3b>(y,x)[0];
            s=(float)img.at<cv::Vec3b>(y,x)[1];
            v=(float)img.at<cv::Vec3b>(y,x)[2];
            _h=h/60;
            _H=h/60;
            _x=s*(1-abs(fmod(_h,2)-1));
        switch (_H) {
            case 0:
                    r=v;
                    g=v-s+_x;
                    b=v-s;
                    break;
            case 1:
                    r=v-s+_x;
                    g=v;
                    b=v-s;
                    break;
            case 2:
                    r=v-s;
                    g=v;
                    b=v-s+_x;
                    break;
            case 3:
                    r=v-s;
                    g=v-s+_x;
                    b=v;
                    break;
            case 4:
                    g=v-s;
                    r=v-s+_x;
                    b=v;
                    break;
            case 5:
                    g=v-s;
                    r=v;
                    b=v-s+x;
                    break;
                      }
            bgr.at<cv::Vec3b>(y,x)[0]=(uchar)(b*255);
            bgr.at<cv::Vec3b>(y,x)[1]=(uchar)(g*255);
            bgr.at<cv::Vec3b>(y,x)[2]=(uchar)(r*255);
        }
    }
}

int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);
    cv::Mat hsvimg=BGR2HSV(img);
    cv::Mat bgrimg;
    HSV2BGR(hsvimg,bgrimg);
    cv::imshow("answer3",bgrimg);
    cv::waitKey(0);
    return 0;
}
