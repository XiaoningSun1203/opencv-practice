#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

  //双线性插值（好像与最邻近插值的结果相同）
void bilinear(cv::Mat& img,cv::Mat& result,int resized_height,int resized_width){//已知放大后的尺寸
    int height=img.rows;
    int width=img.cols;
    int nchannels=img.channels();

    double ry=resized_height/height;
    double rx=resized_width/width;
    result.create(resized_height, resized_width, img.type());//检查是否需要为输出图像分配内存。如果之前没分配过或大小不对就分配内存
    int  y_before,x_before;//原图中四个点中左上角的点,是整数
    double y,x;//对应于原图的位置，是浮点数
    int j,i;//在放大后图中的坐标
    int dx,dy;

    for (j=0; j<resized_height; j++) {
        y=j/ry;//对应于原图的位置
        y_before=(int)floor(y);//原图中的四个点中左上角那个的行坐标
        y_before=fmin(y_before, height-1);
        dy=(int)(y-y_before)*2048;

        for (i=0; i<resized_width; i++) {
            x=i/rx;//对应于原图的位置
            x_before=(int)floor(i/rx);//原图中的四个点中左上角那个的列坐标
            x_before=fmin(x_before, width-1);
            dx=(int)(x-x_before)*2048;
            for (int c=0; c<nchannels; c++) {
                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(((2048-dx)*(2048-dy)*img.at<cv::Vec3b>(y,x)[c]+dx*(2048-dy)*img.at<cv::Vec3b>(y,x+1)[c]+(2048-dx)*dy*img.at<cv::Vec3b>(y+1,x)[c]+dx*dy*img.at<cv::Vec3b>(y+1,x+1)[c])/4194304);
            }
        }
    }

}

int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//answer1.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;
    bilinear(img,outimg,img.rows*2,img.cols*2);
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
