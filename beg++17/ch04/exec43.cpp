// exec43.cpp

// A complete C++ Program
#include <cstddef>
#include <iostream>
#include <cmath>

int main(int argc, char** argv)
{

    std::cout << "Enter size of array: ";
    size_t size {};
    std::cin >> size;
    // allocate and create a dynamic array
    double* arr {new double[size]{}};

    // initialize item on each index
    for (size_t i = 0; i < size; ++i)
    {
        *(arr+i) = 1.0/std::pow((i+1.0), 2.0);
    }
    // calculate sum
    double sum {};
    for (size_t i = 0; i < size; ++i)
    {
        sum += *(arr+i);
    }
    delete[] arr;

    std::cout << std::sqrt(sum * 6.0) << std::endl;
    return 0;
}
