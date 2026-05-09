
// A complete C++ Program
#include <iostream>
#include <iomanip>

struct Logger
{
    virtual void log(long from, long to, double amount) const = 0;
    virtual ~Logger() = default;
};

struct FileLogger : Logger
{
    void log(long from, long to, double amount) const override
    {
        std::cout << "[File] " << from << " -> " << to << ": "
            << std::setw(5) << std::fixed << amount << "\n";
    }
};

struct ConsoleLogger : Logger
{
    void log(long from, long to, double amount) const override
    {
        std::cout << "[Cons] " << from << " -> " << to << ": "
            << std::setw(5) << std::fixed << amount << "\n";
    }
};

struct AccountDatabase
{
    virtual void set_amount(long id,double amount) = 0;
    virtual double get_amount(long id) const = 0;
    virtual ~AccountDatabase() = default;
};

struct Bank
{
    Bank(Logger& logger): m_logger{&logger}
    {}

    Bank(const Bank&) = delete;
    Bank& operator=(const Bank&) = delete;
    Bank(Bank&&) = delete;
    Bank& operator=(Bank&&) = delete;
    ~Bank() = default;

    void set_logger(Logger& logger)
    {
        m_logger = &logger;
    }

    void make_transfer(long from, long to, double amount) const
    {
        m_logger->log(from, to, amount);
    }

private:
    Logger* m_logger;
};


int main()
{
    ConsoleLogger console_logger {};
    Bank bank{console_logger};
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
    FileLogger file_logger {};
    bank.set_logger(file_logger);
    bank.make_transfer(3000, 2000, 75.00);

    return 0;
}
