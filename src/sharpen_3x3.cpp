#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include <opencv2/highgui.hpp>

  //2.6用3*3算子锐化图像（扫描图像并访问相邻像素）
void sharpen(const cv::Mat& image,cv::Mat& result){
    int height=image.rows;
    int width=image.cols;
    int nchannels=image.channels();
    uchar* output=NULL;
    result.create(height,width,image.type());//检查是否需要为输出图像分配内存。如果之前没分配过或大小不对就分配
    for (int y=1;y<height-2; y++) {//除去第一行和最后一行
        const uchar* previous=image.ptr<const uchar>(y-1);//取得上一行的开始地址
        const uchar* current=image.ptr<const uchar>(y);//取得本行的开始地址
        const uchar* next=image.ptr<const uchar>(y+1);//取得下一行行的开始地址
        output=result.ptr<uchar>(y);//把output指针放在输出图像的本行
        for (int x=1; x<(width-2)*nchannels; x++) {//同时兼容灰度图与彩色图
            *output=cv::saturate_cast<uchar>(5*current[x]-current[x-nchannels]-current[x+nchannels]-previous[x]-next[x]);
            output++;
        }
    }
    result.row(0).setTo(cv::Scalar(0,0,0));//把输出图像四边的像素设置为0,四边会出现黑边
    result.col(0).setTo(cv::Scalar(0,0,0));
    result.row(height-1).setTo(cv::Scalar(0,0,0));
    result.col(width-1).setTo(cv::Scalar(0,0,0));
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//6.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;
    sharpen(img,outimg);
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
