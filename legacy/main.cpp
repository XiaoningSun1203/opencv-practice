

//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//using namespace cv;
//using namespace std;
//int main(int argc, const char * argv[])
//{
//    cv::Mat ima(500,500,CV_8UC1,cv::Scalar(255));
//    cv::namedWindow("New Window");
//    cout<<ima.size()<<endl;
//    cv::imshow("New Window", ima);
//    std::cout<<"This image is"<<ima.rows<<"x"<<ima.cols<<std::endl;
//    cv::waitKey(1000);//毫秒
//    ima=200;
//    cv::imshow("New Window", ima);
//    cv::waitKey(1000);
    //在图片上画圈圈
//    cv::circle(ima,cv::Point(155,110), 65, 0,3);
//    cv::imshow("New Window", ima);
//    cv::waitKey(1000);
    //读取文件中的图片
//    cv::Mat ima2=cv::imread("//Users//sunxiaoning//Desktop//2.jpg");
//    cv::imshow("New Window", ima2);
//    cv::waitKey(1000);
    //图片间复制
//    ima2.convertTo(ima, CV_32F,1/255,20.0);//没成功
//    cv::imshow("New Window", ima);
//    cv::imwrite("output.jpg", ima);//没成功
//    cv::waitKey(1000);

//    cv::flip(ima, ima, 0);
//    cv::imshow("New Window", ima);
//    cv::waitKey(1000);
    
//    cv::Matx33d matrix(3.0,2.0,1.0,2.0,1.0,3.0,1.0,2.0,3.0);
//    cv::Matx31d vector(5.0,1.0,3.0);
//    cv::Matx31d result=matrix*vector;

//return 0;
//}
//这是第一个成功的程序ROI
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//using namespace cv;
//using namespace std;
//int main(int argc, const char* argv[])
//{
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg");
//    cv::imshow("New Window", img);
//    cv::waitKey(1000);
//    cv::Mat logo=cv::imread("//Users//sunxiaoning//Desktop//1.png");//读入logo图像
//    //定义一个ROI区域，从ima2，大小计算得（正好是logo的大小）
//    cv::Mat imageROI(img,cv::Rect(img.cols-logo.cols,img.rows-logo.rows,logo.cols,logo.rows));
//    cv::Mat mask(logo);//把标志作为掩码，必须是灰度图像
//    logo.copyTo(imageROI,mask);//把logo贴到ima2的ROI区域,只复制掩码不为0像素
//    cv::imshow("ROI Window", img);
//    cv::waitKey(0);
//    return 0;
//}
//交换通道
//#include<iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//cv::Mat channel_swap(cv::Mat img){
//    int x,y;
//    int width=img.cols;
//    int height=img.rows;
//    cv::Mat out=cv::Mat::zeros(height,width,CV_8UC3);
//    for (y=0; y<height; y++) {
//        for (x=0; x<width; x++) {
//            out.at<cv::Vec3b>(y,x)[0]=img.at<cv::Vec3b>(y,x)[2];
//            out.at<cv::Vec3b>(y,x)[1]=img.at<cv::Vec3b>(y,x)[0];
//            out.at<cv::Vec3b>(y,x)[2]=img.at<cv::Vec3b>(y,x)[1];
//        }
//    }
//    return out;
//}
//int main(int argc,const char*argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);
//    cv::Mat out=channel_swap(img);
//
//    cv::imshow("sample",out);
//    cv::waitKey(0);
//    return 0;
//}
//减色处理
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core.hpp>
//#include<opencv2/highgui.hpp>
//cv::Mat colorReduce(cv::Mat img,int div){
//    cv::Mat out=cv::Mat::zeros(img.rows,img.cols,CV_8UC3);
//    for (int y=0; y<img.rows; y++) {
//        for (int x=0; x<img.cols; x++) {
//    out.at<cv::Vec3b>(y,x)[0]=img.at<cv::Vec3b>(y,x)[0]/div*div+div/2;
//    out.at<cv::Vec3b>(y,x)[1]=img.at<cv::Vec3b>(y,x)[1]/div*div+div/2;
//    out.at<cv::Vec3b>(y,x)[2]=img.at<cv::Vec3b>(y,x)[2]/div*div+div/2;
//        }
//    }
//    return out;
//}
//int main(int argc,const char*argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);
//    cv::Mat out=colorReduce(img,4);
//    cv::imshow("sample",out);
//    cv::waitKey(0);
//    return 0;
//}
  //灰度化
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core.hpp>
//#include<opencv2/highgui.hpp>
//cv::Mat BGR2GRAY(cv::Mat img){
//    cv::Mat out=cv::Mat::zeros(img.rows,img.cols,CV_8UC1);
//    for(int y=0;y<img.rows;y++){
//        for (int x=0; x<img.cols; x++) {
//            out.at<uchar>(y,x)=0.01*(float)img.at<cv::Vec3b>(y,x)[2]+0.01*(float)img.at<cv::Vec3b>(y,x)[0]+0.98*(float)img.at<cv::Vec3b>(y,x)[1];
//        }
//    }
//    return out;
//}
//int main(int argc,const char* argv[]){
//    cv::Mat image=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg");
//    cv::Mat output=BGR2GRAY(image);
//    cv::imshow("灰度化后图像", output);
//    cv::waitKey(0);
//    return 0;
//}
  //二值化
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core.hpp>
//#include<opencv2/highgui.hpp>
//cv::Mat BGR2GRAY(cv::Mat inputimg){//三通道变灰度图
//    cv::Mat out=cv::Mat::zeros(inputimg.rows,inputimg.cols,CV_8UC1);
//    for (int y=0; y<inputimg.rows; y++) {
//        for (int x=0; x<inputimg.cols; x++) {
//            out.at<uchar>(y,x)=0.2126*(float)inputimg.at<cv::Vec3b>(y,x)[2]+0.7152*(float)inputimg.at<cv::Vec3b>(y,x)[1]+0.0722*(float)inputimg.at<cv::Vec3b>(y,x)[0];
//        }
//    }
//    return out;
//}
//cv::Mat Binarize(cv::Mat inputimg,int th){//灰度图变二值图
//    cv::Mat out=cv::Mat::zeros(inputimg.rows,inputimg.cols,CV_8UC1);
//    for (int y=0; y<inputimg.rows; y++) {
//        for (int x=0; x<inputimg.cols; x++) {
//            if (inputimg.at<uchar>(y,x)>th){
//                out.at<uchar>(y,x)=255;
//            }else{
//                out.at<uchar>(y,x)=0;
//            }
//        }
//    }
//    return out;
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg");
//    if (img.empty()) {
//        std::cout<<"non loading"<<std::endl;
//        return -1;
//    }
//    cv::Mat grayimg=BGR2GRAY(img);
//    cv::imshow("BGR2GRAY",grayimg);
//    cv::waitKey(1000);
//    cv::Mat binaryimg=Binarize(grayimg,125);
//    cv::imshow("BINARY",binaryimg);
//    cv::waitKey(0);
//    return 0;
//}
  //用指针来遍历图像
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core.hpp>
//#include<opencv2/highgui.hpp>
//void colorReduce(cv::Mat& outputImg,const cv::Mat& inputImg,int div){
//    outputImg.create(inputImg.rows,inputImg.cols,inputImg.type());
//    int nr=inputImg.rows;
//    int nc=inputImg.cols*inputImg.channels();
//    for (int y=0; y<nr; y++) {
//        const uchar* inData=inputImg.ptr<uchar>(y);
//        uchar* outData=outputImg.ptr<uchar>(y);
//        for (int x=0; x<nc; x++) {
//            outData[x]=inData[x]/div*div+div/2;
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);
//
//    cv::Mat out;
//    colorReduce(out,img,4);
//    cv::imshow("answer", out);
//    cv::waitKey(0);
//    return 0;
//}
  //将图像展开成一行来遍历图像
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core.hpp>
//#include<opencv2/highgui.hpp>
//void colorReduce(const cv::Mat& inputImg,cv::Mat& outputImg,int div){
//    int nr=inputImg.rows;
//    int nc=inputImg.cols;
//    outputImg.create(inputImg.size(),inputImg.type());
//    if (inputImg.isContinuous()&&outputImg.isContinuous()) {
//        nr=1;
//        nc=nc*inputImg.rows*inputImg.channels();
//    }
//    for (int y=0; y<nr; y++) {
//        const uchar* inData=inputImg.ptr<uchar>(y);
//        uchar* outData=outputImg.ptr<uchar>(y);
//        for (int x=0; x<nc; x++) {
//            outData[x]=inData[x]/div*div+div/2;
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);
//
//    cv::Mat out;
//    colorReduce(img,out,16);
//    cv::imshow("answer", out);
//    cv::waitKey(0);
//    return 0;
//}
  //大津二值化算法
//#include<iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include<opencv2/highgui.hpp>
//#include <math.h>
//void BGR2GRAY(const cv::Mat& img,cv::Mat& outimg){
//    outimg.create(img.size(),CV_8UC1);
//    for (int y=0; y<img.rows; y++) {
//        for(int x=0;x<img.cols;x++){
//            outimg.at<uchar>(y,x)=0.3*img.at<cv::Vec3b>(y,x)[0]+0.3*img.at<cv::Vec3b>(y,x)[1]+0.4*img.at<cv::Vec3b>(y,x)[2];
//        }
//    }
//}
//void Binarize_Otsu(const cv::Mat& grayimg,cv::Mat& outimg){
//    int height=grayimg.rows;
//    int width=grayimg.cols;
//    double max_sb=0,sb=0;
//    int th=0;
//    for (int t=0; t<255; t++) {
//        double w0=0,m0=0;
//        double w1=0,m1=0;
//        for (int y=0; y<height; y++) {
//            for (int x=0; x<width; x++) {
//               int value=grayimg.at<uchar>(y,x);
//                if (value>=t) {
//                    w0++;
//                    m0=m0+value;
//                }else{
//                    w1++;
//                    m1=m1+value;
//                }
//            }
//        }
//        m0=m0/w0;
//        m1=m1/w1;
//        w0=w0/(height*width);
//        w1=w1/(height*width);
//        sb=w0*w1*pow((m0-m1),2);
//        if(sb>max_sb){
//            max_sb=sb;
//            th=t;
//        }
//    }
//    std::cout<<"threshold:"<<th<<std::endl;
//    outimg.create(height, width, CV_8UC1);
//    for (int y=0; y<height; y++) {
//        for (int x=0; x<width; x++) {
//            outimg.at<uchar>(y,x)=grayimg.at<uchar>(y,x);
//            if(outimg.at<uchar>(y,x)<th){
//                outimg.at<uchar>(y,x)=0;
//            }else{
//                outimg.at<uchar>(y,x)=255;
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//4.jpg",cv::IMREAD_COLOR);
//    cv::Mat grayimg,outimg;
//    BGR2GRAY(img,grayimg);
//    Binarize_Otsu(grayimg,outimg);
//    cv::imshow("answer",outimg);
//    cv::waitKey(0);
//    return 0;
//}
  //HSV变换：未实现
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core.hpp>
//#include<opencv2/highgui.hpp>
//#include<math.h>
//cv::Mat BGR2HSV(cv::Mat img){
//    float r,g,b;
//    float h=0,s=0,v=0;
//    float _max,_min;
//    int height=img.rows;
//    int width=img.cols;
//    cv::Mat hsv(height, width, CV_32FC3);
//    for (int y=0; y<height; y++) {
//        for (int x=0; x<width; x++) {
//            r=(float)img.at<cv::Vec3b>(y,x)[2]/255;
//            g=(float)img.at<cv::Vec3b>(y,x)[1]/255;
//            b=(float)img.at<cv::Vec3b>(y,x)[0]/255;
//            _max=fmax(r,fmax(g,b));
//            _min=fmin(r,fmin(g,b));
//            if (_min==_max) {
//                h=0;
//            }else if(_min==b){
//                h=60*(g-r)/(_max-_min)+60;
//            }else if(_min==r){
//                h=60*(b-g)/(_max-_min)+180;
//            }else if(_min==g){
//                h=60*(r-b)/(_max-_min)+300;
//            }
//            s=_max-_min;
//            v=_max;
//            hsv.at<cv::Vec3f>(y,x)[0]=h;
//            hsv.at<cv::Vec3f>(y,x)[1]=s;
//            hsv.at<cv::Vec3f>(y,x)[2]=v;
//        }
//    }
//    return hsv;
//}
//void HSV2BGR(const cv::Mat& img,cv::Mat& bgr){
//    int height=img.rows;
//    int width=img.cols;
//    int _H;//作为选择条件
//    float h,s,v;
//    float r=0,g=0,b=0;
//    double _h;
//    double _x;
//    bgr.create(height, width, CV_8UC3);
//    for (int y=0; y<height; y++) {
//        for (int x=0; x<width; x++) {
//            h=(float)img.at<cv::Vec3b>(y,x)[0];
//            s=(float)img.at<cv::Vec3b>(y,x)[1];
//            v=(float)img.at<cv::Vec3b>(y,x)[2];
//            _h=h/60;
//            _H=h/60;
//            _x=s*(1-abs(fmod(_h,2)-1));
//        switch (_H) {
//            case 0:
//                    r=v;
//                    g=v-s+_x;
//                    b=v-s;
//                    break;
//            case 1:
//                    r=v-s+_x;
//                    g=v;
//                    b=v-s;
//                    break;
//            case 2:
//                    r=v-s;
//                    g=v;
//                    b=v-s+_x;
//                    break;
//            case 3:
//                    r=v-s;
//                    g=v-s+_x;
//                    b=v;
//                    break;
//            case 4:
//                    g=v-s;
//                    r=v-s+_x;
//                    b=v;
//                    break;
//            case 5:
//                    g=v-s;
//                    r=v;
//                    b=v-s+x;
//                    break;
//                      }
//            bgr.at<cv::Vec3b>(y,x)[0]=(uchar)(b*255);
//            bgr.at<cv::Vec3b>(y,x)[1]=(uchar)(g*255);
//            bgr.at<cv::Vec3b>(y,x)[2]=(uchar)(r*255);
//        }
//    }
//}
//cv::Mat inverse_hue(cv::Mat& hsv){
//    int height=hsv.rows;
//    int width=hsv.cols;
//    cv::Mat inverse_hsv=cv::Mat::zeros(height, width, CV_32FC3);
//    for (int y=0; y<height; y++) {
//        for (int x=0; x<width; x++) {
//            inverse_hsv.at<cv::Vec3f>(y,x)[0]=fmod(hsv.at<cv::Vec3f>(y,x)[0]+180, 360);
//        }
//    }
//    return inverse_hsv;
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//3.jpeg",cv::IMREAD_COLOR);
//
//    cv::Mat hsvimg=BGR2HSV(img);
//    cv::imshow("answer1",hsvimg);
//    cv::waitKey(1000);
//
//    cv::Mat inverse_hsv=inverse_hue(hsvimg);
//    cv::imshow("answer2",inverse_hsv);
//    cv::waitKey(1000);
//
//    cv::Mat bgrimg;
//    HSV2BGR(hsvimg,bgrimg);
//    cv::imshow("answer3",bgrimg);
//    cv::waitKey(0);
//    return 0;
//}
  //2.6用3*3算子锐化图像（扫描图像并访问相邻像素）
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//void sharpen(const cv::Mat& image,cv::Mat& result){
//    int height=image.rows;
//    int width=image.cols;
//    int nchannels=image.channels();
//    uchar* output=NULL;
//    result.create(height,width,image.type());//检查是否需要为输出图像分配内存。如果之前没分配过或大小不对就分配
//    for (int y=1;y<height-2; y++) {//除去第一行和最后一行
//        const uchar* previous=image.ptr<const uchar>(y-1);//取得上一行的开始地址
//        const uchar* current=image.ptr<const uchar>(y);//取得本行的开始地址
//        const uchar* next=image.ptr<const uchar>(y+1);//取得下一行行的开始地址
//        output=result.ptr<uchar>(y);//把output指针放在输出图像的本行
//        for (int x=1; x<(width-2)*nchannels; x++) {//同时兼容灰度图与彩色图
//            *output=cv::saturate_cast<uchar>(5*current[x]-current[x-nchannels]-current[x+nchannels]-previous[x]-next[x]);
//            output++;
//        }
//    }
//    result.row(0).setTo(cv::Scalar(0,0,0));//把输出图像四边的像素设置为0,四边会出现黑边
//    result.col(0).setTo(cv::Scalar(0,0,0));
//    result.row(height-1).setTo(cv::Scalar(0,0,0));
//    result.col(width-1).setTo(cv::Scalar(0,0,0));
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//6.tif",cv::IMREAD_COLOR);
//    cv::Mat outimg;
//    sharpen(img,outimg);
//    cv::imshow("answer",outimg);
//    cv::waitKey(0);
//    return 0;
//}
  //最邻近插值
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <math.h>
//
//void nearest_neighbor(cv::Mat& img,cv::Mat& result,double rx,double ry){
//    int height=img.rows;
//    int width=img.cols;
//    int nchannels=img.channels();
//    int resized_height=(int)(height*ry);
//    int resized_width=(int)(width*rx);
//    result.create(resized_height,resized_width, img.type());
//
//    int y_before,x_before;//放大过的虚拟y,x在原图中的向前取整后坐标
//    for (int j=0; j<resized_height;j++) {
//        y_before=(int)round(j/ry);
//        y_before=fmin(y_before,height-1);
//        for (int i=0; i<resized_width; i++) {
//            x_before=(int)round(i/rx);
//            x_before=fmin(x_before, width-1);
//            for (int n=0; n<nchannels; n++) {
//                result.at<cv::Vec3b>(j,i)[n]=img.at<cv::Vec3b>(y_before,x_before)[n];
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//answer1.tif",cv::IMREAD_COLOR);
//    cv::Mat outimg;
//
//    const int64 start=cv::getTickCount();//记录开始时间
//
//    nearest_neighbor(img,outimg,2.0,2.0);
//
//    double duration=(cv::getTickCount()-start)/cv::getTickFrequency();//计算某个代码段的运行时间
//    std::cout<<duration<<std::endl;
//    cv::imshow("answer",outimg);
//    cv::waitKey(0);
//    return 0;
//}
  //双线性插值（好像与最邻近插值的结果相同）
//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <math.h>
//void bilinear(cv::Mat& img,cv::Mat& result,int resized_height,int resized_width){//已知放大后的尺寸
//    int height=img.rows;
//    int width=img.cols;
//    int nchannels=img.channels();
//
//    double ry=resized_height/height;
//    double rx=resized_width/width;
//    result.create(resized_height, resized_width, img.type());//检查是否需要为输出图像分配内存。如果之前没分配过或大小不对就分配内存
//    int  y_before,x_before;//原图中四个点中左上角的点,是整数
//    double y,x;//对应于原图的位置，是浮点数
//    int j,i;//在放大后图中的坐标
//    int dx,dy;
//
//    for (j=0; j<resized_height; j++) {
//        y=j/ry;//对应于原图的位置
//        y_before=(int)floor(y);//原图中的四个点中左上角那个的行坐标
//        y_before=fmin(y_before, height-1);
//        dy=(int)(y-y_before)*2048;
//
//        for (i=0; i<resized_width; i++) {
//            x=i/rx;//对应于原图的位置
//            x_before=(int)floor(i/rx);//原图中的四个点中左上角那个的列坐标
//            x_before=fmin(x_before, width-1);
//            dx=(int)(x-x_before)*2048;
//            for (int c=0; c<nchannels; c++) {
//                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(((2048-dx)*(2048-dy)*img.at<cv::Vec3b>(y,x)[c]+dx*(2048-dy)*img.at<cv::Vec3b>(y,x+1)[c]+(2048-dx)*dy*img.at<cv::Vec3b>(y+1,x)[c]+dx*dy*img.at<cv::Vec3b>(y+1,x+1)[c])/4194304);
//            }
//        }
//    }
//
//}
//void bilinear2(cv::Mat& img,cv::Mat& result,double rx,double ry){//已知放大的倍数，放大倍数不一定是整数，应该是浮点数
//    int height=img.rows;
//    int width=img.cols;
//    int nchannels=img.channels();
//
//    int resized_height=(int)(height*ry);
//    int resized_width=(int)(width*rx);
//    result.create(resized_height, resized_width, img.type());//检查是否需要为输出图像分配内存。如果之前没分配过或大小不对就分配内存
//
//    int  y_before,x_before;//原图中四个点中左上角的点
//    double y,x;//对应于原图的位置，是浮点数
//    int j,i;//在放大后图中的坐标
//    int dx,dy;
//
//    for (j=0; j<resized_height; j++) {
//        y=j/ry;//对应于原图的位置
//        y_before=(int)floor(y);//原图中的四个点中左上角那个点的行坐标
//        y_before=fmin(y_before, height-1);
//        dy=(int)(y-y_before)*2048;
//        for (i=0; i<resized_width; i++) {
//            x=i/rx;//对应于原图的位置
//            x_before=(int)floor(i/rx);//原图中的四个点中左上角那个点的列坐标
//            x_before=fmin(x_before, width-1);
//            dx=(int)(x-x_before)*2048;
//            for (int c=0; c<nchannels; c++) {
//                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(((2048-dx)*(2048-dy)*img.at<cv::Vec3b>(y,x)[c]+dx*(2048-dy)*img.at<cv::Vec3b>(y,x+1)[c]+(2048-dx)*dy*img.at<cv::Vec3b>(y+1,x)[c]+dx*dy*img.at<cv::Vec3b>(y+1,x+1)[c])/4194304);
//            }
//        }
//    }
//
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//answer1.tif",cv::IMREAD_COLOR);
//    cv::Mat outimg;
//    bilinear2(img,outimg,2,2);
//    cv::imshow("answer",outimg);
//    cv::waitKey(0);
//    return 0;
//}
  //降分辨率
//#include <iostream>
//#include <opencv2/highgui.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <math.h>
//
//void reduceResolution(cv::Mat& img,cv::Mat& result,double rx,double ry){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//
//    int resize_height=(int)height/ry;
//    int resize_width=(int)width/rx;
//    result.create(resize_height, resize_width, img.type());
//
//    int y_before,x_before;
//    for (int j=0; j<resize_height; j++) {
//        y_before=(int)floor(j*ry);
//        for (int i=0; i<resize_width; i++) {
//            x_before=(int)floor(i*rx);
//            for (int c=0; c<channel; c++) {
//                        result.at<cv::Vec3b>(j,i)[c]=img.at<cv::Vec3b>(y_before,x_before)[c];
//            }
//        }
//    }
//}
//int main(int argc,const char*argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//Chronometer.tif",cv::IMREAD_COLOR);
//    cv::Mat outimg;
//    reduceResolution(img, outimg, 13, 13);
//    cv::imwrite("//Users//sunxiaoning//Desktop//answer1.tif", outimg);
//    cv::waitKey(0);
//
//   return 0;
//}
  //双三次插值(未完成)
//#include <iostream>
//#include <opencv2/highgui.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <math.h>
//
//int val_clip(int x,int min,int max){//保证x不溢出
//    return fmin(fmax(x,min),max);
//}
//
//double weight(double x){
//    double a=-1;
//    if (fabs(x)<=1){
//        return (a+2)*pow(fabs(x), 3)-(a+3)*pow(fabs(x), 2)+1;
//    }else if(fabs(x)<=2){
//        return a*pow(fabs(x), 3)-5*a*pow(fabs(x), 2)+8*a*fabs(x)-4*a;
//    }
//        return 0;
//}
//void bicubic(cv::Mat& img,cv::Mat& result,double rx,double ry){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//
//    int resize_height=(int)(height*ry);
//    int resize_width=(int)(width*rx);
//    result.create(resize_height,resize_width, img.type());
//
//    double dy,dx;//输出图像坐标除以倍数得到的虚拟坐标
//    int y_before,x_before;//对虚拟坐标取整
//    int y,x;//避免上下溢出
//    int weight_x,weight_y,weight_sum;//x的权重系数，y的权重系数,16个权重系数之和
//    double val_sum;//16个像素带权重的和
//    int value;
//    for (int j=0; j<resize_height; j++) {
//        dy=j/ry;
//        y_before=(int)floor(dy);
//
//        for (int i=0; i<resize_width; i++) {
//            dx=i/rx;
//            x_before=(int)floor(dx);
//
//            for(int c=0;c<channel;c++){
//                val_sum=0;
//                weight_sum=0;
//                for (int filter_h=-1; filter_h<3; filter_h++) {//在4*4网格中计算val_sum和weight_sum
//                    y=val_clip(y_before+filter_h,0,height-1);//防止4*4网格纵坐标溢出原图
//                    weight_y=weight(fabs(dy-y));//得到原图中antiOverflow_y的权重系数
//                    for (int filter_w=-1; filter_w<3; filter_w++) {
//                        x=val_clip(x_before+filter_w,0,width-1);//防止4*4网格横坐标溢出原图
//                        weight_x=weight(fabs(dx-x));//得到原图中antiOverflow_x的权重系数
//
//                        weight_sum+=weight_x*weight_y;
//                        val_sum+=(double)img.at<cv::Vec3b>(y,x)[c]*weight_x*weight_y;
//                    }
//                }
//                        value=val_sum/weight_sum;
//                        value=val_clip(value, 0, 255);
//                        result.at<cv::Vec3b>(j,i)[c]=(uchar)value;
//
//            }
//        }
//    }
//}
//int main(int argc,const char*argv[]){
//   cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//answer1.tif",cv::IMREAD_COLOR);
//   cv::Mat outimg;
//   bicubic(img, outimg, 1.5, 1.5);
//   cv::imshow("answer2", outimg);
//   cv::waitKey(0);
//   return 0;
//}
  //伽马校正
//#include <iostream>
//#include <math.h>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//void gamma_correction(cv::Mat& img,cv::Mat& result,double gamma_c,double gamma_g){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height, width, img.type());
//
//    double val=0;
//    for (int y=0; y<height; y++) {
//        for (int x=0; x<width; x++) {
//            for (int c=0; c<channel; c++) {//疑问：可以兼容灰度图像么？
//                val=(double)img.at<cv::Vec3b>(y,x)[c]/255;
//                result.at<cv::Vec3b>(y,x)[c]=(uchar)gamma_c*(pow(val,gamma_g))*255;
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//spine的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat outimg;
//    gamma_correction(img, outimg, 1., 0.3);
//    cv::imshow("answer",outimg);
//    cv::waitKey(0);
//    return 0;
//}
  //平均池化
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//
//void pooling(cv::Mat& img,cv::Mat& result){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height, width, CV_8UC3);
//
//    double sum=0,vORm=0;
//    int r=8;//网格大小为r*r,以三个通道组合在一起为一个基本像素单位。
//    for (int y=0; y<height; y+=r) {//此次遍历用来确定每个网格左上角像素的坐标,而且注意每次循环的间隔为r个像素
//        for (int x=0; x<width; x+=r) {
//            for (int c=0; c<channel; c++) {//对8*8网格的三个通道分别计算
//                sum=0;//清空sum，sum的生存期是整个函数。
//                vORm=0;//清空vORm；这一行对平均池化没有影响（因为平均池化会在后面对vORm赋值），但在最大池化时循环内只有取大小没有赋值。一旦没有清空vORm，图像中的255会一直延续。
//                for (int dy=0; dy<r; dy++) {//此次遍历用来确定以y,x为左上角的8*8网格的灰度值之和
//                    for (int dx=0; dx<r; dx++) {
//                       sum=sum+img.at<cv::Vec3b>(y+dy,x+dx)[c];//此行用于平均池化
//
//                    }
//                }
//               vORm=sum/(r*r);//此行用于平均池化
//                for (int dy=0; dy<r; dy++) {//此次遍历用来给8*8网格的每个像素赋新的灰度值
//                    for (int dx=0; dx<r; dx++) {
//                        result.at<cv::Vec3b>(y+dy,x+dx)[c]=(uchar)vORm;
//                    }
//                }
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//lenna-RGB的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat outimg;
//    pooling(img, outimg);
//    cv::imshow("answer",outimg);
//    cv::waitKey(0);
//    return 0;
//}
  //最大池化
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//
//void pooling(cv::Mat& img,cv::Mat& result){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height, width, CV_8UC3);
//
//    double sum=0,vORm=0;
//    int r=8;//网格大小为r*r,以三个通道组合在一起为一个基本像素单位。
//    for (int y=0; y<height; y+=r) {//此次遍历用来确定每个网格左上角像素的坐标,而且注意每次循环的间隔为r个像素
//        for (int x=0; x<width; x+=r) {
//            for (int c=0; c<channel; c++) {//对8*8网格的三个通道分别计算
//                sum=0;//清空sum，sum的生存期是整个函数。
//                vORm=0;//清空vORm；这一行对平均池化没有影响（因为平均池化会在后面对vORm赋值），但在最大池化时循环内只有取大小没有赋值。一旦没有清空vORm，图像中的255会一直延续。
//                for (int dy=0; dy<r; dy++) {//此次遍历用来确定以y,x为左上角的8*8网格的灰度值之和
//                    for (int dx=0; dx<r; dx++) {
//                        vORm=fmax(vORm,img.at<cv::Vec3b>(y+dy,x+dx)[c]);//此行用于最大池化
//                    }
//                }
//                for (int dy=0; dy<r; dy++) {//此次遍历用来给8*8网格的每个像素赋新的灰度值
//                    for (int dx=0; dx<r; dx++) {
//                        result.at<cv::Vec3b>(y+dy,x+dx)[c]=(uchar)vORm;
//                    }
//                }
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//lenna-RGB的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat outimg;
//    pooling(img, outimg);
//    cv::imshow("answer",outimg);
//    cv::waitKey(0);
//    return 0;
//}
  //单独降低某个通道的颜色B、G、R，比如红色通道溢出
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//
//void red_spill(cv::Mat& img,cv::Mat& result){
//    int height=img.rows;
//    int width=img.cols;
//    result.create(height, width, CV_8UC3);
//
//    for (int y=0; y<height; y++) {
//        for (int x=0; x<width; x++) {
//            result.at<cv::Vec3b>(y,x)[2]=img.at<cv::Vec3b>(y,x)[2]-150;
//            result.at<cv::Vec3b>(y,x)[1]=img.at<cv::Vec3b>(y,x)[1];//之前忘了把B、G通道原样复制给result，导致显示出来的只有红色通道
//            result.at<cv::Vec3b>(y,x)[0]=img.at<cv::Vec3b>(y,x)[0];
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//lenna-RGB的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat outimg;
//    red_spill(img, outimg);
//    cv::imshow("answer",outimg);
//    cv::waitKey(0);
//    return 0;
//}
  //直方图归一化
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/core.hpp>
//#include <cmath>
//void his_normal(cv::Mat& img,cv::Mat& result,int min,int max){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height,width,img.type());
//
//    int _min=255,_max=0;//原图中的最小、最大灰度值
//    int value;
//    for (int j=0; j<height; j++) {//获得原图的最大灰度值、最小灰度值
//        for (int i=0; i<width; i++) {
//            for (int c=0; c<channel; c++) {
//                _min=fmin(_min,img.at<cv::Vec3b>(j,i)[c]);
//                _max=fmax(_max,img.at<cv::Vec3b>(j,i)[c]);
//            }
//        }
//    }
//
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            for (int c=0; c<channel; c++) {
//                value=img.at<cv::Vec3b>(j,i)[c];
//                result.at<cv::Vec3b>(j,i)[c]=(uchar)((max-min)*(value-_min)/(_max-_min)+min);
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//pollen-lowcontrast的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat outimg;
//    his_normal(img, outimg,0,150);
//    cv::imshow("answer",outimg);
//    cv::waitKey(0);
//    return 0;
//}
  //直方图均衡化
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>
void his_equal(cv::Mat& img,cv::Mat& result){
    int height=img.rows;
    int width=img.cols;
    int channel=img.channels();
    result.create(height, width, img.type());

    int value;
    double S=height*width*channel;
    double his[255];
    double his_sum[255];
    for (int i=0; i<255; i++) {//数组初始化
        his[i]=0;
        his_sum[i]=0;
    }
    //计算原始直方图his[]
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            for (int c=0; c<channel; c++) {
                value=img.at<cv::Vec3b>(y,x)[c];
                his[value]++;
            }
        }
    }
    //计算原始的累计直方图数组his_sum[]
    for (int val=0; val<255; val++) {
        his_sum[0]=his[0];
        his_sum[val]=his_sum[val-1]+his[val];
    }
    //使用直方图均衡化公式（L-1）/(M*N)*(从0到k的nk之和）得出新的灰度值
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            for (int c=0; c<channel; c++) {
                value=img.at<cv::Vec3b>(y,x)[c];
                result.at<cv::Vec3b>(y,x)[c]=cv::saturate_cast<uchar>(255/S*his_sum[value]);
            }
        }
    }
}
int main(int argc,const char* argv[]){
    cv::Mat img=cv::imread("/Users/sunxiaoning/Desktop/lenna.tif",cv::IMREAD_COLOR);
    cv::Mat outimg;
    his_equal(img, outimg);
    cv::imshow("answer",outimg);
    cv::waitKey(0);
    return 0;
}
  //图像添加椒盐噪声
//#include <iostream>
//#include <cstdlib>
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/core.hpp>
//void salt(cv::Mat &img,cv::Mat &result,double n){//n是椒盐噪声的比例
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result=img.clone();//只create不行，因为非椒盐部分需要原图像内容，所以需要clone（）
//
//    int number=height*width*n;
//    for (int i=0; i<number; i++) {//盐粒总个数
//        int m=rand()%height;//随机定位到第m行，%是为了保证随机数不超过总行数
//        int n=rand()%width;
//        if(channel==1){//单通道的处理方案
//            result.at<uchar>(m,n)=255;
//        }else{//三通道的处理方案
//            result.at<cv::Vec3b>(m,n)[0]=255;
//            result.at<cv::Vec3b>(m,n)[1]=255;
//            result.at<cv::Vec3b>(m,n)[2]=255;
//        }
//    }
//}
//int main(int argc,const char*argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//lenna-RGB的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    if (img.empty()) {
//        return -1;
//    }
//    salt(img, out, 0.2);
//    cv::imshow("result window", out);
//    cv::imwrite("//Users//sunxiaoning//Desktop//椒盐.tif", out);
//    cv::waitKey(0);
//    return  0;
//}
  //中值滤波
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/core.hpp>
//#include <math.h>
//void median_filter(cv::Mat &img,cv::Mat &result,int kernel_size){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//
//    result.create(height,width,img.type());
//    int pad=floor(kernel_size/2);
//    int count=0;
//
//    int vs[kernel_size*kernel_size];
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            for (int c=0; c<channel; c++) {
//                count=0;
//                if(((j-pad)>=0)&&((i-pad)>=0)&&((j+pad)<=height)&&((i+pad)<=width)){//不处理四周pad圈的像素
//                   for (int dy=-pad; dy<pad+1; dy++) {//构建kernel_size的数组用于快速排序
//                       for (int dx=-pad; dx<pad+1; dx++) {
//                        vs[count++]=img.at<cv::Vec3b>(j+dy,i+dx)[c];
//                       }
//                   }
//                    std::sort(vs,vs+(kernel_size*kernel_size));//对size*size个数进行快速排序
//                    result.at<cv::Vec3b>(j,i)[c]=(uchar)vs[int(floor(count/2))];//取排序后的数组的中间值，将其赋值给（j,i）
//                }
//            }
//        }
//    }
//}
//int main(int argc, const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//circuitboard-saltandpep的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    median_filter(img,out, 3);
//    cv::imshow("answer", out);
//    cv::waitKey(0);
//    return 0;
//}
  //均值滤波器or盒式滤波算子
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/core.hpp>
//void mean_filter(cv::Mat &img,cv::Mat &result,int kernel_size){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height, width, img.type());
//
//    int pad=floor(kernel_size/2);
//    int sum=0;
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            for(int c=0;c<channel;c++){
//                sum=0;
//                for (int dy=-pad; dy<pad+1; dy++) {
//                    for (int dx=-pad; dx<pad+1; dx++) {
//                        sum=sum+img.at<cv::Vec3b>(j+dy,i+dx)[c];
//                    }
//                }
//                sum=(int)sum/(kernel_size*kernel_size);
//                result.at<cv::Vec3b>(j,i)[c]=(uchar)(sum);
//            }
//        }
//    }
//}
//int main(int argc,const char*argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//椒盐.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    mean_filter(img, out, 3);
//    cv::imshow("answer", out);
//    cv::waitKey(0);
//    return 0;
//}
  //最大值滤波器
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <math.h>
//void BGR2GRAY(cv::Mat& img,cv::Mat& result){
//    int height=img.rows;
//    int width=img.cols;
//    result.create(height,width,img.type());
//
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            result.at<uchar>(j,i)=0.0722*img.at<cv::Vec3b>(j,i)[0]+0.7152*img.at<cv::Vec3b>(j,i)[1]+0.2126*img.at<cv::Vec3b>(j,i)[2];
//        }
//    }
//}
//void max_filter(cv::Mat& img,cv::Mat&result,int kernel_size){
//    int height=img.rows;
//    int width=img.cols;
//    result.create(height,width,CV_8UC1);
//
//    int pad=floor(kernel_size/2);
//    int value=0;
//    int vmax=0;
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//                vmax=0;
//                for (int dy=-pad; dy<pad+1; dy++) {
//                    for (int dx=-pad; dx<pad+1; dx++) {
//                        value=img.at<uchar>(j+dy,i+dx);//这里之前写错了，导致胡椒噪声更大了
//                        if (value>vmax) {
//                            vmax=value;
//                        }
//                    }
//                }
//                result.at<uchar>(j,i)=(uchar)vmax;
//
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img1=cv::imread("//Users//sunxiaoning//Desktop//circuitboard-pepper的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat gray;
//    cv::Mat out;
//    BGR2GRAY(img1,gray);
//    max_filter(gray, out,3);
//    cv::imshow("max_filter result",out);
//    cv::waitKey(0);
//    return 0;
//}
  //最小值滤波器
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <math.h>
//void BGR2GRAY(cv::Mat& img,cv::Mat& result){
//    int height=img.rows;
//    int width=img.cols;
//    result.create(height,width,img.type());
//
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            result.at<uchar>(j,i)=0.0722*img.at<cv::Vec3b>(j,i)[0]+0.7152*img.at<cv::Vec3b>(j,i)[1]+0.2126*img.at<cv::Vec3b>(j,i)[2];
//        }
//    }
//}
//void min_filter(cv::Mat& img,cv::Mat&result,int kernel_size){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height,width,CV_8UC1);
//
//    int pad=floor(kernel_size/2);
//    int value=0;
//    int vmin=255;
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            for (int c=0; c<channel; c++) {
//                vmin=255;
//                for (int dy=-pad; dy<pad+1; dy++) {
//                    for (int dx=-pad; dx<pad+1; dx++) {
//                        value=img.at<cv::Vec3b>(j+dy,i+dx)[c];
//                        if (value<vmin) {
//                            vmin=value;
//                        }
//                    }
//                }
//                result.at<cv::Vec3b>(j,i)[c]=(uchar)vmin;
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img2=cv::imread("//Users//sunxiaoning//Desktop//circuitboard-salt的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat gray;
//    cv::Mat out;
//    BGR2GRAY(img2,gray);
//    min_filter(gray, out, 3);
//    cv::imshow("min_filter result",out);
//    cv::waitKey(0);
//    return 0;
//}
//  //高斯滤波
//#include <iostream>
//#include <opencv2/highgui.hpp>
//#include <opencv2/core.hpp>
//#include <math.h>
//void gaussian_filter(cv::Mat& img,cv::Mat& result,int kernel_size,double sigma){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height, width, img.type());
//
//    int pad=floor(kernel_size/2);
//    double kernel[kernel_size][kernel_size];
//    double kernel_sum=0;
//    int _x=0,_y=0;
//
//    for (int y=0; y<kernel_size; y++) {//对高斯函数取样
//        for (int x=0; x<kernel_size; x++) {
//            _x=x-pad;
//            _y=y-pad;
//            kernel[y][x]=1/(2*M_PI*sigma*sigma)*exp(-(_x*_x+_y*_y)/(2*sigma*sigma));
//            kernel_sum+=kernel[y][x];
//        }
//    }
//    for(int y=0;y<kernel_size;y++){
//        for (int x=0; x<kernel_size; x++) {
//            kernel[y][x]/=kernel_sum;
//        }
//    }
//
//    double value=0;
//    for (int j=0; j<height; j++) {//进行高斯滤波
//        for (int i=0; i<width; i++) {
//            for (int c=0; c<channel; c++) {
//                value=0;
//                for (int y=-pad; y<pad+1; y++) {
//                    for (int x=-pad; x<pad+1; x++) {
//                        value+=img.at<cv::Vec3b>(j+y,i+x)[c]*kernel[y+pad][x+pad];
//                    }
//                }
//                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(value);
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//testpattern512-binary的副本.tif",cv::IMREAD_COLOR);
//    //cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//testpattern1024的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    gaussian_filter(img, out,21, 3.5);//为什么会整整大了4倍？
//    cv::imshow("gaussian_filter result", out);
//    cv::waitKey(0);
//    return 0;
//}
  //LoG滤波器（没找到书上的实验，用人骨图像做了没有什么差别）
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <math.h>
//void LoG_filter(cv::Mat& img,cv::Mat& result,int kernel_size,double sigma){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height,width, img.type());
//
//    int pad=floor(kernel_size/2);
//    double kernel[kernel_size][kernel_size];
//    int _x=0,_y=0;
//    double kernel_sum=0;
//    //对高斯-拉普拉斯函数进行取样，得到滤波网格
//    for (int y=0; y<kernel_size; y++) {
//        for (int x=0; x<kernel_size; x++) {
//            _x=x-pad;
//            _y=y-pad;
//            kernel[y][x]=(_x*_x+_y*_y-sigma*sigma)/(2*M_PI*pow(sigma,6))*exp(-(_x*_x+_y*_y)/(2*sigma*sigma));
//            kernel_sum+=kernel[y][x];
//        }
//    }
//    for (int y=0; y<kernel_size; y++) {
//        for (int x=0; x<kernel_size; x++) {
//            kernel[y][x]/=kernel_sum;
//        }
//    }
//
//    double value=0;
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            for(int c=0;c<channel;c++){
//            value=0;
//            for (int y=-pad;y<pad+1;y++) {
//                for (int x=-pad; x<pad+1; x++) {
//                    value+=img.at<cv::Vec3b>(j+y,i+x)[c]*kernel[y+pad][x+pad];
//                    }
//                }
//                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(value);
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//bonescan的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    LoG_filter(img, out, 5, 2);//图片为甚么会变小
//    cv::imshow("LoG", out);
//    cv::waitKey(0);
//    return 0;
//}
  //各种算子的代码（罗伯特梯度算子、罗伯特交叉梯度算子、prewitt算子、Emboss算子）
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//void filter(cv::Mat& img,cv::Mat& result,bool horizontal,int kernel_size){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height, width, img.type());
//
//    //罗伯特梯度算子
//    double kernel[3][3]={{0,-1,0},{0,1,0},{0,0,0}};
//    if(horizontal){
//        kernel[0][1]=0;
//        kernel[1][0]=-1;
//    }
    //罗伯特交叉梯度算子
//    double kernel[3][3]={{-1,0,0},{0,1,0},{0,0,0}};
//    if(horizontal){
//        kernel[0][0]=0;
//        kernel[0][1]=-1;
//        kernel[1][0]=1;
//        kernel[1][1]=0;
//    }
    //prewitt算子(的确有使边缘强烈的效果)
//    double kernel[3][3]={{-1,-1,-1},{0,0,0},{1,1,1}};
//    if(horizontal){
//        kernel[0][1]=0;
//        kernel[0][2]=-1;
//        kernel[1][0]=-1;
//        kernel[1][1]=1;
//        kernel[2][0]=-1;
//        kernel[2][1]=0;
//    }
    //emboss滤波
//    double kernel[3][3]={{-2,-1,0},{-1,1,1},{0,1,2}};
    
//    int pad=floor(kernel_size/2);
//    double v=0;
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            for (int c=0; c<channel; c++) {
//                v=0;
//                for (int dy=-pad; dy<pad+1; dy++) {
//                    for (int dx=-pad; dx<pad+1; dx++) {
//                        v+=img.at<cv::Vec3b>(j+dy,i+dx)[c]*kernel[dy+pad][dx+pad];
//
//                    }
//                }
//                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(v);
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//contact-lens的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    filter(img, out,false,3);
//    cv::imshow("Robert filter", out);
//    cv::waitKey(0);
//    return 0;
//}
  //Sobel 滤波
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//void filter(cv::Mat& img,cv::Mat& result,int kernel_size){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height, width, img.type());
//
//    //sobel算子
//    double kernel1[3][3]={{1,2,1},{0,0,0},{-1,-2,-1}};//水平sobel算子，即水平方向的偏导数
//    double kernel2[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};//垂直sobel算子，即垂直方向的偏导数
//
//    int pad=floor(kernel_size/2);
//    double v1=0,v2=0;
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            for (int c=0; c<channel; c++) {
//                v1=0;
//                v2=0;
//                for (int dy=-pad; dy<pad+1; dy++) {
//                    for (int dx=-pad; dx<pad+1; dx++) {
//                        v1+=img.at<cv::Vec3b>(j+dy,i+dx)[c]*kernel1[dy+pad][dx+pad];//原图与水平方向的偏导数进行卷积
//                        v2+=img.at<cv::Vec3b>(j+dy,i+dx)[c]*kernel2[dy+pad][dx+pad];//原图与垂直方向的偏导数进行卷积
//                    }
//                }
//                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(sqrt(v1*v1+v2*v2));//任意方向上的偏导数等于水平与垂直的平方和再取平方
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//contact-lens的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    filter(img, out,3);
//    cv::imshow("Sobel filter", out);
//    cv::waitKey(0);
//    return 0;
//}
  //单独的拉普拉斯锐化滤波
//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <math.h>
//void laplace_filter(cv::Mat& img,cv::Mat& result,int kernel_size){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height, width, img.type());
//
//    double kernel[3][3]={{0,1,0},{1,-4,1},{0,1,0}};
//    //double kernel[3][3]={{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};
//
//    int pad=floor(kernel_size/2);
//    double value=0;
//    for (int j=0; j<height; j++) {
//        for (int i=0; i<width; i++) {
//            for (int c=0; c<channel; c++) {
//                value=0;
//                for (int dy=-pad; dy<pad+1; dy++) {
//                    for (int dx=-pad; dx<pad+1; dx++) {
//                        value+=img.at<cv::Vec3b>(j+dy,i+dx)[c]*kernel[dy+pad][dx+pad];
//                    }
//                }
//
//                //result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(img.at<cv::Vec3b>(j,i)[c]+value);//正确——锐化后图像
//                result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>(value);//正确——单纯拉普拉斯图像
//            }
//        }
//    }
//
//}
//void histogram_normalization(cv::Mat& img,cv::Mat& result,int n,int m){//求单纯拉普拉斯图像的最大值、最小值为灰度值固定范围缩放做准备
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//    result.create(height, width, img.type());
//
//    double value=0;
//    double max=0,min=255;
//    for (int j=0; j<height; j++) {
//         for (int i=0; i<width; i++) {
//             for (int c=0; c<channel; c++) {
//             value=img.at<cv::Vec3b>(j,i)[c];
//             max=fmax(max, value);
//             min=fmin(min, value);
//            }
//        }
//   }
//    for (int j=0; j<height; j++) {
//         for (int i=0; i<width; i++) {
//             for (int c=0; c<channel; c++) {
//             value=img.at<cv::Vec3b>(j,i)[c];
//             result.at<cv::Vec3b>(j,i)[c]=cv::saturate_cast<uchar>((m-n)*(value-min)/(max-min)+n);
//            }
//        }
//   }
//}
//
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//blurry-moon的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    cv::Mat out2;
//    laplace_filter(img,out,3);
//    histogram_normalization(out,out2,0,255);
//    cv::imshow("laplace filter", out);
//    cv::waitKey(0);
//    return 0;
//}
  //平移变换or缩放平移变换
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//void affine(cv::Mat& img,cv::Mat& result,double a,double b,double c,double d,double tj,double ti){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//
//    int resize_height=(int)(height*a);//注意别搞反了a,d
//    int resize_width=(int)(width*d);
//
//    result.create(resize_height, resize_width, img.type());
//
//    int det=a*d-b*c;
//    int j_before,i_before;
//    for (int j=0; j<resize_height; j++) {//x代表纵坐标
//        for (int i=0; i<resize_width; i++) {//y代表横坐标
//
//                j_before=(int)((d*j-b*i)/det-tj);
//                i_before=(int)((-c*j+a*i)/det-ti);
//
//                if(i_before<0||i_before>=width||j_before<0||j_before>=height){
//                    continue;
//                }
//            for (int c=0; c<channel; c++){
//                    result.at<cv::Vec3b>(j,i)[c]=(uchar)img.at<cv::Vec3b>(j_before,i_before)[c];
//            }
//
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//wingding-arrow-down的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    affine(img,out,1.3,0,0,0.8,30,-30);
//    cv::imshow("affine", out);
//    cv::waitKey(0);
//    return 0;
//}
  //旋转变换
//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <math.h>
//void affine(cv::Mat& img,cv::Mat& result,double a,double b,double c,double d,double tj,double ti,double theta){
//    int height=img.rows;
//    int width=img.cols;
//    int channel=img.channels();
//
//    double rad=theta/180.*M_PI;
//    a=std::cos(rad);
//    b=-std::sin(rad);
//    c=std::sin(rad);
//    d=std::cos(rad);
//    double det=a*d-b*c;
//
//    int resize_height=(int)height*abs(d)+width*abs(c);
//    int resize_width=(int)width*abs(d)+height*abs(c);
//
//    tj=(int)resize_height/2-(a*(height/2)+b*(width/2));
//    ti=(int)resize_width/2-(c*(height/2)+d*(width/2));
//
//    result.create(resize_height, resize_width, img.type());
//
//    int j_before=0,i_before=0;
//    for (int j=0; j<resize_height; j++) {
//        for (int i=0; i<resize_width; i++) {
//            j_before=(int)(d*j-b*i+b*ti-d*tj)/det;
//            i_before=(int)(-c*j+a*i-a*ti+c*tj)/det;
//
//            if (i_before<0||i_before>=width||j_before<0||j_before>=height) {
//                result.at<cv::Vec3b>(j,i)[c]=125;
//                continue;
//            }
//            for (int c=0; c<channel; c++) {
//                result.at<cv::Vec3b>(j,i)[c]=img.at<cv::Vec3b>(j_before,i_before)[c];
//            }
//        }
//    }
//}
//int main(int argc,const char* argv[]){
//    cv::Mat img=cv::imread("//Users//sunxiaoning//Desktop//wingding-arrow-down的副本.tif",cv::IMREAD_COLOR);
//    cv::Mat out;
//    affine(img,out,1,0,0,1,0,0,-90);
//    cv::imshow("affine", out);
//    cv::waitKey(0);
//    return 0;
//}
  //j_before=(int)(d*(j-tj)-b*(i-ti)+b*ti-d*tj)/det;//根本不对，出来的是红色,为什么
  //i_before=(int)(-c*(j-tj)+a*(i-ti)-a*ti+c*tj)/det;
  //j_before=(int)(d*j-b*i)/det-tj;
  //i_before=(int)(-c*j+a*i)/det-ti;


















