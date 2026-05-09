
// A complete C++ Program
#include <iostream>
#include <iomanip>

struct FileLogger
{
    static void log(long from, long to, double amount)
    {
        std::cout << "[File] " << from << " -> " << to << ": "
		<< std::setw(5) << amount << "\n";
    }
};

struct ConsoleLogger
{
    static void log(long from, long to, double amount)
    {
        std::cout << "[Cons] " << from <<" -> " << to << ": "
		<< std::setw(5) << std::setprecision(6)<< std::fixed << amount << "\n";
    }
};

enum class LoggerType
{
	File,
	Console
};

struct Bank
{
	Bank(): type{LoggerType::Console}
	{}
	void set_logger(LoggerType logger)
	{
		type = logger;
	}

	void make_transfer(long from, long to, double amount) const
	{
		switch(type)
		{
			case LoggerType::Console:
				ConsoleLogger::log(from, to, amount);
				break;
			case LoggerType::File:
				FileLogger::log(from, to, amount);
				break;
			default:
				throw std::logic_error {"Unreconginized logger type."};
				break;
		}
	}

	private:
		LoggerType type;
};

int main()
{
    Bank bank;
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
    bank.set_logger(LoggerType::File);
    bank.make_transfer(3000, 2000, 75.00);
	return 0;
}
