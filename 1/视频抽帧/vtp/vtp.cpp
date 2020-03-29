#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	/******** ��ȡ��Ƶ�ļ�(ʵ������ͬʱ���г�ʼ��)*******/
	VideoCapture capture("C:/Users/86176/Desktop/��Ŀһ�����棩/ͼ��ת��Ƶ/��Ŀһ/test.mp4");

	/********** ��ȡ��Ƶ��֡������ӡ*****************/
	long totalFrameNumber = capture.get(CAP_PROP_FRAME_COUNT);
	cout << "total frames: " << totalFrameNumber << endl;

	Mat frame;             //����һ��Mat������������Ŵ洢ÿһ֡ͼ��
	bool flags = true;     //ѭ����־λ
	long currentFrame = 0; //���嵱ǰ֡

	while (flags)
	{
		capture.read(frame); // ��ȡ��Ƶÿһ֡
		stringstream str;    //stringstream�ַ���������long���͵�ת�����ַ��ʹ�������str
		str << "f" << currentFrame << ".jpg";
		cout << "���ڴ����" << currentFrame << "֡" << endl;

		/***����ÿ10֡��ȡһ��֡***/
		if (currentFrame % 1 == 0) 
		{
			imwrite("C:/Users/86176/Desktop/��Ŀһ�����棩/ͼ��ת��Ƶ/��Ŀһ/images" + str.str(), frame);
		}// ��֡ת��ͼƬ���
		/**** ��������,��ǰ֡��������֡��ʱ��ʱ��ѭ��ֹͣ****/
		if (currentFrame >= totalFrameNumber)
		{
			flags = false;
		}

		currentFrame++;
	}

	waitKey(0);
	return 0;
}