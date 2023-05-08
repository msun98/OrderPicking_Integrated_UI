#include <iostream>
#include <QDebug>
#include "log_writer.h"

//#

#ifdef _WIN64
#include <filesystem>
Log_writer::Log_writer()
{
    experimental::filesystem::path log_path("./_log");
    if (!experimental::filesystem::exists(log_path)) {
        create_directory(log_path);
    }

    QString date_and_time = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    string log_file_name = date_and_time.toStdString();
    log_file_name_ = "_log/" + log_file_name + "-log-list.html";

    //css 파일 생성
    if(!experimental::filesystem::exists("_log/log_styles.css")){
        qDebug()<<"not exist";
        FILE* pFile;
        pFile = fopen("_log/log_styles.css", "a");
        fprintf(pFile, "*{margin:0px}");
        fprintf(pFile,"p{font-family: 'Spoqa Han Sans', snan-serif;}");
        fclose(pFile);
    }

    //로그 파일 첫 생성 시 스타일 옵션
    if(!experimental::filesystem::exists(log_file_name_)){
        qDebug()<<"not exist";
        FILE* pFile;
        pFile = fopen(log_file_name_.c_str(), "a");
        fprintf(pFile, "<link rel=\"stylesheet\" href=\"log_styles.css\"><link>");
        fprintf(pFile, "<body bgcolor=\"#252831\"></body>");

        fclose(pFile);
    }
}
#elif __linux__
#include <QDir>
Log_writer::Log_writer()
{
    QDir log_folder_path("/_log");
    //로그 폴더 생성
    if(!log_folder_path.exists()){
        log_folder_path.mkdir("/_log");
    }


    QString date_and_time = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    string log_file_name = date_and_time.toStdString();
    log_file_name_ = "_log/" + log_file_name + "-log-list.html";

    //css 파일 생성
    QDir css_path("_log/log_styles.css");
    if(!css_path.exists()){
        qDebug()<<"not exist";
        FILE* pFile;
        pFile = fopen("_log/log_styles.css", "w");
        fprintf(pFile, "*{margin:0px}");
        fprintf(pFile,"p{font-family: 'Spoqa Han Sans', snan-serif;}");
        fclose(pFile);
    }

    //로그 파일 첫 생성 시 스타일 옵션
    QDir log_file_path(QString::fromStdString(log_file_name_));
    if(!log_file_path.exists()){
        qDebug()<<"not exist";
        FILE* pFile;
        pFile = fopen(log_file_name_.c_str(), "a");
        fprintf(pFile, "<link rel=\"stylesheet\" href=\"log_styles.css\"><link>");
        fprintf(pFile, "<body bgcolor=\"#252831\"></body>");

        fclose(pFile);
    }
}
#endif

Log_writer::~Log_writer()
{

}


void Log_writer::PrintLog(string user_log, QTextEdit *textEditLog, string color_code, bool time, bool hide)
{
    logWithHtml(textEditLog, user_log, color_code, time, hide);
}

void Log_writer::PrintLogList(vector<string> user_log_list, QTextEdit *textEditLog, string color_code, bool time, bool hide)
{
    for (auto ele : user_log_list) {
        logWithHtml(textEditLog, ele, color_code, time, hide);
    }
}


void Log_writer::logWithHtml(QTextEdit *textEditLog, string msg, string color_code, bool time, bool hide)
{
    string log_for_write;
    log_for_write = (time) ? logWithTime(msg) : msg;
    string style_font = "<font color=" + color_code+">" + log_for_write+"</font>";
    writeLogFile("<p>" + style_font +"</p>");
    if (!hide){
        textEditLog->append(QString::fromStdString(style_font));
    }

}

void Log_writer::writeLogFile(string log)
{
    FILE* pFile;
    pFile = fopen(log_file_name_.c_str(), "a");
    fprintf(pFile, log.c_str());
    fclose(pFile);
}


string Log_writer::logWithTime(string msg)
{
    QString time = QTime::currentTime().toString("hh:mm:ss:zzz");;
    QString log = "[" + time + "] " + QString::fromStdString(msg);
    string log_for_write = log.toStdString();

    return log_for_write;
}


