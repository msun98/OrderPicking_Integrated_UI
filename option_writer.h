#ifndef OPTION_WRITER_H
#define OPTION_WRITER_H

#include <string>
#include <QtDebug>
#include <opencv2/core/persistence.hpp>

#include "Common_header.h"

class Option_writer
{
public:
    Option_writer();

    bool WriteSettingFile_RB5(const std::string& file_name, jointInfo option_Joint, tcpInfo option_Tcp);
    bool ReadSettingFile_RB5(const std::string& file_name, jointInfo& option_Joint, tcpInfo& option_Tcp);
    bool NewFile_RB5(const std::string& file_name);

    bool WriteSettingFile_LIFT(const std::string& file_name, liftInfo option_Lift);
    bool ReadSettingFile_LIFT(const std::string& file_name, liftInfo& option_Lift);
    bool NewFile_LIFT(const std::string& file_name);

    bool WriteSettingFile_VISION(const std::string& file_name, xyzInfo option_Vision);
    bool ReadSettingFile_VISION(const std::string& file_name, xyzInfo& option_Vision);
    bool NewFile_VISION(const std::string& file_name);

    bool WriteSettingFile_CALIB(const std::string& file_name, tcpInfo option_Tcp);
    bool ReadSettingFile_CALIB(const std::string& file_name, tcpInfo& option_Tcp);
    bool NewFile_CALIB(const std::string& file_name);


private:
    cv::FileStorage file_storage_RB5;
    cv::FileStorage file_storage_LIFT;
    cv::FileStorage file_storage_VISION;
    cv::FileStorage file_storage_CALIB;

};

#endif // OPTION_WRITER_H
