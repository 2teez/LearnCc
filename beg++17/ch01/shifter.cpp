// shifter.cpp

// A complete C++ Program
#include <iomanip>
#include <ios>
#include <iostream>

int main(int argc, char** argv)
{

    const int number {45};
    const int shifted_number {static_cast<int>(number << 2)};
    std::cout <<  number << " - " << shifted_number << "\n"
              << std::setbase(16)<< std::showbase << number << " - " << shifted_number << "\n"
              << std::endl;

    return 0;
}
