#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <cmath>

  //最大池化

void pooling(cv::Mat& img,cv::Mat& result){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, CV_8UC3);

    double sum=0,vORm=0;
    int r=8;//网格大小为r*r,以三个通道组合在一起为一个基本像素单位。
    for (int y=0; y<height; y+=r) {//此次遍历用来确定每个网格左上角像素的坐标,而且注意每次循环的间隔为r个像素
        for (int x=0; x<width; x+=r) {
            for (int c=0; c<channel; c++) {//对8*8网格的三个通道分别计算
                sum=0;//清空sum，sum的生存期是整个函数。
                vORm=0;//清空vORm；这一行对平均池化没有影响（因为平均池化会在后面对vORm赋值），但在最大池化时循环内只有取大小没有赋值。一旦没有清空vORm，图像中的255会一直延续。
                for (int dy=0; dy<r; dy++) {//此次遍历用来确定以y,x为左上角的8*8网格的灰度值之和
                    for (int dx=0; dx<r; dx++) {
                        vORm=fmax(vORm,img.at<cv::Vec3b>(y+dy,x+dx)[c]);//此行用于最大池化
                    }
                }
                for (int dy=0; dy<r; dy++) {//此次遍历用来给8*8网格的每个像素赋新的灰度值
                    for (int dx=0; dx<r; dx++) {
                        result.at<cv::Vec3b>(y+dy,x+dx)[c]=(uchar)vORm;
                    }
                }
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//lenna-RGB的副本.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;
    pooling(img, outimg);
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
