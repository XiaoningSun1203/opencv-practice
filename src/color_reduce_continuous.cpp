#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>

  //将图像展开成一行来遍历图像
void colorReduce(const cv::Mat& inputImg,cv::Mat& outputImg,int div){
    int nr=inputImg.rows;
    int nc=inputImg.cols;
    outputImg.create(inputImg.size(),inputImg.type());
    if (inputImg.isContinuous()&&outputImg.isContinuous()) {
        nr=1;
        nc=nc*inputImg.rows*inputImg.channels();
    }
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
    colorReduce(img,out,16);
    cv::imshow("answer", out);
    cv::waitKey(0);
    return 0;
}
