#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <math.h>
#include <algorithm>

  //中值滤波
void median_filter(cv::Mat &img,cv::Mat &result,int kernel_size){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();

    result.create(height,width,img.type());
    int pad=floor(kernel_size/2);
    int count=0;

    int vs[kernel_size*kernel_size];
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            for (int c=0; c<channel; c++) {
                count=0;
                if(((j-pad)>=0)&&((i-pad)>=0)&&((j+pad)<=height)&&((i+pad)<=width)){//不处理四周pad圈的像素
                   for (int dy=-pad; dy<pad+1; dy++) {//构建kernel_size的数组用于快速排序
                       for (int dx=-pad; dx<pad+1; dx++) {
                        vs[count++]=img.at<cv::Vec3b>(j+dy,i+dx)[c];
                       }
                   }
                    std::sort(vs,vs+(kernel_size*kernel_size));//对size*size个数进行快速排序
                    result.at<cv::Vec3b>(j,i)[c]=(uchar)vs[int(floor(count/2))];//取排序后的数组的中间值，将其赋值给（j,i）
                }
            }
        }
    }
}
int main(int argc, const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//circuitboard-saltandpep的副本.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    median_filter(img,out, 3);
    cv::imshow("answer", out);
    cv::waitKey(0);
    return 0;
}
