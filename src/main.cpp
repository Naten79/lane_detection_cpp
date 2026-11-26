#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

int main()
{
    std::cout << "OpenCV " << CV_VERSION << '\n';

    // Image de 240 x 320 pixels, 3 canaux de 8 bits (couleur), fond gris foncé
    cv::Mat image(240, 320, CV_8UC3, cv::Scalar(40, 40, 40));

    // Disque orange au centre (OpenCV range les couleurs en Bleu, Vert, Rouge)
    cv::circle(image, cv::Point(160, 120), 60, cv::Scalar(0, 160, 255), cv::FILLED);

    cv::imwrite("output/test.png", image);
    std::cout << "Image ecrite dans output/test.png\n";

    return 0;
}