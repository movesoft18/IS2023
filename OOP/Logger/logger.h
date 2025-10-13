#pragma once

#include <string>
#include <iostream>
#include <fstream>
using std::string;
using std::ofstream;
using std::ostream;

// ��� ���������, � ������� �������� ���������� �������
// ������ ����� ���� �������, ���������� ��� � ��� ������� �����
// ������� ��������� � ��������� �������
// � ���������� ������������ ������ ����� ����������� �������

class ILogger
{
public:
    virtual bool StartLog() = 0;
    virtual bool StopLog() = 0;
    virtual bool Log(const string& Message) = 0;
    virtual ~ILogger() = default;
};

// � ��� ��� ��� ����������� �����, ��������� �� ������ ����������
// �� ����������, ��� ��� ������ � �������� ��� ������ ����� ������������
// ����� ostream
// ����� �� ����� ������������� ���������� ����� ����������� ������� �� ���������

class LoggerBase : public ILogger
{
protected:
    ostream* stream;
public:
    virtual ~LoggerBase() {}
    bool StartLog() override = 0;
    bool StopLog() override = 0;
    bool Log(const string& Message) override = 0;
};
// ��� ����� ��������� �������, ������� ������� ��������� � ��������� ����

class FileLogger : public LoggerBase
{
    ofstream f; // ����� ������
    string filename; // ��� ����� ����
    bool append;    // ����� ������ ���� - �������� ��� �������� ����� �����
public:
    FileLogger(const string& filename, bool append = false) : filename(filename), append(append) {}
    virtual ~FileLogger();
    bool StartLog() override;
    bool StopLog() override;
    bool Log(const string& Message) override;
};



// ���������� ������, ������� ��������� � �������� � �������
class ConsoleLogger : public LoggerBase
{
    bool isStarted; // ������� ����, ��� ������ �������
public:
    ConsoleLogger();
    virtual~ConsoleLogger();
    bool StartLog() override;
    bool StopLog() override;
    bool Log(const string& Message) override;
};

// ������ ������ - ��������, ������� ������������ ���� ������������ ����������� �� �����
class NullLogger : public ILogger
{
public:
    NullLogger() {}
    virtual ~NullLogger();
    bool StartLog() override;
    bool StopLog() override;
    bool Log(const string& Message) override;
};
// ��������� ��������� � ����� ���������� Logger.cpp ������ ������
// ����� ������������ ������ ��������� �� ������� ����� �� ��� ��������

extern NullLogger nullLogger;
