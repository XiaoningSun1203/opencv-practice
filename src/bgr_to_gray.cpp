#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>

  //灰度化
cv::Mat BGR2GRAY(cv::Mat img){
    cv::Mat out=cv::Mat::zeros(img.rows,img.cols,CV_8UC1);
    for(int y=0;y<img.rows;y++){
        for (int x=0; x<img.cols; x++) {
            out.at<uchar>(y,x)=0.01*(float)img.at<cv::Vec3b>(y,x)[2]+0.01*(float)img.at<cv::Vec3b>(y,x)[0]+0.98*(float)img.at<cv::Vec3b>(y,x)[1];
        }
    }
    return out;
}
int main(int argc,const char* argv[]){
    cv::Mat image=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg");
    cv::Mat output=BGR2GRAY(image);
    cv::imshow("灰度化后图像", output);
    cv::waitKey(0);
    return 0;
}
