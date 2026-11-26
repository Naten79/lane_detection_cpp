#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <string>
#include <iostream>

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

    double duration {cap.get(cv::CAP_PROP_FRAME_COUNT)/cap.get(cv::CAP_PROP_FPS)};
    std::cout << "Video file opened successfully! Video specifications:" <<"\n" ;
    std::cout << "Duration: " << duration << "\n";
    std::cout << "FPS: " << cap.get(cv::CAP_PROP_FPS)  << "\n";
    std::cout << "Height: " << cap.get(cv::CAP_PROP_FRAME_HEIGHT) << ", Width: "<< cap.get(cv::CAP_PROP_FRAME_WIDTH) << "\n";


    cv::Mat frame {};
    int frameCount { 0 };

    while (cap.read(frame))   // lit l'image suivante ; false à la fin de la vidéo
    {
        ++frameCount;
        cv::imshow("Lane detection", frame);

        const int key { cv::waitKey(1) };   // laisse la fenêtre s'afficher, attend 1 ms
        if (key == 27 || key == 'q')        // 27 = touche Échap
        {
            break;
        }
    }

    std::cout << frameCount << " frames processed\n";

    return 0;
}