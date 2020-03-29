#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	/******** 获取视频文件(实例化的同时进行初始化)*******/
	VideoCapture capture("C:/Users/86176/Desktop/项目一（二版）/图像转视频/项目一/test.mp4");

	/********** 获取视频总帧数并打印*****************/
	long totalFrameNumber = capture.get(CAP_PROP_FRAME_COUNT);
	cout << "total frames: " << totalFrameNumber << endl;

	Mat frame;             //定义一个Mat变量，用来存放存储每一帧图像
	bool flags = true;     //循环标志位
	long currentFrame = 0; //定义当前帧

	while (flags)
	{
		capture.read(frame); // 读取视频每一帧
		stringstream str;    //stringstream字符串流，将long类型的转换成字符型传给对象str
		str << "f" << currentFrame << ".jpg";
		cout << "正在处理第" << currentFrame << "帧" << endl;

		/***设置每10帧获取一次帧***/
		if (currentFrame % 1 == 0) 
		{
			imwrite("C:/Users/86176/Desktop/项目一（二版）/图像转视频/项目一/images" + str.str(), frame);
		}// 将帧转成图片输出
		/**** 结束条件,当前帧数大于总帧数时候时，循环停止****/
		if (currentFrame >= totalFrameNumber)
		{
			flags = false;
		}

		currentFrame++;
	}

	waitKey(0);
	return 0;
}