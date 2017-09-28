#include "opencvhandler.h"

OpenCVHandler::OpenCVHandler(std::string _filepath)
{
    filepath = _filepath;
    image = cv::imread(filepath, CV_LOAD_IMAGE_COLOR);
    size = image.size();
}

void OpenCVHandler::averageGS()
{
    //Split the input image into its 3 channels BGR
    cv::Mat bgr[3];
    cv::split(image, bgr);
    cv::Mat gray = (bgr[2] + bgr[1] + bgr[0])/3;
    cv::namedWindow("Average", cv::WINDOW_NORMAL);
    cv::imshow( "Average", gray );
}

void OpenCVHandler::lightnessGS()
{
    //Split the input image into its 3 channels BGR
    cv::Mat bgr[3];
    cv::split(image, bgr);
    cv::Mat max =  cv::max(bgr[2], cv::max(bgr[1], bgr[0]));
    cv::Mat min =  cv::min(bgr[2], cv::min(bgr[1], bgr[0]));
    cv::Mat gray = (max + min)/2;
    cv::namedWindow("Lightness", cv::WINDOW_NORMAL);
    cv::imshow( "Lightness", gray );
}

void OpenCVHandler::luminosityGS()
{
    //Split the input image into its 3 channels BGR
    cv::Mat bgr[3];
    cv::split(image, bgr);
    cv::Mat gray = 0.21*bgr[2] + 0.72*bgr[1] + 0.07*bgr[0];
    cv::namedWindow("Luminosity", cv::WINDOW_NORMAL);
    cv::imshow( "Luminosity", gray );
}

void OpenCVHandler::decompMinGS()
{
    //Split the input image into its 3 channels BGR
    cv::Mat bgr[3];
    cv::split(image, bgr);
    cv::Mat min =  cv::min(bgr[2], cv::min(bgr[1], bgr[0]));
    cv::namedWindow("Minimum Decomposition", cv::WINDOW_NORMAL);
    cv::imshow( "Minimum Decomposition", min );
}

void OpenCVHandler::decompMaxGS()
{
    //Split the input image into its 3 channels BGR
    cv::Mat bgr[3];
    cv::split(image, bgr);
    cv::Mat max =  cv::max(bgr[2], cv::max(bgr[1], bgr[0]));
    cv::namedWindow("Maximum Decomposition", cv::WINDOW_NORMAL);
    cv::imshow( "Maximum Decomposition", max );
}

void OpenCVHandler::redChannelGS()
{
    //Split the input image into its 3 channels BGR
    cv::Mat bgr[3];
    cv::split(image, bgr);
    cv::namedWindow("Red Channel", cv::WINDOW_NORMAL);
    cv::imshow( "Red Channel", bgr[2] );
}

void OpenCVHandler::greenChannelGS()
{
    //Split the input image into its 3 channels BGR
    cv::Mat bgr[3];
    cv::split(image, bgr);
    cv::namedWindow("Green Channel", cv::WINDOW_NORMAL);
    cv::imshow( "Green Channel", bgr[1] );
}

void OpenCVHandler::blueChannelGS()
{
    //Split the input image into its 3 channels BGR
    cv::Mat bgr[3];
    cv::split(image, bgr);
    cv::namedWindow("Blue Channel", cv::WINDOW_NORMAL);
    cv::imshow( "Blue Channel", bgr[0] );
}

void OpenCVHandler::shadesOfGrayGS(int _numShades)
{
    int conversionFactor = 255/(_numShades-1);
    //Split the input image into its 3 channels BGR
    cv::Mat bgr[3];
    cv::split(image, bgr);
    cv::Mat average = (bgr[2] + bgr[1] + bgr[0])/3;
    cv::Mat gray = ((average/conversionFactor)+0.5)*conversionFactor;
    cv::namedWindow("Shades of Gray", cv::WINDOW_NORMAL);
    cv::imshow( "Shades of Gray", gray );
}



