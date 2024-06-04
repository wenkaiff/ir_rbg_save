//img
#include<opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <time.h>
#include <fstream>
#include<iostream>
using namespace std;
using namespace cv;

int main() {
	/*VideoCapture vid1(0);*/
	VideoCapture vid1 = VideoCapture();
	vid1.open(1, CAP_DSHOW);
	VideoCapture vid2 = VideoCapture();
	vid2.open(2, CAP_DSHOW);
	vid1.set(CAP_PROP_FRAME_WIDTH, 640);
	vid1.set(CAP_PROP_FRAME_HEIGHT, 512);
	vid2.set(CAP_PROP_FRAME_WIDTH, 640);
	vid2.set(CAP_PROP_FRAME_HEIGHT, 512);
	vid2.set(CAP_PROP_FOURCC, VideoWriter::fourcc('Y', 'U', 'Y', '2'));
	/*cout << vid2.get(CAP_PROP_FORMAT) << endl;*/
	int n_frame = 0;
	Mat frame_v, frame_i, frame;

	
	while (true) {
		vid1 >> frame_v;
		vid2 >> frame_i;
		
		resize(frame_v, frame_v, Size(640, 512));
		resize(frame_i, frame_i, Size(640, 512), 0.0, 0.0, INTER_CUBIC);
		
		/*resize(frame_v, frame_v, Size(2448, 2048));
		resize(frame_i, frame_i, Size(2448, 2048), 0.0, 0.0, INTER_CUBIC);*/

		Mat m = Mat::zeros(frame_v.size(), frame_v.type());
		m = Scalar(0, 0, 35);
		subtract(frame_v, m, frame_v);

		namedWindow("cap1", WINDOW_NORMAL);
		namedWindow("cap2", WINDOW_NORMAL);
		imshow("cap1", frame_v);   
		imshow("cap2", frame_i);


		/*hconcat(frame_v, frame_i, frame);*/

		imwrite("E:\\photo\\rgb" + to_string(n_frame) + "rgb.jpg", frame_v);
		imwrite("E:\\photo\\ir" + to_string(n_frame) + "ir.jpg", frame_i);

		n_frame = n_frame + 1;
		//cout << to_string(n_frame) << endl;
		waitKey(0);
	}
	return 0;
}





////video
//#include<opencv2/opencv.hpp>
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <time.h>
//#include <fstream>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
//int main() {
//	//VideoCapture vid1(0);
//	VideoCapture vid1 = VideoCapture();
//	vid1.open(1, CAP_DSHOW);
//	VideoCapture vid2 = VideoCapture();
//	vid2.open(2, CAP_DSHOW);
//	vid1.set(CAP_PROP_FRAME_WIDTH, 640);
//	vid1.set(CAP_PROP_FRAME_HEIGHT, 512);
//	vid2.set(CAP_PROP_FRAME_WIDTH, 640);
//	vid2.set(CAP_PROP_FRAME_HEIGHT, 512);
//	vid2.set(CAP_PROP_FOURCC, VideoWriter::fourcc('Y', 'U', 'Y', '2'));
//	//cout << vid2.get(CAP_PROP_FORMAT) << endl;
//	int n_frame = 0;
//	Mat frame_v, frame_i, frame;
//	VideoWriter vwrgb;
//	VideoWriter vwir;
//	int fps = 24;
//	vwrgb.open("I:\\a\\rgb\\video\\rgb.avi", VideoWriter::fourcc('M', 'P', '4', '2'), fps, Size(640, 512));
//	vwir.open("I:\\a\\ir\\video\\ir.avi", VideoWriter::fourcc('M', 'P', '4', '2'), fps, Size(640, 512));
//
//	while (true) {
//		vid1 >> frame_v;
//		vid2 >> frame_i;
//
//		resize(frame_v, frame_v, Size(640, 512));
//		resize(frame_i, frame_i, Size(640, 512), 0.0, 0.0, INTER_CUBIC);
//
//		//Mat m = Mat::zeros(frame_v.size(), frame_v.type());
//		//m = Scalar(0, 0, 35);
//		//subtract(frame_v, m, frame_v);
//
//		namedWindow("cap1", WINDOW_NORMAL);
//		namedWindow("cap2", WINDOW_NORMAL);
//		imshow("cap1", frame_v);
//		imshow("cap2", frame_i);
//
//		vwrgb.write(frame_v);
//		vwir.write(frame_i);
//
//		if (waitKey(100)==32)
//		{
//			imwrite("I:\\a\\rgb\\" + to_string(n_frame) + "rgb.jpg", frame_v);
//			imwrite("I:\\a\\ir\\" + to_string(n_frame) + "ir.jpg", frame_i);
//			n_frame = n_frame + 1;
//		}
//
//		if (waitKey(100) == 'q') break;
//
//		//hconcat(frame_v, frame_i, frame);
//
//		//imwrite("./1/v/" + to_string(n_frame++) + "v.jpg", frame_v);
//		//imwrite("./1/i/" + to_string(n_frame++) + "i.jpg", frame_i);
//		////cout << to_string(n_frame) << endl;
//	}
//	return 0;
//}


