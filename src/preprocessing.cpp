#include "lane_detection/preprocessing.h"
#include <opencv2/imgproc.hpp>

cv::Mat lane_detection::toGray(const cv::Mat& frame)
{
    cv::Mat outputFrame {};
    cv::cvtColor(frame, outputFrame, cv::COLOR_BGR2GRAY);
    return outputFrame;
}



