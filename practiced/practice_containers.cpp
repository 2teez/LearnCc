// practice_containers.cpp

// A complete C++ Program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    return 0;
}
