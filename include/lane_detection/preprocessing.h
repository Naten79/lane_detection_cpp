#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <opencv2/core.hpp>

namespace lane_detection {
    inline constexpr int blurKernelSize {5};
    inline constexpr int brightnessThreshold {200};

    cv::Mat toGray(const cv::Mat& frame);
}

#endif //PREPROCESSING_H