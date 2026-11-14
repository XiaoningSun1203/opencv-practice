#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <math.h>

  //降分辨率

void reduceResolution(cv::Mat& img,cv::Mat& result,double rx,double ry){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();

    int resize_height=(int)height/ry;
    int resize_width=(int)width/rx;
    result.create(resize_height, resize_width, img.type());

    int y_before,x_before;
    for (int j=0; j<resize_height; j++) {
        y_before=(int)floor(j*ry);
        for (int i=0; i<resize_width; i++) {
            x_before=(int)floor(i*rx);
            for (int c=0; c<channel; c++) {
                        result.at<cv::Vec3b>(j,i)[c]=img.at<cv::Vec3b>(y_before,x_before)[c];
            }
        }
    }
}
int main(int argc,const char*argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//Chronometer.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;
    reduceResolution(img, outimg, 13, 13);
    cv::imwrite("//Users//sunxiaoning//Desktop//answer1.tif", outimg);
    cv::waitKey(0);

   return 0;
}
