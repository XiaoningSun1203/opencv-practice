#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>

  //二值化
cv::Mat BGR2GRAY(cv::Mat inputimg){//三通道变灰度图
    cv::Mat out=cv::Mat::zeros(inputimg.rows,inputimg.cols,CV_8UC1);
    for (int y=0; y<inputimg.rows; y++) {
        for (int x=0; x<inputimg.cols; x++) {
            out.at<uchar>(y,x)=0.2126*(float)inputimg.at<cv::Vec3b>(y,x)[2]+0.7152*(float)inputimg.at<cv::Vec3b>(y,x)[1]+0.0722*(float)inputimg.at<cv::Vec3b>(y,x)[0];
        }
    }
    return out;
}
cv::Mat Binarize(cv::Mat inputimg,int th){//灰度图变二值图
    cv::Mat out=cv::Mat::zeros(inputimg.rows,inputimg.cols,CV_8UC1);
    for (int y=0; y<inputimg.rows; y++) {
        for (int x=0; x<inputimg.cols; x++) {
            if (inputimg.at<uchar>(y,x)>th){
                out.at<uchar>(y,x)=255;
            }else{
                out.at<uchar>(y,x)=0;
            }
        }
    }
    return out;
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg");
    if (img.empty()) {
        std::cout<<"non loading"<<std::endl;
        return -1;
    }
    cv::Mat grayimg=BGR2GRAY(img);
    cv::imshow("BGR2GRAY",grayimg);
    cv::waitKey(1000);
    cv::Mat binaryimg=Binarize(grayimg,125);
    cv::imshow("BINARY",binaryimg);
    cv::waitKey(0);
    return 0;
}
