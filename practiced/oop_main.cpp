// oop_main.cpp

// A complete C++ Program
#include <iostream>
#include "oop.h"

int main(int argc, char** argv)
{

    Vehicle minivan;

    minivan.fuelcap = 16;
    minivan.mpg = 21;
    minivan.passenagers = 7;

    int range = minivan.range();

    std::cout << "Minivan can carry " << minivan.passenagers <<
       " passenagers with a range of " << range << "\n";

    //
    Vehicle sportcar(2, 23, 230);

    std::cout << "Sport car can carry " << sportcar.passenagers <<
    " passenagers with a range of " << sportcar.range() << "\n";

    return 0;
}
