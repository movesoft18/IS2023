#include <iostream>
#include <fstream>
#include <time.h>
#include "Logger.h"

using namespace std;
// Функция, возвращающая по ссылке текущую дату и время в виде набора инициализированных переменных
// Не будем углубляться в суть данной функции, в рамках нашей задачи это неважно. Считайте что она есть.
void GetDateTime(string& w_day, int& day, int& month, int& year, int& hour, int& min, int& sec)
{
    time_t tt = time(NULL);
    tm tk;
    localtime_s(&tk, &tt);
    switch (tk.tm_wday)
    {
    case 0:
        w_day = "Sun";
        break;
    case 1:
        w_day = "Mon";
        break;
    case 2:
        w_day = "Tue";
        break;
    case 3:
        w_day = "Wed";
        break;
    case 4:
        w_day = "Thu";
        break;
    case 5:
        w_day = "Fri";
        break;
    case 6:
        w_day = "Sat";
        break;
    }
    year = tk.tm_year + 1900;
    day = tk.tm_mday;
    month = tk.tm_mon + 1;
    hour = tk.tm_hour;
    min = tk.tm_min;
    sec = tk.tm_sec;
}

// Реализация по умолчанию чисто виртуальной функции запуска лога
bool LoggerBase::StartLog()
{
    int day, month, year, hour, min, sec;
    string w_day;
    // получаем текущую дату и время
    GetDateTime(w_day, day, month, year, hour, min, sec);
    // выводим в поток сообщение о начале логгирования с указанием даты и времени запуска
    *stream << "---------------- Logging started in " << w_day << " " << day << "-" << month << "-"

        << year << " at " << hour << ":" << min << ":" << sec << endl;

    // возвращаем true, если операция прошла успешно, и false если не успешно

    return !stream->fail();

}

// Реализация по умолчанию чисто виртуальной функции остановки лога
bool LoggerBase::StopLog()
{
    int day, month, year, hour, min, sec;
    string w_day;
    // получаем текущую дату и время
    GetDateTime(w_day, day, month, year, hour, min, sec);
    // выводим в поток сообщение об остановке логгирования с указанием даты и времени остановки
    *stream << "---------------- Logging stopped in " << w_day << " " << day << "-" << month << "-"
        << year << " at " << hour << ":" << min << ":" << sec << endl;
    // возвращаем true, если операция прошла успешно, и false если не успешно
    return !stream->fail();
}

// Реализация по умолчанию чисто виртуальной функции вывода сообщения в лог
bool LoggerBase::Log(const string& Message)
{
    int day, month, year, hour, min, sec;
    string w_day;
    // получаем текущую дату и время
    // выводим в поток сообщение с указанием даты и времени
    GetDateTime(w_day, day, month, year, hour, min, sec);
    *stream << w_day << " " << day << "-" << month << "-"
        << year << " " << hour << ":" << min << ":" << sec << "  LOGOUT: " << Message << endl;
    // возвращаем true, если операция прошла успешно, и false если не успешно
    return !stream->fail();
}

// Конструктор консольного логгера. Связывает поток stream с потоком вывода ошибок std::cerr
ConsoleLogger::ConsoleLogger() : isStarted(false)
{
    stream = &std::cerr;
}



// Деструктор. останавливает лог, если он запущен

ConsoleLogger::~ConsoleLogger()
{
    if (isStarted) StopLog();
}



// Запуск консольного логгера
bool ConsoleLogger::StartLog()
{
    // проверяем запущен ли лог, и если нет запускаем, устанавливаем флаг isStarted и выводим сообщение о старте
    if (!isStarted)
    {
        // заметьте - здесь мы используем реализацию по умолчанию!!!!
        // она выводит в указанный поток сообщение о старте логгирования
        isStarted = LoggerBase::StartLog();
        return isStarted;
    }
    return true;
}

// остановка консольного логгера
bool ConsoleLogger::StopLog()
{
    // проверяем запущен ли
    if (isStarted)
    {
        // выводим сообщение об остановке логгера (используя функционал чисто виртуальной функции по умолчанию)
        LoggerBase::StopLog();
        isStarted = false;
        return true;
    }
    return false;
}

// Вывод сообщения лога в консоль
bool ConsoleLogger::Log(const string& Message)
{
    // если лог запущен
    if (isStarted)
    {
        // выводим сообщение в консоль, используя функционал чисто виртуальной функции по умолчанию
        return LoggerBase::Log(Message);
    }
    return false;
}



// Файловый логгер, старт лога
bool FileLogger::StartLog()
{
    // проверяем, открыт ли файл, связанный с потоком f, и если открыт, то ничего не делаем
    if (f.is_open()) return true;
    // если включен режим дозаписи
    if (append)
        // открываем файл для дозаписи
        f.open(filename, ios::app);
    else
        // иначе создаем файл вновь
        f.open(filename);
    if (f) // если файл успешно создан или открыт для дозаписи
    {
        // связываем поток stream с открытым файловым потоком
        stream = &f;
        // выводим сообщение о старте лога
        return LoggerBase::StartLog();
    }
    else
        return false;
}



// Деструктор, закрывает лог и связанный с ним файл, если лог не закрыт
FileLogger::~FileLogger()
{
    if (f.is_open()) StopLog();
}


// Остановка файлового логгера
bool FileLogger::StopLog()
{
    if (f) // если файл открыт, то
    {
        // выводим сообщение об остановке лога
        LoggerBase::StopLog();
        // закрываем файл лога
        f.close();
        return true;
    }
    else
        return false;
}

// Вывод лога в файл
bool FileLogger::Log(const string& Message)
{
    if (f) // если файл открыт
    {
        // выводим сообщение в лог
        return LoggerBase::Log(Message);
    }
    else
        return false;
}



// Пустой логгер. Все его методы ничего не выводят. Всегда возвращают true
NullLogger::~NullLogger() {}
bool NullLogger::StartLog() { return true; }
bool NullLogger::StopLog() { return true; }
bool NullLogger::Log(const string& Message) { return true; }

// Объявляем экземпляр класса NullLogger. В заголовочном файле он объявлен как extern, потому что по факту он объявлен здесь
// а не в заголовке

NullLogger nullLogger;