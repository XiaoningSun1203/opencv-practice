#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

  //直方图均衡化
void his_equal(cv::Mat& img,cv::Mat& result){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, img.type());

    int value;
    double S=height*width*channel;
    double his[255];
    double his_sum[255];
    for (int i=0; i<255; i++) {//数组初始化
        his[i]=0;
        his_sum[i]=0;
    }
    //计算原始直方图his[]
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            for (int c=0; c<channel; c++) {
                value=img.at<cv::Vec3b>(y,x)[c];
                his[value]++;
            }
        }
    }
    //计算原始的累计直方图数组his_sum[]
    for (int val=0; val<255; val++) {
        his_sum[0]=his[0];
        his_sum[val]=his_sum[val-1]+his[val];
    }
    //使用直方图均衡化公式（L-1）/(M*N)*(从0到k的nk之和）得出新的灰度值
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            for (int c=0; c<channel; c++) {
                value=img.at<cv::Vec3b>(y,x)[c];
                result.at<cv::Vec3b>(y,x)[c]=cv::saturate_cast<uchar>(255/S*his_sum[value]);
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("/Users/sunxiaoning/Desktop/lenna.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;
    his_equal(img, outimg);
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
