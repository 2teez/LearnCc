// bubblesort.cpp

// A complete C++ Program
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iterator>

namespace bubble
{
    template <typename It, typename F>
    void selection_sort(It begin, It end, F f)
    {
        for(auto i = begin; i != end; ++i)
            for (auto j = (i+1); j != end; ++j)
                if (*i> *j)
                    f(*i, *j);
    }

    template <typename It, typename F>
    void sort(It begin, It end, F f)
    {
        for(auto i = end; i != begin; --i)
            for (auto j = begin; j < i; ++j)
                if (*j > *(j+1))
                    f(*j, *(j+1));
    }
}

template <typename T>
void swappy(T& a, T& b)
{
    std::swap(a, b);
}

template <typename ...T>
void println(const T& ...arg)
{
    std::cout << ((arg << "\n") <<...);
}

int main(int argc, char** argv)
{

    std::string hello {"Hello, World!"};
    std::sort(std::begin(hello), std::end(hello), [](char a, char b){return a > b;});
    std::cout << hello << "\n";
     int nums[] {4, 25, 12, 8};
     bubble::sort(std::begin(nums), std::end(nums), swappy<int>);
     for (auto const & value: nums)
        std::cout << value << ",";
     std::cout << "\n";

    return 0;
}
