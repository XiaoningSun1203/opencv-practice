#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

  //旋转变换
void affine(cv::Mat& img,cv::Mat& result,double a,double b,double c,double d,double tj,double ti,double theta){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();

    double rad=theta/180.*M_PI;
    a=std::cos(rad);
    b=-std::sin(rad);
    c=std::sin(rad);
    d=std::cos(rad);
    double det=a*d-b*c;

    int resize_height=(int)height*abs(d)+width*abs(c);
    int resize_width=(int)width*abs(d)+height*abs(c);

    tj=(int)resize_height/2-(a*(height/2)+b*(width/2));
    ti=(int)resize_width/2-(c*(height/2)+d*(width/2));

    result.create(resize_height, resize_width, img.type());

    int j_before=0,i_before=0;
    for (int j=0; j<resize_height; j++) {
        for (int i=0; i<resize_width; i++) {
            j_before=(int)(d*j-b*i+b*ti-d*tj)/det;
            i_before=(int)(-c*j+a*i-a*ti+c*tj)/det;

            if (i_before<0||i_before>=width||j_before<0||j_before>=height) {
                result.at<cv::Vec3b>(j,i)[c]=125;
                continue;
            }
            for (int c=0; c<channel; c++) {
                result.at<cv::Vec3b>(j,i)[c]=img.at<cv::Vec3b>(j_before,i_before)[c];
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//wingding-arrow-down的副本.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    affine(img,out,1,0,0,1,0,0,-90);
    cv::imshow("affine", out);
    cv::waitKey(0);
    return 0;
}
  //j_before=(int)(d*(j-tj)-b*(i-ti)+b*ti-d*tj)/det;//根本不对，出来的是红色,为什么
  //i_before=(int)(-c*(j-tj)+a*(i-ti)-a*ti+c*tj)/det;
  //j_before=(int)(d*j-b*i)/det-tj;
  //i_before=(int)(-c*j+a*i)/det-ti;
