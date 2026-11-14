#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

  //平移变换or缩放平移变换
void affine(cv::Mat& img,cv::Mat& result,double a,double b,double c,double d,double tj,double ti){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();

    int resize_height=(int)(height*a);//注意别搞反了a,d
    int resize_width=(int)(width*d);

    result.create(resize_height, resize_width, img.type());

    int det=a*d-b*c;
    int j_before,i_before;
    for (int j=0; j<resize_height; j++) {//x代表纵坐标
        for (int i=0; i<resize_width; i++) {//y代表横坐标

                j_before=(int)((d*j-b*i)/det-tj);
                i_before=(int)((-c*j+a*i)/det-ti);

                if(i_before<0||i_before>=width||j_before<0||j_before>=height){
                    continue;
                }
            for (int c=0; c<channel; c++){
                    result.at<cv::Vec3b>(j,i)[c]=(uchar)img.at<cv::Vec3b>(j_before,i_before)[c];
            }

        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//wingding-arrow-down的副本.tif",cv::IMREAD_COLOR);
    cv::Mat out;
    affine(img,out,1.3,0,0,0.8,30,-30);
    cv::imshow("affine", out);
    cv::waitKey(0);
    return 0;
}
