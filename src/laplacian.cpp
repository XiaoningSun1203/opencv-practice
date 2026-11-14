#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>
#include <opencv2/opencv.hpp>

  //单独的拉普拉斯锐化滤波
void laplace_filter(cv::Mat& img,cv::Mat& result,int kernel_size){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, img.type());

    double kernel[3][3]={{0,1,0},{1,-4,1},{0,1,0}};
    //double kernel[3][3]={{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};

    int pad=floor(kernel_size/2);
    double value=0;
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            for (int c=0; c<channel; c++) {
                value=0;
                for (int dy=-pad; dy<pad+1; dy++) {
                    for (int dx=-pad; dx<pad+1; dx++) {
                        value+=img.at<cv::Vec3b>(j+dy,i+dx)[c]*kernel[dy+pad][dx+pad];
                    }
                }

                //result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(img.at<cv::Vec3b>(j,i)[c]+value);//正确——锐化后图像
                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(value);//正确——单纯拉普拉斯图像
            }
        }
    }

}
void histogram_normalization(cv::Mat& img,cv::Mat& result,int n,int m){//求单纯拉普拉斯图像的最大值、最小值为灰度值固定范围缩放做准备
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, img.type());

    double value=0;
    double max=0,min=255;
    for (int j=0; j<height; j++) {
         for (int i=0; i<width; i++) {
             for (int c=0; c<channel; c++) {
             value=img.at<cv::Vec3b>(j,i)[c];
             max=fmax(max, value);
             min=fmin(min, value);
            }
        }
   }
    for (int j=0; j<height; j++) {
         for (int i=0; i<width; i++) {
             for (int c=0; c<channel; c++) {
             value=img.at<cv::Vec3b>(j,i)[c];
             result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>((m-n)*(value-min)/(max-min)+n);
            }
        }
   }
}

int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//blurry-moon的副本.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    cv::Mat out2;
    laplace_filter(img,out,3);
    histogram_normalization(out,out2,0,255);
    cv::imshow("laplace filter", out);
    cv::waitKey(0);
    return 0;
}
