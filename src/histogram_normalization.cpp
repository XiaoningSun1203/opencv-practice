#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <cmath>

  //直方图归一化
void his_normal(cv::Mat& img,cv::Mat& result,int min,int max){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height,width,img.type());

    int _min=255,_max=0;//原图中的最小、最大灰度值
    int value;
    for (int j=0; j<height; j++) {//获得原图的最大灰度值、最小灰度值
        for (int i=0; i<width; i++) {
            for (int c=0; c<channel; c++) {
                _min=fmin(_min,img.at<cv::Vec3b>(j,i)[c]);
                _max=fmax(_max,img.at<cv::Vec3b>(j,i)[c]);
            }
        }
    }

    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            for (int c=0; c<channel; c++) {
                value=img.at<cv::Vec3b>(j,i)[c];
                result.at<cv::Vec3b>(j,i)[c]=(uchar)((max-min)*(value-_min)/(_max-_min)+min);
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//pollen-lowcontrast的副本.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;
    his_normal(img, outimg,0,150);
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
