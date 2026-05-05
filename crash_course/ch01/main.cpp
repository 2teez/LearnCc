// types.cpp

// A complete C++ Program
#include <iostream>
#include "types_main.hpp"

int main(int argc, char** argv)
{
    Calculator calc(Operations::Add);
    std::cout << calc.calculate(5, 3) << std::endl;

    return 0;
}
