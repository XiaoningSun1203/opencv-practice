#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <cmath>

  //各种算子的代码（罗伯特梯度算子、罗伯特交叉梯度算子、prewitt算子、Emboss算子）
void filter(cv::Mat& img,cv::Mat& result,bool horizontal,int kernel_size){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, img.type());

    //emboss滤波
    double kernel[3][3]={{-2,-1,0},{-1,1,1},{0,1,2}};
    
    int pad=floor(kernel_size/2);
    double v=0;
    for (int j=0; j<height; j++) {
        for (int i=0; i<width; i++) {
            for (int c=0; c<channel; c++) {
                v=0;
                for (int dy=-pad; dy<pad+1; dy++) {
                    for (int dx=-pad; dx<pad+1; dx++) {
                        v+=img.at<cv::Vec3b>(j+dy,i+dx)[c]*kernel[dy+pad][dx+pad];

                    }
                }
                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(v);
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//contact-lens的副本.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    filter(img, out,false,3);
    cv::imshow("Robert filter", out);
    cv::waitKey(0);
    return 0;
}
