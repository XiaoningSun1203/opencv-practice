#include <iostream>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

  //图像添加椒盐噪声
void salt(cv::Mat &img,cv::Mat &result,double n){//n是椒盐噪声的比例
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result=img.clone();//只create不行，因为非椒盐部分需要原图像内容，所以需要clone（）

    int number=height*width*n;
    for (int i=0; i<number; i++) {//盐粒总个数
        int m=rand()%height;//随机定位到第m行，%是为了保证随机数不超过总行数
        int n=rand()%width;
        if(channel==1){//单通道的处理方案
            result.at<uchar>(m,n)=255;
        }else{//三通道的处理方案
            result.at<cv::Vec3b>(m,n)[0]=255;
            result.at<cv::Vec3b>(m,n)[1]=255;
            result.at<cv::Vec3b>(m,n)[2]=255;
        }
    }
}
int main(int argc,const char*argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//lenna-RGB的副本.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    if (img.empty()) {
        return -1;
    }
    salt(img, out, 0.2);
    cv::imshow("result window", out);
    cv::imwrite("//Users//sunxiaoning//Desktop//椒盐.tif", out);
    cv::waitKey(0);
    return  0;
}
