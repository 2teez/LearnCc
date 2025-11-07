// banky.cpp

// A complete C++ Program

#include <functional>
#include <iostream>
//#include <memory>

struct Log{
    virtual void log(int, int, double) const = 0;
    virtual ~Log() = default;
};

struct FileLog: public Log {
  void log(int from, int to, double amount) const override
  {
      std::cout << "[FileL:] " << from <<","<< to <<","<< amount << "\n";
  }
};

struct ConsoleLog: public Log {
  void log(int from, int to, double amount) const override
  {
      std::cout << "[ConsL:] " << from <<" -> "<< to <<": "<< amount << "\n";
  }
};

struct FileLogger
{
    void print(int from, int to, double amount) const
    {
        std::cout << "[File:] " << from <<","<< to <<","<< amount << "\n";
    }
};

struct ConsoleLogger
{
    void print(int from, int to, double amount) const
    {
        std::cout << "[cons:] " << from <<" -> "<< to <<": "<< amount << "\n";
    }
};

enum class LoggerType
{
    FileLogger,
    ConsoleLogger,
};

struct Bank
{
    public:
    Bank(): log{LoggerType::ConsoleLogger} {}
    void set_logger(LoggerType new_log)
    {
        log = new_log;
    }

    void make_transfer(
        int from,
        int to,
        double amount,
        Log* used_log) const
    {
        used_log->log(from, to, amount);
    }


    void make_transfer(
        int from, int to, double amount,
        std::function<LoggerType(int, int, double)> used_log
        /*LoggerType (*used_log)(int, int, double)*/) const
    {
        switch(log)
        {
            case LoggerType::FileLogger:
              used_log(from, to, amount);
            break;
            case LoggerType::ConsoleLogger:
              used_log(from, to, amount);
            break;
        }
    }
    void make_transfer(int from, int to, double amount) const
    {
        switch(log)
        {
            case LoggerType::FileLogger:
              file_log.print(from, to, amount);
            break;
            case LoggerType::ConsoleLogger:
              cons_log.print(from, to, amount);
            break;
        }
    }
    private:
       LoggerType log;
       FileLogger file_log;
       ConsoleLogger cons_log;
};

int main(int argc, char** argv)
{
    Bank bank;
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.0);
    bank.set_logger(LoggerType::FileLogger);
    bank.make_transfer(3000, 2000, 75.00);
    // using interface, inheritance & polymorphsim
    auto clog = ConsoleLog();
    bank.make_transfer(3000, 2000, 75.00, &clog);
    auto flog = FileLog();
    bank.make_transfer(3000, 2000, 75.00, &flog);
    return 0;
}
