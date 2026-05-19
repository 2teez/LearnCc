// array_prac3.cpp

// A complete C++ Program
#include <iostream>
#include <cstddef>
#include <print>

void seperate_even_odd(const int*, std::size_t, int**, std::size_t*, int**, std::size_t*);

void print_array(const int*, std::size_t);

int main(int argc, char** argv)
{
    int un_split[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* even_nums {nullptr};
    int* odd_nums {nullptr};
    std::size_t even_count {0};
    std::size_t odd_count {0};
    seperate_even_odd(un_split, std::size(un_split), &even_nums, &even_count, &odd_nums, &odd_count);

    print_array(even_nums, even_count);
    print_array(odd_nums, odd_count);

    delete[] even_nums;
    delete[] odd_nums;

    even_nums = nullptr;
    odd_nums = nullptr;

    return 0;
}

void seperate_even_odd(
    const int* original_array, std::size_t size,
    int** even_nums, std::size_t* even_count, int** odd_nums, std::size_t* odd_count
)
{
    *even_count = 0;
    *odd_count = 0;
    // count the number of array and even
    for (std::size_t i = 0; i < size; ++i)
    {
        if (original_array[i] % 2 == 0)
        {
            ++*even_count;
        }
        else
        {
            ++*odd_count;
        }
    }

    *even_nums = new int[*even_count];
    *odd_nums = new int[*odd_count];
    std::size_t even_index = 0;
    std::size_t odd_index = 0;
    for (std::size_t i = 0; i < size; ++i)
    {
        if (original_array[i] % 2 == 0)
        {
            (*even_nums)[even_index++] = original_array[i];
        }
        else
        {
            (*odd_nums)[odd_index++] = original_array[i];
        }
    }

}

void print_array(const int* array, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::print(std::cout, "{} -> {}, ", i, array[i]);
    }
    std::println("");
}
