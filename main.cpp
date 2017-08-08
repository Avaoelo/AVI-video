#include<iostream>
#include <cstring>
#include <cstdio>
#include <opencv2/opencv.hpp>
#include <ctime> 
using namespace std;
int main()
{
	int isColor=1;//图片是否为彩色
	double fps=25;//帧率 按照需求设置
	int imgW=360;//图片宽度
	int imgH=240;//图片高度
	char* flieName="videoname.avi";//保存的视频文件名
	int startFrame=1;//图片开始帧号，这样设计主要是因为实验中可能只需要图片的一部分帧序列
	int endFrame=2000;//同上
	char cur_fn[255];//
	char* prefix="F:\\vibe20\\output\\vibe-";//图片序列的路径
	char* ext=".jpg";//序列图片后缀名

	CvVideoWriter *pWriter;

	CvSize size=cvSize(imgW,imgH);
	pWriter=cvCreateVideoWriter(flieName,CV_FOURCC('X','V','I','D'),fps,size,isColor);//OpenCV 库函数，创建视频写入器
	IplImage *pImg=NULL;
	while(startFrame<=endFrame)
	{
		strcpy(cur_fn,"");
		sprintf(cur_fn,"%s%010d%s",prefix,startFrame,ext);//这里的设置适合形如 123.jpg 124.jpg的图片序列
		pImg=cvLoadImage(cur_fn,0);
		if (!pImg)    
		{
			std::cout<<"can't open file"<<std::endl;
			return 0;
		}
		cvWriteFrame(pWriter,pImg);
		cvWaitKey(1);

		std::cout<<"Write frame "<<startFrame<<std::endl;
		startFrame++;
		cvReleaseImage(&pImg);
	}

	cvReleaseVideoWriter(&pWriter);//记得用完 释放资源 否则会运行失败
}