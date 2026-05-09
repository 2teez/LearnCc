
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

struct Bank
{
    Bank(): m_logger{new ConsoleLogger{}}
    {}

    void set_logger(Logger* logger)
    {
        if (m_logger)
        {
            delete m_logger;
        }
        m_logger = logger;
    }

    void make_transfer(long from, long to, double amount)
    {
        if (m_logger)
        {
            m_logger->log(from, to, amount);
        }
    }

private:
    Logger* m_logger = nullptr;
};


int main()
{
    Bank bank;
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
    bank.set_logger(new FileLogger{});
    bank.make_transfer(3000, 2000, 75.00);

    return 0;
}
