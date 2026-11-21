#include <iostream>
#include "threed.h"

ThreeD::ThreeD(): x(0), y(0), z(0) {};

ThreeD::ThreeD(int x, int y, int z): x(x), y(y), z(z)
{}
ThreeD ThreeD::operator+(const ThreeD& rhs) const
{
    return ThreeD(x + rhs.x, y + rhs.y, z + rhs.z);
}

ThreeD ThreeD::operator=(const ThreeD& rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    return *this;
}

ThreeD ThreeD::operator--()
{
    x--;
    y--;
    z--;
    return *this;
}

ThreeD ThreeD::operator--(int)
{
    ThreeD temp = *this;
    --x; --y; --z;
    return *this;
}

void ThreeD::show_threeD() const
{
    std::cout << "X: " << x << ", Y: " << y
     << ", Z: " << z << "\n";
}

void show_threeD(const ThreeD& lhs)
{
     std::cout << "X: " << lhs.x << ", Y: " << lhs.y
      << ", Z: " << lhs.z << "\n";
}
