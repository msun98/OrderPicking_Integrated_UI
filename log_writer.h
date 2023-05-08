#ifndef LOG_WRITER_H
#define LOG_WRITER_H

#include <string>
#include <vector>
#include <QTextEdit>
#include <QTime>
#include <QDateTime>

using namespace std;
class Log_writer
{
public:
    Log_writer();
    ~Log_writer();
    inline void SetLogFileName(string filename) { log_file_name_ = filename + ".html"; }
    void PrintLog(string user_log, QTextEdit *textEditLog, string color_code="white", bool time = true, bool hide=false);
    void PrintLogList(vector<string> user_log_list, QTextEdit *textEditLog, string color_code="white", bool time = true, bool hide=false);

private:

    //�α�
    void logWithHtml(QTextEdit *textEditLog, string msg, string color_code, bool time=true, bool hide=false);
    string logWithTime(string msg);
    void writeLogFile(string log);

    string log_file_name_;
    string log_;
    vector<string> log_list_;
};

#endif // LOG_WRITER_H
