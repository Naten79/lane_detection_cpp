#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <filesystem>
#include <chrono>
#include <string>
#include <iostream>
#include "lane_detection/preprocessing.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: lane_detection <video_path>\n";
        return 1;
    }

    const std::string videoPath { argv[1] };

    cv::VideoCapture cap(videoPath);

    // Check if the video was opened successfully
    if (!cap.isOpened()) 
    {
        std::cerr << "Error: Could not open video file." << "\n";
        return 1;
    } 
 
    const int totalFrames { static_cast<int>(cap.get(cv::CAP_PROP_FRAME_COUNT)) };
    const double fps { cap.get(cv::CAP_PROP_FPS) };
    const int width { static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH)) };
    const int height { static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT)) };
    const double duration { totalFrames / fps };

    std::cout << "Video file opened successfully! Video specifications:" <<"\n" ;
    std::cout << "Duration: " << duration << "\n";
    std::cout << "FPS: " << fps  << "\n";
    std::cout << "Height: " << height << ", Width: "<< width << "\n";


    cv::Mat frame {};
    int frameCount { 0 };

    std::filesystem::create_directories("output");
    cv::VideoWriter writer("output/result.mp4",
                       cv::VideoWriter::fourcc('m', 'p', '4', 'v'),
                       fps,
                       cv::Size(width, height));

    if (!writer.isOpened())
    {
        std::cerr << "Error: Could not open video writer." << "\n";
        return 1;
    } 

    const auto start {std::chrono::steady_clock::now()};

    while (cap.read(frame))   // lit l'image suivante ; false à la fin de la vidéo
    {
        ++frameCount;
        writer.write(frame);
        cv::imshow("Lane detection", lane_detection::toGray(frame));

        const int key { cv::waitKey(1) };   // laisse la fenêtre s'afficher, attend 1 ms
        if (key == 27 || key == 'q')        // 27 = touche Échap
        {
            break;
        }
    }

    const std::chrono::duration<double> elapsed { std::chrono::steady_clock::now() - start };
    const double seconds { elapsed.count() };
    const double processingSpeed {static_cast<double>(frameCount) / seconds};


    std::cout << frameCount << " frames processed in " << seconds << " s (" << processingSpeed << " frames/s)" << "\n";


    return 0;
}