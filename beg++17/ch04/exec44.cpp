// exec43.cpp

// A complete C++ Program
#include <cstddef>
#include <iostream>
#include <cmath>
#include <vector>

int main(int argc, char** argv)
{

    std::cout << "Enter size of array: ";
    size_t size {};
    std::cin >> size;
    // allocate and create a dynamic array
    std::vector<double> vec {};

    // initialize item on each index
    for (size_t i = 0; i < size; ++i)
    {
        vec.push_back(1.0/std::pow((i+1.0), 2.0));
    }
    // calculate sum
    double sum {};
    for (auto num : vec)
    {
        sum += num;
    }

    std::cout << std::sqrt(sum * 6.0) << std::endl;
    return 0;
}
