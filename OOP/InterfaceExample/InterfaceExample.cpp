#include <iostream>
#include <string>
using namespace std;

class IMoveable
{
    virtual void getPosition() const  = 0;
    virtual void move(int newX, int newY) = 0;
};

class IErrorlogger
{
public:
    virtual bool openLog(const string& fileName) = 0;
    virtual bool closeLog() = 0;
    virtual bool writeError(const string& message) = 0;
    virtual ~IErrorlogger() = default;
};

struct LEResult
{
	double root;	// корень уравнения, если есть
	int count;		// количество корней 0 - нет корней, 1 - 1 корень, 3 - бесконечное множество
};

LEResult LinearEquation(
	double a, 
	double b, 
	IErrorlogger* logger = nullptr
)
{
	if (a == 0)
	{
		if (b == 0)
		{
			if (logger) logger->writeError("Бесконечное множество корней");
			return LEResult{ 0, 3 };
		}
		else
		{
			if (logger) logger->writeError("Нет корней");
			return LEResult{ 0, 0 };
		}
	}
	if(logger) logger->writeError("1 корень");
	return LEResult{ b / a, 1 };
}

int main()
{
	auto res = LinearEquation(3, 4);
	FileLogger logger = new FileLogger();
	logger->openLog();
	res = LinearEquation(3, 4, logger);
	logger->closeLog();
	delete logger;
}

