#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

  //伽马校正
void gamma_correction(cv::Mat& img,cv::Mat& result,double gamma_c,double gamma_g){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, img.type());

    double val=0;
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            for (int c=0; c<channel; c++) {//疑问：可以兼容灰度图像么？
                val=(double)img.at<cv::Vec3b>(y,x)[c]/255;
                result.at<cv::Vec3b>(y,x)[c]=(uchar)gamma_c*(pow(val,gamma_g))*255;
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//spine的副本.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;
    gamma_correction(img, outimg, 1., 0.3);
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
