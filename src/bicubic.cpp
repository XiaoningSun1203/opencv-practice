#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <math.h>

  //双三次插值(未完成)

int val_clip(int x,int min,int max){//保证x不溢出
    return fmin(fmax(x,min),max);
}

double weight(double x){
    double a=-1;
    if (fabs(x)<=1){
        return (a+2)*pow(fabs(x), 3)-(a+3)*pow(fabs(x), 2)+1;
    }else if(fabs(x)<=2){
        return a*pow(fabs(x), 3)-5*a*pow(fabs(x), 2)+8*a*fabs(x)-4*a;
    }
        return 0;
}
void bicubic(cv::Mat& img,cv::Mat& result,double rx,double ry){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();

    int resize_height=(int)(height*ry);
    int resize_width=(int)(width*rx);
    result.create(resize_height,resize_width, img.type());

    double dy,dx;//输出图像坐标除以倍数得到的虚拟坐标
    int y_before,x_before;//对虚拟坐标取整
    int y,x;//避免上下溢出
    int weight_x,weight_y,weight_sum;//x的权重系数，y的权重系数,16个权重系数之和
    double val_sum;//16个像素带权重的和
    int value;
    for (int j=0; j<resize_height; j++) {
        dy=j/ry;
        y_before=(int)floor(dy);

        for (int i=0; i<resize_width; i++) {
            dx=i/rx;
            x_before=(int)floor(dx);

            for(int c=0;c<channel;c++){
                val_sum=0;
                weight_sum=0;
                for (int filter_h=-1; filter_h<3; filter_h++) {//在4*4网格中计算val_sum和weight_sum
                    y=val_clip(y_before+filter_h,0,height-1);//防止4*4网格纵坐标溢出原图
                    weight_y=weight(fabs(dy-y));//得到原图中antiOverflow_y的权重系数
                    for (int filter_w=-1; filter_w<3; filter_w++) {
                        x=val_clip(x_before+filter_w,0,width-1);//防止4*4网格横坐标溢出原图
                        weight_x=weight(fabs(dx-x));//得到原图中antiOverflow_x的权重系数

                        weight_sum+=weight_x*weight_y;
                        val_sum+=(double)img.at<cv::Vec3b>(y,x)[c]*weight_x*weight_y;
                    }
                }
                        value=val_sum/weight_sum;
                        value=val_clip(value, 0, 255);
                        result.at<cv::Vec3b>(j,i)[c]=(uchar)value;

            }
        }
    }
}
int main(int argc,const char*argv[]){
   cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//answer1.tif",cv::IMREAD_COLOR);
   cv::Mat outimg;
   bicubic(img, outimg, 1.5, 1.5);
   cv::imshow("answer2", outimg);
   cv::waitKey(0);
   return 0;
}
