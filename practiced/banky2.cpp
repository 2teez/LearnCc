// banky2.cpp

// A complete C++ Program
#include <iostream>
#include <memory>

struct Logger
{
    Logger() = default;
    //Logger& operator=(const Logger&) = default;
    //Logger& operator=(Logger&&) = default;
    virtual ~Logger() = default;
    virtual void log(int, int, double) const = 0;
};

struct FileLogger: Logger
{
    void log(int from, int to, double amount) const override
    {
        std::cout << "[File]" << from <<","<< to <<","<< amount << "\n";
    }
};


struct ConsoleLogger: Logger
{
    void log(int from, int to, double amount) const override
    {
        std::cout << "[Console]" << from <<" -> "<< to <<": "<< amount << "\n";
    }
};

struct Bank
{
    Bank(): log {std::make_unique<ConsoleLogger>()} {}
    void set_logger(std::unique_ptr<Logger> log)
    {
        this->log = std::move(log);
    }
    void make_transfer(int from, int to, double amount) const
    {
        log->log(from, to, amount);
    }
    private:
        std::unique_ptr<Logger> log;
};

int main(int argc, char** argv)
{

    Bank bank;
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.0);
    bank.set_logger(std::make_unique<FileLogger>());
    bank.make_transfer(3000, 2000, 75.00);

    return 0;
}
