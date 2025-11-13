// searcher.cpp

// A complete C++ Program
#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include <iterator>

template <typename T>
using fn = void(*)(T&, T&);

namespace linear_search
{
    template <typename T>
    bool search(const T* arr, size_t n, const T& ele)
    {
        if (n == 0 || !arr)
            return false;

        for (auto it = 0; it < n; it++)
            if (arr[it] == ele)
                return true;
        return false;
    }

    template <typename T, typename U>
    bool search(T start, T end, const U& ele)
    {
        for (auto it = start; it != end; it++)
            if (*it == ele)
                return true;
        return false;
    }
}

namespace binary_search
{
    template <typename T, typename F>
    void sorter(T start, T end, F f)
    {
        for(auto it = start; it != end; ++it)
            for (auto it2 = start; it2 != end; ++it2)
            f(*it, *it2);
    }
}

template <typename T>
void swap(T& a, T& b)
{
    auto tmp = a;
    if (a < b)
    {
        a = b;
        b = tmp;
    }
}

template <typename U>
void println(const U& data)
{
    for(auto const& value: data)
    std::cout << value << ' ';
    std::cout << '\n';
}

int main(int argc, char** argv)
{

    char hello[] = {"Hello, World!"};
    std::cout << std::boolalpha << linear_search::search(hello,
        std::strlen(hello), 'r') << '\n';

    std::string hello_str = hello;
    std::cout << std::boolalpha
              << linear_search::search(std::begin(hello_str),std::end(hello_str), 'r')
              << '\n';
    // binary serach
    std::vector<int> nums {2,6,3,9,0,1};
    binary_search::sorter(std::begin(nums),std::end(nums), swap<int>);
    println(nums);
    //
    binary_search::sorter(std::begin(hello_str),std::end(hello_str), [](char& a, char& b){
        auto tmp = a;
        if (a < b)
        {
            a = b;
            b = tmp;
        }
    });
    println(hello_str);

    return 0;
}
