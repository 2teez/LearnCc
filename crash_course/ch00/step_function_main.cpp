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

    // checking absolute value function
    int abs_result1 = absolute_value(num1);
    int abs_result2 = absolute_value(num2);
    int abs_result3 = absolute_value(num3);

    std::cout << "absolute_value(" << num1 << ") = " << abs_result1 << std::endl;
    std::cout << "absolute_value(" << num2 << ") = " << abs_result2 << std::endl;
    std::cout << "absolute_value(" << num3 << ") = " << abs_result3 << std::endl;

    return 0;
}
