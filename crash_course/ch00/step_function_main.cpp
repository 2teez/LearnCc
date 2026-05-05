// step_function_main.cpp

// A complete C++ Program
#include <iostream>
#include "step_function.hpp"

int main(int argc, char** argv)
{

    int num1 = 42,
        num2 = 0,
        num3 = -32768;

    int result1 = step_function(num1);
    int result2 = step_function(num2);
    int result3 = step_function(num3);

    std::cout << "step_function(" << num1 << ") = " << result1 << std::endl;
    std::cout << "step_function(" << num2 << ") = " << result2 << std::endl;
    std::cout << "step_function(" << num3 << ") = " << result3 << std::endl;

    return 0;
}
