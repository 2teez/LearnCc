
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
    ConsoleLogger(const char* name): m_name{name}
    {
        if (name == nullptr)
        {
            throw std::invalid_argument("name cannot be null");
        }
    }
    ConsoleLogger(const ConsoleLogger&) = default;
    ConsoleLogger(ConsoleLogger&&) noexcept = default;
    ConsoleLogger& operator=(const ConsoleLogger&) = default;
    ConsoleLogger& operator=(ConsoleLogger&&) noexcept = default;
    ~ConsoleLogger() = default;
    void log(long from, long to, double amount) const override
    {
        std::cout << m_name << " " << from << " -> " << to << ": "
            << std::setw(5) << std::fixed << amount << "\n";
    }

private:
    const char* m_name;
};

struct AccountDatabase
{
    virtual void set_amount(long id,double amount) = 0;
    virtual double get_amount(long id) const = 0;
    virtual ~AccountDatabase() = default;
};

struct InMemoryDatabase : AccountDatabase
{
    InMemoryDatabase(int size): m_size{size}
    {
        m_data = new double[size]{};
    }

    InMemoryDatabase(const InMemoryDatabase& other): m_size{other.m_size}
    {
        m_data = new double[m_size]{};
        for (int i = 0; i < m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }

    InMemoryDatabase(InMemoryDatabase&& other) noexcept: m_data{other.m_data}, m_size{other.m_size}
    {
        other.m_data = nullptr;
        other.m_size = 0;
    }

    InMemoryDatabase& operator=(const InMemoryDatabase& other)
    {
        if (this != &other)
        {
            delete[] m_data;
            m_size = other.m_size;
            m_data = new double[m_size]{};
            for (int i = 0; i < m_size; ++i)
            {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }

    InMemoryDatabase& operator=(InMemoryDatabase&& other) noexcept
    {
        if (this != &other)
        {
            delete[] m_data;
            m_size = other.m_size;
            m_data = other.m_data;
            other.m_data = nullptr;
            other.m_size = 0;
        }

        return *this;
    }

    ~InMemoryDatabase()
    {
        delete[] m_data;
    }

    void set_amount(long id, double amount) override
    {
        m_data[id] = amount;
    }

    double get_amount(long id) const override
    {
        return m_data[id];
    }

private:
    double* m_data;
    int m_size;
};

struct Bank
{
    Bank(Logger& logger, AccountDatabase& database): m_logger{&logger}, m_database{database}
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
        m_database.set_amount(from, m_database.get_amount(from) - amount);
        m_database.set_amount(to, m_database.get_amount(to) + amount);
    }

private:
    Logger* m_logger;
    AccountDatabase& m_database;
};


int main()
{
    ConsoleLogger console_logger {"[Cons]"};
    InMemoryDatabase database {5};
    Bank bank{console_logger, database };
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
    FileLogger file_logger {};
    bank.set_logger(file_logger);
    bank.make_transfer(3000, 2000, 75.00);

    return 0;
}
