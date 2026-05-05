// types.cpp

// A complete C++ Program
#include <iostream>
#include "types_main.hpp"

int main(int argc, char** argv)
{
    Calculator calc(Operations::Add);
    std::cout << calc.calculate(5, 3) << std::endl;
    //
    Calculator calc2 {Operations::Subtract};
    std::cout << calc2.calculate(5, 3) << std::endl;
    //
    Calculator calc3 {Operations::Multiply};
    std::cout << calc3.calculate(5, 3) << std::endl;
    //
    Calculator calc4 {Operations::Divide};
    std::cout << calc4.calculate(5, 3) << std::endl;

    return 0;
}
