#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>

  //用指针来遍历图像
void colorReduce(cv::Mat& outputImg,const cv::Mat& inputImg,int div){
    outputImg.create(inputImg.rows,inputImg.cols,inputImg.type());
    int nr=inputImg.rows;
    int nc=inputImg.cols*inputImg.channels();
    for (int y=0; y<nr; y++) {
        const uchar* inData=inputImg.ptr<uchar>(y);
        uchar* outData=outputImg.ptr<uchar>(y);
        for (int x=0; x<nc; x++) {
            outData[x]=inData[x]/div*div+div/2;
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);

    cv::Mat out;
    colorReduce(out,img,4);
    cv::imshow("answer", out);
    cv::waitKey(0);
    return 0;
}
