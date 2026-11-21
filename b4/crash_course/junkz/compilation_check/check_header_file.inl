
#include <iostream>
#include "check_header_file.hpp"

template <typename T>
void printfln(const T value, std::ostream& os)
{
    os << value << std::endl;
}

template <typename T>
void printf(const T value, std::ostream& os)
{
    os << value;
}

template <typename T>
void printfln(const T value)
{
    printfln(value, std::cout);
}

template <typename T>
void printf(const T value)
{
    printf(value, std::cout);
}
