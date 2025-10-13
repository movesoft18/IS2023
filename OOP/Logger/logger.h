#pragma once

#include <string>
#include <iostream>
#include <fstream>
using std::string;
using std::ofstream;
using std::ostream;

// Это интерфейс, в котором объявлен функционал логгера
// Логгер может быть запущен, остановлен или с его помощью можно
// вывести сообщение о некотором событии
// В интерфейсе присутствуют только чисто виртуальные функции

class ILogger
{
public:
    virtual bool StartLog() = 0;
    virtual bool StopLog() = 0;
    virtual bool Log(const string& Message) = 0;
    virtual ~ILogger() = default;
};

// а вот это уже абстрактный класс, созданный на основе интерфейса
// от определяет, что все классы в иерархии для вывода будут использовать
// поток ostream
// также он будет предоставлять реализации чисто виртуальных функций по умолчанию

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
// это класс файлового логгера, который выводит сообщения в указанный файл

class FileLogger : public LoggerBase
{
    ofstream f; // поток вывода
    string filename; // имя файла лога
    bool append;    // режим вывода лога - дозапись или создание файла вновь
public:
    FileLogger(const string& filename, bool append = false) : filename(filename), append(append) {}
    virtual ~FileLogger();
    bool StartLog() override;
    bool StopLog() override;
    bool Log(const string& Message) override;
};



// Консольный логгер, выводит сообщения о событиях в консоль
class ConsoleLogger : public LoggerBase
{
    bool isStarted; // признак того, что логгер запущен
public:
    ConsoleLogger();
    virtual~ConsoleLogger();
    bool StartLog() override;
    bool StopLog() override;
    bool Log(const string& Message) override;
};

// Пустой логгер - заглушка, который используется если логгирование производить не нужно
class NullLogger : public ILogger
{
public:
    NullLogger() {}
    virtual ~NullLogger();
    bool StartLog() override;
    bool StopLog() override;
    bool Log(const string& Message) override;
};
// объявляем созданный в файле реализации Logger.cpp пустой логгер
// чтобы использующие логгер программы не тратили время на его создание

extern NullLogger nullLogger;
