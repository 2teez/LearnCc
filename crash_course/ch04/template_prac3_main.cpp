
// A complete C++ Program
#include <iostream>
#include "template_prac.hpp"

int main()
{

    // using the Averageable concept
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << mean(arr) << std::endl;

    double arr2[] = {1.5, 2.5, 3.5, 4.5, 5.5, 2.78, 9.23, 8.12};
    std::cout << mean(arr2) << std::endl;

    return 0;
}
