// searcher.cpp

// A complete C++ Program
#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include <iterator>
#include <utility>

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

template <typename T>
void swap(T& a, T& b)
{
    std::swap(a, b);
}


namespace binary_search
{
    template <typename T, typename F>
    void sorter(T start, T end, F f)
    {
        for(auto it = start; it != end; ++it)
            for (auto it2 = it+1; it2 != end; ++it2)
            f(*it, *it2);
    }

    template <typename T = int, typename U, typename Data>
    T bin_search(Data& data, T start_idx, T end_idx, const U& value, bool sort_first = false)
    {
        if (sort_first)
            sorter(&data[start_idx], &data[end_idx], ::swap<U>);

        while(start_idx <= end_idx)
        {
            T curr_idx = (start_idx + end_idx) / 2;

            if (data[curr_idx] == value)
                return curr_idx;
            else if (data[curr_idx] < value)
                start_idx = curr_idx + 1;
            else
                end_idx = curr_idx - 1;
        }
        return -1;
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
        if (a > b)
        {
            a = b;
            b = tmp;
        }
    });
    println(hello_str);
    //
    auto index = binary_search::bin_search(hello, 0, 5, 'e');
    std::cout  << index << "\n";
    return 0;
}
