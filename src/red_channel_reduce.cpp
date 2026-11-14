#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

  //单独降低某个通道的颜色B、G、R，比如红色通道溢出

void red_spill(cv::Mat& img,cv::Mat& result){
    int height=img.rows;
    int width=img.cols;
    result.create(height, width, CV_8UC3);

    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            result.at<cv::Vec3b>(y,x)[2]=img.at<cv::Vec3b>(y,x)[2]-150;
            result.at<cv::Vec3b>(y,x)[1]=img.at<cv::Vec3b>(y,x)[1];//之前忘了把B、G通道原样复制给result，导致显示出来的只有红色通道
            result.at<cv::Vec3b>(y,x)[0]=img.at<cv::Vec3b>(y,x)[0];
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//lenna-RGB的副本.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;
    red_spill(img, outimg);
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
