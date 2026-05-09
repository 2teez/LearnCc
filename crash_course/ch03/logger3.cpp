
// A complete C++ Program
#include <iostream>

struct Logger
{
    virtual void log(long from, long to, double amount) const = 0;
    virtual ~Logger() = default;
};



int main()
{
    std::string hello {"Hello, World!"};
    std::cout << hello << std::endl;

    return 0;
}
