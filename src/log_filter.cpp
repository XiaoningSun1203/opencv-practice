#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

  //LoG滤波器（没找到书上的实验，用人骨图像做了没有什么差别）
void LoG_filter(cv::Mat& img,cv::Mat& result,int kernel_size,double sigma){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height,width, img.type());

    int pad=floor(kernel_size/2);
    double kernel[kernel_size][kernel_size];
    int _x=0,_y=0;
    double kernel_sum=0;
    //对高斯-拉普拉斯函数进行取样，得到滤波网格
    for (int y=0; y<kernel_size; y++) {
        for (int x=0; x<kernel_size; x++) {
            _x=x-pad;
            _y=y-pad;
            kernel[y][x]=(_x*_x+_y*_y-sigma*sigma)/(2*M_PI*pow(sigma,6))*exp(-(_x*_x+_y*_y)/(2*sigma*sigma));
            kernel_sum+=kernel[y][x];
        }
    }
    for (int y=0; y<kernel_size; y++) {
        for (int x=0; x<kernel_size; x++) {
            kernel[y][x]/=kernel_sum;
        }
    }

    double value=0;
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            for(int c=0;c<channel;c++){
            value=0;
            for (int y=-pad;y<pad+1;y++) {
                for (int x=-pad; x<pad+1; x++) {
                    value+=img.at<cv::Vec3b>(j+y,i+x)[c]*kernel[y+pad][x+pad];
                    }
                }
                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(value);
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//bonescan的副本.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    LoG_filter(img, out, 5, 2);//图片为甚么会变小
    cv::imshow("LoG", out);
    cv::waitKey(0);
    return 0;
}
