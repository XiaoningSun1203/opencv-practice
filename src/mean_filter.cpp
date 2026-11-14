#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <cmath>

  //均值滤波器or盒式滤波算子
void mean_filter(cv::Mat &img,cv::Mat &result,int kernel_size){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, img.type());

    int pad=floor(kernel_size/2);
    int sum=0;
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            for(int c=0;c<channel;c++){
                sum=0;
                for (int dy=-pad; dy<pad+1; dy++) {
                    for (int dx=-pad; dx<pad+1; dx++) {
                        sum=sum+img.at<cv::Vec3b>(j+dy,i+dx)[c];
                    }
                }
                sum=(int)sum/(kernel_size*kernel_size);
                result.at<cv::Vec3b>(j,i)[c]=(uchar)(sum);
            }
        }
    }
}
int main(int argc,const char*argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//椒盐.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    mean_filter(img, out, 3);
    cv::imshow("answer", out);
    cv::waitKey(0);
    return 0;
}
