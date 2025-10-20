// prime_numbers.cpp

// A complete C++ Program
#include <iostream>
#include <cstdbool>
#include <iomanip>
#include <cmath>

bool is_prime(const int number);

inline const std::string tell_bool_value(int value)
{
    return (value == 0) ? "false" : "true";
}

void find_all_prime_numbers(int from, int to);

typedef double (*square_root)(double);
// using square_root = double (*)(double);

void show_square_root_btw(int, int, square_root);

int main(int argc, char** argv)
{

    find_all_prime_numbers(1, 100);
    show_square_root_btw(1, 99, std::sqrt);

    return 0;
}

bool is_prime(const int number)
{
    if (number < 2)
    {
        return false;
    }

    for (int i = 2; i <= std::sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

void find_all_prime_numbers(int from, int to)
{
    for (int i = from; i < to; i++)
    {
        bool result = is_prime(i);
        if (result)
        {
            std::cout << i << std::setw(10) << tell_bool_value(result) << std::endl;
        }
    }
}

void show_square_root_btw(int from, int to, square_root fn)
{
    for (int i = from; i < to; i++)
    {
        std::cout << i << std::setw(10) << fn(static_cast<double>(i)) << std::endl;
    }
}
