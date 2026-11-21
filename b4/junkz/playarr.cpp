// playarr.cpp

// A complete C++ Program
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>

const unsigned int Len {100};
//typedef long long Llong;
using Llong = long long;
std::array<Llong, Len> generate_fibo();

int main(int argc, char** argv)
{

    std::cout << "Enter an upper limit for a vector: ";
    int upper_bound {};
    int lower_bound {1};
    std::cin >> upper_bound;
    std::vector<int> values (upper_bound);
    for (size_t i = 0; i < upper_bound; ++i) {  // populate the vector
        values.push_back(lower_bound++);
    }

    for (auto value: values)
    {
        if (value % 7 == 0 || value % 13 == 0) {
            continue;
        } else {
            std::cout << std::setw(4) << value;
        }
    }
    std::cout << std::endl;
    // print fibo first 93 numbers
    std::cout << "Number " << std::setw(5) << "Fibo Number\n";
    auto fibo_nums = generate_fibo();
    for(auto i = 1; i < fibo_nums.size(); ++i) {
        std::cout << std::setw(6) << i << " " << std::setw(20) << fibo_nums.at(i) << "\n";
    }
    return 0;
}

std::array<Llong, Len> generate_fibo()
{
    std::array<Llong, Len> nums{0, 1};

    for (auto i = 2; i < Len; ++i)
    {
        nums.at(i) = nums.at(i-1) + nums.at(i-2);
    }

    return nums;
}
