#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;
int main(int argc, const char * argv[])
{
    cv::Mat ima(500,500,CV_8UC1,cv::Scalar(255));
    cv::namedWindow("New Window");
    cout<<ima.size()<<endl;
    cv::imshow("New Window", ima);
    std::cout<<"This image is"<<ima.rows<<"x"<<ima.cols<<std::endl;
    cv::waitKey(1000);//毫秒
    ima=200;
    cv::imshow("New Window", ima);
    cv::waitKey(1000);
    //在图片上画圈圈
    cv::circle(ima,cv::Point(155,110), 65, 0,3);
    cv::imshow("New Window", ima);
    cv::waitKey(1000);
    //读取文件中的图片
    cv::Mat ima2=cv::imread("//Users//sunxiaoning//Desktop//2.jpg");
    cv::imshow("New Window", ima2);
    cv::waitKey(1000);
    //图片间复制
    ima2.convertTo(ima, CV_32F,1/255,20.0);//没成功
    cv::imshow("New Window", ima);
    cv::imwrite("output.jpg", ima);//没成功
    cv::waitKey(1000);

    cv::flip(ima, ima, 0);
    cv::imshow("New Window", ima);
    cv::waitKey(1000);
    
    cv::Matx33d matrix(3.0,2.0,1.0,2.0,1.0,3.0,1.0,2.0,3.0);
    cv::Matx31d vector(5.0,1.0,3.0);
    cv::Matx31d result=matrix*vector;

return 0;
}
