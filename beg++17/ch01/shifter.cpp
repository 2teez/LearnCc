// shifter.cpp

// A complete C++ Program
#include <iomanip>
#include <ios>
#include <iostream>

enum class Direction {
    North, N=North,
    South, S=South,
    West, W=West,
    East, E=East,
};

int main(int argc, char** argv)
{

    const int number {45};
    const int shifted_number {static_cast<int>(number << 2)};
    std::cout <<  number << " - " << shifted_number << "\n"
              << std::setbase(16)<< std::showbase << number << " - " << shifted_number << "\n"
              << std::endl;

    Direction place {Direction::West};
    std::cout << std::setbase(10) << std::showbase;
    std::cout << static_cast<int>(place) << std::endl;
    return 0;
}
