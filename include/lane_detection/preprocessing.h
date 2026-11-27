#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <opencv2/core.hpp>

namespace lane_detection {
    inline constexpr int blurKernelSize {9};
    inline constexpr int brightnessThreshold {200};

    cv::Mat toGray(const cv::Mat& frame);
    cv::Mat blur(const cv::Mat& frame, int kernelSize);
    cv::Mat thresholdBright(const cv::Mat& frame, int threshold);
    cv::Mat applyRoi(const cv::Mat& frame);
    cv::Mat preprocess(const cv::Mat& frame);
}

#endif //PREPROCESSING_H