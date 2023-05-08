#include "telnetclient.h"


telnetclient::telnetclient(QObject *parent) : QThread(parent)
{
    cout << "Hi telnet" << endl;
    serverMessage_Flag = true;

//    telent_signal= "telentClinetThread opened";
}

void telnetclient::run()
{
    RunTelnetClient();
}

int i=0;
void telnetclient::RunTelnetClient()
{

#ifdef POSIX
    termios stored_settings;
    tcgetattr(0, &stored_settings);
    termios new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_lflag &= (~ISIG); // don't automatically handle control-C
    tcsetattr(0, TCSANOW, &new_settings);
#endif

    std::string dest_ip;
    std::string dest_port;
    dest_ip = "192.168.1.20";//"192.168.1.32";
    dest_port = "7171";

    try
    {
        std::cout << "SimpleTelnetClient is tring to connect " << dest_ip << ":" << dest_port << std::endl;
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(dest_ip, dest_port);
        tcp::resolver::iterator iterator = resolver.resolve(query);

        AsioTelnetClient telnet_client(io_service, iterator);

        telnet_client.setReceivedSocketCallback([&](const std::string& message)
        {
            qDebug() << "From server - " << QString::fromStdString(message);

            if(QString::fromStdString(message) == "Enter password:\r\n")
            {
                serverMessage_Flag = true;
                sendCommand = "rainbow";
                flag = 1;
//                cout<<message<<endl;
            }
            serverMessage = message; //must use dont modify
        });

        telnet_client.setClosedSocketCallback([]()
        {
            std::cout << " # disconnected" << std::endl;
        });

        while (1)
        {
            char ch;
//
            if(flag == 1)
            {
                char a[sendCommand.length()];
//                cout<<sendCommand<<endl;

                for(int i=0;i<sizeof(a);i++)
                {
                    a[i] = sendCommand[i];
                    telnet_client.write(a[i]);
                }

                ch = '\n';
                telnet_client.write(ch);

                flag = 0;
            }
            usleep(10*1000);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
#ifdef POSIX // restore default buffering of standard input
    tcsetattr(0, TCSANOW, &stored_settings);
#endif
}
