#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <cmath>

  //Sobel 滤波
void filter(cv::Mat& img,cv::Mat& result,int kernel_size){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, img.type());

    //sobel算子
    double kernel1[3][3]={{1,2,1},{0,0,0},{-1,-2,-1}};//水平sobel算子，即水平方向的偏导数
    double kernel2[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};//垂直sobel算子，即垂直方向的偏导数

    int pad=floor(kernel_size/2);
    double v1=0,v2=0;
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            for (int c=0; c<channel; c++) {
                v1=0;
                v2=0;
                for (int dy=-pad; dy<pad+1; dy++) {
                    for (int dx=-pad; dx<pad+1; dx++) {
                        v1+=img.at<cv::Vec3b>(j+dy,i+dx)[c]*kernel1[dy+pad][dx+pad];//原图与水平方向的偏导数进行卷积
                        v2+=img.at<cv::Vec3b>(j+dy,i+dx)[c]*kernel2[dy+pad][dx+pad];//原图与垂直方向的偏导数进行卷积
                    }
                }
                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(sqrt(v1*v1+v2*v2));//任意方向上的偏导数等于水平与垂直的平方和再取平方
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//contact-lens的副本.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    filter(img, out,3);
    cv::imshow("Sobel filter", out);
    cv::waitKey(0);
    return 0;
}
