// practice_containers.cpp

// A complete C++ Program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
T summation(T first_value, T second_value);

int main(int argc, char** argv)
{

    std::string str {"Hello, World!"};
    for (auto ch = str.rbegin(); ch != str.rend(); ++ch)
    {
        std::cout << *ch;
    }
    std::cout << std::endl;
    ///
    std::vector<int> nums  {0, 1, 8, 13, 5, 2, 3 };
    std::sort(nums.begin(), nums.end());

    for (auto& num: nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
   //
   std::cout << summation(4.2, 0.35) << "\n";
   std::cout << summation(4, -2) << "\n";
   std::cout << summation<std::string>("hello, ", "world..") << "\n";
   //
    return 0;
}

template <typename T>
T summation(T first_value, T second_value)
{
    return first_value + second_value;
}
