// Bridge.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <string>
using namespace std;

// Опережающее объявление
class LoggerImpl;

class Logger
{
public:
    Logger(LoggerImpl* p);
    virtual ~Logger();
    virtual void log(const string& str) = 0;
protected:
    LoggerImpl* pimpl;
};

class ConsoleLogger : public Logger
{
public:
    ConsoleLogger();
    void log(const string& str);
};

class FileLogger : public Logger
{
public:
    FileLogger(const string& file_name);
    void log(const string& str);
private:
    string file;
};

class SocketLogger : public Logger
{
public:
    SocketLogger(const string& remote_host, int remote_port);
    void log(const string& str);
private:
    string host;
    int    port;
};


// Logger.cpp - Абстракция

Logger::Logger(LoggerImpl* p) : pimpl(p)
{ }

Logger::~Logger()
{
    delete pimpl;
}

ConsoleLogger::ConsoleLogger() : Logger(
#ifdef MT
    new MT_LoggerImpl()
#else
    new ST_LoggerImpl()
#endif
)
{ }

void ConsoleLogger::log(const string& str)
{
    pimpl->console_log(str);
}

FileLogger::FileLogger(const string& file_name) : Logger(
#ifdef MT
    new MT_LoggerImpl()
#else
    new ST_LoggerImpl()
#endif
), file(file_name)
{ }

void FileLogger::log(const string& str)
{
    pimpl->file_log(file, str);
}

SocketLogger::SocketLogger(const string& remote_host,
    int remote_port) : Logger(
#ifdef MT
        new MT_LoggerImpl()
#else
        new ST_LoggerImpl()
#endif
    ), host(remote_host), port(remote_port)
{ }

void SocketLogger::log(const string& str)
{
    pimpl->socket_log(host, port, str);
}

class LoggerImpl
{
public:
    virtual ~LoggerImpl() {}
    virtual void console_log(const string& str) = 0;
    virtual void file_log(
        const string& file, const string& str) = 0;
    virtual void socket_log(
        const string& host, int port, const string& str) = 0;
};

class ST_LoggerImpl : public LoggerImpl
{
public:
    void console_log(const string& str);
    void file_log(const string& file, const string& str);
    void socket_log(
        const string& host, int port, const string& str);
};

class MT_LoggerImpl : public LoggerImpl
{
public:
    void console_log(const string& str);
    void file_log(const string& file, const string& str);
    void socket_log(
        const string& host, int port, const string& str);
};


// LoggerImpl.cpp - Реализация

void ST_LoggerImpl::console_log(const string& str)
{
    cout << "Single-threaded console logger" << endl;
}

void ST_LoggerImpl::file_log(const string& file, const  string& str)
{
    cout << "Single-threaded file logger" << endl;
}

void ST_LoggerImpl::socket_log(
    const string& host, int port, const string& str)
{
    cout << "Single-threaded socket logger" << endl;
};

void MT_LoggerImpl::console_log(const string& str)
{
    cout << "Multithreaded console logger" << endl;
}

void MT_LoggerImpl::file_log(const string& file, const string& str)
{
    cout << "Multithreaded file logger" << endl;
}

void MT_LoggerImpl::socket_log(
    const string& host, int port, const string& str)
{
    cout << "Multithreaded socket logger" << endl;
}


// Main.cpp

int main()
{
    Logger* p = new FileLogger("log.txt");
    p->log("message");
    delete p;
    return 0;
}