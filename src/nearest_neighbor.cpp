#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

  //最邻近插值

void nearest_neighbor(cv::Mat& img,cv::Mat& result,double rx,double ry){
    int height=img.rows;
    int width=img.cols;
    int nchannels=img.channels();
    int resized_height=(int)(height*ry);
    int resized_width=(int)(width*rx);
    result.create(resized_height,resized_width, img.type());

    int y_before,x_before;//放大过的虚拟y,x在原图中的向前取整后坐标
    for (int j=0; j<resized_height;j++) {
        y_before=(int)round(j/ry);
        y_before=fmin(y_before,height-1);
        for (int i=0; i<resized_width; i++) {
            x_before=(int)round(i/rx);
            x_before=fmin(x_before, width-1);
            for (int n=0; n<nchannels; n++) {
                result.at<cv::Vec3b>(j,i)[n]=img.at<cv::Vec3b>(y_before,x_before)[n];
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//answer1.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;

    const int64 start=cv::getTickCount();//记录开始时间

    nearest_neighbor(img,outimg,2.0,2.0);

    double duration=(cv::getTickCount()-start)/cv::getTickFrequency();//计算某个代码段的运行时间
    std::cout<<duration<<std::endl;
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
