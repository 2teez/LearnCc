// exe2.cpp

// A complete C++ Program
#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
    double radius {};
    const double pi {22.0/7.0};
    std::cout << "Enter the radius: ";
    std::cin >> radius;
    std::cout << "Area of a cicle with radius " << radius << " = "
    << std::setprecision(5) << pi * radius * radius << std::endl;

    return 0;
}
