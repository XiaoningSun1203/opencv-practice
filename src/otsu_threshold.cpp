#include<iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include <math.h>

  //大津二值化算法
void BGR2GRAY(const cv::Mat& img,cv::Mat& outimg){
    outimg.create(img.size(),CV_8UC1);
    for (int y=0; y<img.rows; y++) {
        for(int x=0;x<img.cols;x++){
            outimg.at<uchar>(y,x)=0.3*img.at<cv::Vec3b>(y,x)[0]+0.3*img.at<cv::Vec3b>(y,x)[1]+0.4*img.at<cv::Vec3b>(y,x)[2];
        }
    }
}
void Binarize_Otsu(const cv::Mat& grayimg,cv::Mat& outimg){
    int height=grayimg.rows;
    int width=grayimg.cols;
    double max_sb=0,sb=0;
    int th=0;
    for (int t=0; t<255; t++) {
        double w0=0,m0=0;
        double w1=0,m1=0;
        for (int y=0; y<height; y++) {
            for (int x=0; x<width; x++) {
               int value=grayimg.at<uchar>(y,x);
                if (value>=t) {
                    w0++;
                    m0=m0+value;
                }else{
                    w1++;
                    m1=m1+value;
                }
            }
        }
        m0=m0/w0;
        m1=m1/w1;
        w0=w0/(height*width);
        w1=w1/(height*width);
        sb=w0*w1*pow((m0-m1),2);
        if(sb>max_sb){
            max_sb=sb;
            th=t;
        }
    }
    std::cout<<"threshold:"<<th<<std::endl;
    outimg.create(height, width, CV_8UC1);
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            outimg.at<uchar>(y,x)=grayimg.at<uchar>(y,x);
            if(outimg.at<uchar>(y,x)<th){
                outimg.at<uchar>(y,x)=0;
            }else{
                outimg.at<uchar>(y,x)=255;
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//4.jpg",cv::IMREAD_COLOR);
    cv::Mat grayimg,outimg;
    BGR2GRAY(img,grayimg);
    Binarize_Otsu(grayimg,outimg);
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
