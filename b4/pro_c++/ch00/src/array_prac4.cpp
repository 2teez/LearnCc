// array_prac3.cpp

// A complete C++ Program
#include <iostream>
#include <cstddef>
#include <print>

struct EvenOddResult {
    EvenOddResult(int* even_nums, std::size_t even_count, int* odd_nums, std::size_t odd_count):
        even_nums{even_nums}, even_count{even_count}, odd_nums{odd_nums}, odd_count{odd_count} {}
    EvenOddResult(const EvenOddResult&) = delete;
    EvenOddResult& operator=(const EvenOddResult&) = delete;

    ~EvenOddResult()
    {
        delete[] even_nums;
        delete[] odd_nums;
    }

    int* even_nums;
    std::size_t even_count;
    int* odd_nums;
    std::size_t odd_count;
};

EvenOddResult separate_even_odd(const int*, std::size_t);

void print_array(const int*, std::size_t);

int main(int argc, char** argv)
{
    int un_split[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result = separate_even_odd(un_split, std::size(un_split));

    print_array(result.even_nums, result.even_count);
    print_array(result.odd_nums, result.odd_count);

    return 0;
}

EvenOddResult separate_even_odd(const int* original_array, std::size_t size)
{
    std::size_t even_count = 0;
    std::size_t odd_count = 0;
    // count the number of array and even
    for (std::size_t i = 0; i < size; ++i)
    {
        if (original_array[i] % 2 == 0)
        {
            ++even_count;
        }
        else
        {
            ++odd_count;
        }
    }

    int* even_nums = new int[even_count];
    int* odd_nums = new int[odd_count];
    std::size_t even_index = 0;
    std::size_t odd_index = 0;
    for (std::size_t i = 0; i < size; ++i)
    {
        if (original_array[i] % 2 == 0)
        {
            even_nums[even_index++] = original_array[i];
        }
        else
        {
            odd_nums[odd_index++] = original_array[i];
        }
    }

    return {even_nums, even_count, odd_nums, odd_count};
}

void print_array(const int* array, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::print(std::cout, "{} -> {}, ", i, array[i]);
    }
    std::println("");
}
