// threed_main.cpp

// A complete C++ Program
#include <iostream>
#include "threed.h"

int main(int argc, char** argv)
{
    ThreeD a(1, 2, 3), b(10, 10, 10), c;
    std::cout << "Original Values of a: ";
    a.show_threeD();
    std::cout << "Original Values of b: ";
    b.show_threeD();

    std::cout << "\n";

    c = a + b;
    std::cout << "Values of c after c = a + b: ";
    show_threeD(c);

    std::cout << "\n";

    c = a + b + c;
    std::cout << "Values of c after c = a + b + c: ";
    c.show_threeD();

    std::cout << "\n";

    c = b = a;
    std::cout << "Values of c after c = b = a: ";
    c.show_threeD();
    std::cout << "Values of b after c = b = a: ";
    b.show_threeD();

    return 0;
}
