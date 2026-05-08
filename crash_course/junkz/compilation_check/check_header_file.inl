
#include <iostream>
#include "check_header_file.hpp"

template <typename T>
void printfln(const T value)
{
    std::cout << value << std::endl;
}

template <typename T>
void printf(const T value)
{
    std::cout << value;
}
