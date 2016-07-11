//
//  main.cpp
//  opencvtest
//
//  Created by 高江洲祐治 on 2016/07/11.
//  Copyright © 2016年 高江洲祐治. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, HELLO, World!\n";
//    return 0;
//}

//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//
//int main(int argc, const char * argv[])
//{
//    cv::Mat img(cv::Size(320, 240), CV_8UC3, cv::Scalar(60, 150, 80));
//    cv::namedWindow("OpenCV", cv::WINDOW_AUTOSIZE);
//    cv::imshow("OpenCV", img);
//    cv::waitKey(0);
//}

// http://opencv.jp/sample/video_io.html#capture
#include <cv.h>
#include <highgui.h>
#include <ctype.h>

int
main (int argc, char **argv)
{
    CvCapture *capture = 0;
    IplImage *frame = 0;
    double w = 320, h = 240;
    int c;
    
    // (1)コマンド引数によって指定された番号のカメラに対するキャプチャ構造体を作成する
    if (argc == 1 || (argc == 2 && strlen (argv[1]) == 1 && isdigit (argv[1][0])))
        capture = cvCreateCameraCapture (argc == 2 ? argv[1][0] - '0' : 0);
    
    /* この設定は，利用するカメラに依存する */
    // (2)キャプチャサイズを設定する．
    cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_WIDTH, w);
    cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_HEIGHT, h);
    
    cvNamedWindow ("Capture", CV_WINDOW_AUTOSIZE);
    
    // (3)カメラから画像をキャプチャする
    while (1) {
        frame = cvQueryFrame (capture);
        cvShowImage ("Capture", frame);
        c = cvWaitKey (2);
        if (c == '\x1b')
            break;
    }
    
    cvReleaseCapture (&capture);
    cvDestroyWindow ("Capture");
    
    return 0;
}