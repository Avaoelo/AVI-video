#include<iostream>
#include <cstring>
#include <cstdio>
#include <opencv2/opencv.hpp>
#include <ctime> 
using namespace std;
int main()
{
	int isColor=1;//ͼƬ�Ƿ�Ϊ��ɫ
	double fps=25;//֡�� ������������
	int imgW=360;//ͼƬ���
	int imgH=240;//ͼƬ�߶�
	char* flieName="videoname.avi";//�������Ƶ�ļ���
	int startFrame=1;//ͼƬ��ʼ֡�ţ����������Ҫ����Ϊʵ���п���ֻ��ҪͼƬ��һ����֡����
	int endFrame=2000;//ͬ��
	char cur_fn[255];//
	char* prefix="F:\\vibe20\\output\\vibe-";//ͼƬ���е�·��
	char* ext=".jpg";//����ͼƬ��׺��

	CvVideoWriter *pWriter;

	CvSize size=cvSize(imgW,imgH);
	pWriter=cvCreateVideoWriter(flieName,CV_FOURCC('X','V','I','D'),fps,size,isColor);//OpenCV �⺯����������Ƶд����
	IplImage *pImg=NULL;
	while(startFrame<=endFrame)
	{
		strcpy(cur_fn,"");
		sprintf(cur_fn,"%s%010d%s",prefix,startFrame,ext);//����������ʺ����� 123.jpg 124.jpg��ͼƬ����
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

	cvReleaseVideoWriter(&pWriter);//�ǵ����� �ͷ���Դ ���������ʧ��
}