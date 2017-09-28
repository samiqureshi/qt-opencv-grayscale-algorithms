#ifndef OPENCVHANDLER_H
#define OPENCVHANDLER_H

//#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

class OpenCVHandler
{
public:
    OpenCVHandler(std::string _filepath);
    //Grayscale Algorithms
    void averageGS();
    void lightnessGS();
    void luminosityGS();
    void decompMinGS();
    void decompMaxGS();
    void redChannelGS();
    void greenChannelGS();
    void blueChannelGS();
    void shadesOfGrayGS(int _numShades);


private:
    cv::Mat image;
    cv::Size size;
    std::string filepath;
};

#endif // OPENCVHANDLER_H
