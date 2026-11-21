// pract_enum.cpp

// A complete C++ Program
#include <iostream>
#include <string>

// C-type enum, we also have enum class
enum Transportation
{
    Car, Truck, Airplane, Train, Boat,
};

int main(int argc, char** argv)
{

    std::string transport[] = {"Automobile", "Truck", "Airplane", "Boat"};
    std::cout << transport[Transportation::Car] << std::endl;

    return 0;
}
