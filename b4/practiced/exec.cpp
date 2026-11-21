// exec.cpp

// A complete C++ Program
#include <iostream>
#include <cmath>
#include <iomanip>

double hypot(double, double);
int str_size(const char*);

int main(int argc, char** argv)
{

    std::cout << hypot(4, 5) << std::endl;
    std::cout << hypot(5, 6) << std::endl;
    std::cout << strlen("mit-javame") << std::setw(10) << str_size("mit-javame") << std::endl;
    return 0;
}

double hypot(const double &adj, const double &opp)
{
    return sqrt(pow(adj, 2.0) + pow(opp, 2));
}

int str_size(const char* str)
{
    size_t len = 0;
    if (!*str) return len;
    while(*str++)
    {
        ++len;
    }
    return len;
}
