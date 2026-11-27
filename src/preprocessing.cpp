#include "lane_detection/preprocessing.h"
#include <opencv2/imgproc.hpp>
#include <vector>
namespace lane_detection {


cv::Mat toGray(const cv::Mat& frame)
{
    cv::Mat outputFrame {};
    cv::cvtColor(frame, outputFrame, cv::COLOR_BGR2GRAY);
    return outputFrame;
}

cv::Mat blur(const cv::Mat& frame, int kernelSize){
    cv::Mat outputFrame {};
    cv::Size ksize {};
    ksize.width = kernelSize;
    ksize.height = kernelSize;
    cv::GaussianBlur(frame, outputFrame, ksize, 0);
    return outputFrame;
}

cv::Mat thresholdBright(const cv::Mat& frame, int threshold){
    cv::Mat outputFrame {};
    cv::threshold(frame, outputFrame, threshold, 255, cv::THRESH_BINARY);
    return outputFrame;
}

cv::Mat applyRoi(const cv::Mat& frame)
{
    const int w { frame.cols };
    const int h { frame.rows };

    // Trapezoid covering the road, in proportion to the image size
    const std::vector<cv::Point> trapezoid {
        cv::Point(static_cast<int>(0.10 * w), h - 1),
        cv::Point(static_cast<int>(0.95 * w), h - 1),
        cv::Point(static_cast<int>(0.55 * w), static_cast<int>(0.60 * h)),
        cv::Point(static_cast<int>(0.45 * w), static_cast<int>(0.60 * h))
    };

    // Black image of the same size, with the trapezoid filled in white
    cv::Mat roiMask = cv::Mat::zeros(frame.size(), frame.type());
    cv::fillPoly(roiMask, std::vector<std::vector<cv::Point>> { trapezoid }, cv::Scalar(255));

    // Keep only the pixels that are white in both images
    cv::Mat output {};
    cv::bitwise_and(frame, roiMask, output);
    return output;
}

cv::Mat preprocess(const cv::Mat& frame)
{
    const cv::Mat gray = toGray(frame);
    const cv::Mat blurred = blur(gray, blurKernelSize);
    const cv::Mat mask = thresholdBright(blurred, brightnessThreshold);
    return applyRoi(mask);
}

}
