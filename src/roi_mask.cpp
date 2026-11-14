#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

//这是第一个成功的程序ROI
using namespace cv;
using namespace std;
int main(int argc, const char* argv[])
{
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg");
    cv::imshow("New Window", img);
    cv::waitKey(1000);
    cv::Mat logo=cv::imread("//Users//sunxiaoning//Desktop//1.png");//读入logo图像
    //定义一个ROI区域，从ima2，大小计算得（正好是logo的大小）
    cv::Mat imageROI(img,cv::Rect(img.cols-logo.cols,img.rows-logo.rows,logo.cols,logo.rows));
    cv::Mat mask(logo);//把标志作为掩码，必须是灰度图像
    logo.copyTo(imageROI,mask);//把logo贴到ima2的ROI区域,只复制掩码不为0像素
    cv::imshow("ROI Window", img);
    cv::waitKey(0);
    return 0;
}
