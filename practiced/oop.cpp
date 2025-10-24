#include "oop.h"

Vehicle::Vehicle(int passenagers, int fuelcap, int mpg)
{
    this->passenagers = passenagers;
    this->fuelcap = fuelcap;
    this->mpg = mpg;
}

int Vehicle::range()
{
    return fuelcap * mpg;
}
