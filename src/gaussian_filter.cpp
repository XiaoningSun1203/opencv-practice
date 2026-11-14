#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <math.h>
#include <opencv2/opencv.hpp>

  //高斯滤波
void gaussian_filter(cv::Mat& img,cv::Mat& result,int kernel_size,double sigma){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, img.type());

    int pad=floor(kernel_size/2);
    double kernel[kernel_size][kernel_size];
    double kernel_sum=0;
    int _x=0,_y=0;

    for (int y=0; y<kernel_size; y++) {//对高斯函数取样
        for (int x=0; x<kernel_size; x++) {
            _x=x-pad;
            _y=y-pad;
            kernel[y][x]=1/(2*M_PI*sigma*sigma)*exp(-(_x*_x+_y*_y)/(2*sigma*sigma));
            kernel_sum+=kernel[y][x];
        }
    }
    for(int y=0;y<kernel_size;y++){
        for (int x=0; x<kernel_size; x++) {
            kernel[y][x]/=kernel_sum;
        }
    }

    double value=0;
    for (int j=0; j<height; j++) {//进行高斯滤波
        for (int i=0; i<width; i++) {
            for (int c=0; c<channel; c++) {
                value=0;
                for (int y=-pad; y<pad+1; y++) {
                    for (int x=-pad; x<pad+1; x++) {
                        value+=img.at<cv::Vec3b>(j+y,i+x)[c]*kernel[y+pad][x+pad];
                    }
                }
                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(value);
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//testpattern512-binary的副本.tif",cv::IMREAD_COLOR);
    //cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//testpattern1024的副本.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    gaussian_filter(img, out,21, 3.5);//为什么会整整大了4倍？
    cv::imshow("gaussian_filter result", out);
    cv::waitKey(0);
    return 0;
}
