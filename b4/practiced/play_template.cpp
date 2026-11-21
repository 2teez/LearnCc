// play_template.cpp

// A complete C++ Program
#include <iostream>
#include <stdexcept>

template <size_t L, typename T>
T get(T (&arr)[L], size_t index)
{
    if (index >= L)
    {
        throw std::out_of_range {"Out of bound!"};
    }
    return arr[index];
}


int main(int argc, char** argv)
{

    int nums[] {1, 6, 8, 3};
    std::cout << get(nums, 2) << "\n";
    //
    const char hello[] {"hello, world!"};
    std::cout << get(hello, 8) << "\n";
    //
    //int numbers[] {4,9,3,0,5};
    //std::cout << sum_up(numbers) << "\n";

    return 0;
}
