#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>

//减色处理
cv::Mat colorReduce(cv::Mat img,int div){
    cv::Mat out=cv::Mat::zeros(img.rows,img.cols,CV_8UC3);
    for (int y=0; y<img.rows; y++) {
        for (int x=0; x<img.cols; x++) {
    out.at<cv::Vec3b>(y,x)[0]=img.at<cv::Vec3b>(y,x)[0]/div*div+div/2;
    out.at<cv::Vec3b>(y,x)[1]=img.at<cv::Vec3b>(y,x)[1]/div*div+div/2;
    out.at<cv::Vec3b>(y,x)[2]=img.at<cv::Vec3b>(y,x)[2]/div*div+div/2;
        }
    }
    return out;
}
int main(int argc,const char*argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);
    cv::Mat out=colorReduce(img,4);
    cv::imshow("sample",out);
    cv::waitKey(0);
    return 0;
}
