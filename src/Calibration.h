//
// Created by Piotr Meller on 14.11.18.
//

#ifndef PRACA_INZYNIERSKA_CALIBRATION_H
#define PRACA_INZYNIERSKA_CALIBRATION_H

#include <opencv2/core.hpp>

class Calibration
{
    cv::Mat cameraMatrix;
    cv::Mat distortionCoefficient;

public:
    Calibration(std::string filename);
    ~Calibration();

    cv::Mat getCameraMatrix();
    cv::Mat getDistortionCoefficient();

    void calibrateCamera(std::vector<std::string> image_path_list, cv::Size patern_size);

    cv::Mat undistort(const cv::Mat &img);
};

#endif //PRACA_INZYNIERSKA_CALIBRATION_H

