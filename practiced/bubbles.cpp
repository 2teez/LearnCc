// bubbles.cpp

// A complete C++ Program
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>

#define SIZE 10

enum class Description {
    D,
    A,
};

void sized_array(int*, unsigned);
void sort_array(int*, unsigned, Description);
void print_array(const int*, unsigned);


inline void swapper(int &lhs, int &rhs, Description description)
{
    switch (description)
    {
        case Description::D:
            if (lhs > rhs)
            {
                std::swap(lhs, rhs);
            }
            break;
            case Description::A:
            if (lhs < rhs)
            {
                std::swap(lhs, rhs);
            }
            break;
            default:
            break;
    }

}

int main(int argc, char** argv)
{

    srand(static_cast<unsigned>(time(nullptr)));
    int array[SIZE];
    sized_array(array, SIZE);
    print_array(array, SIZE);
    sort_array(array, SIZE, Description::A);
    print_array(array, SIZE);

    return 0;
}

void sized_array(int* arr, unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = static_cast<unsigned>(1 + (rand() % 10));
    }
}

void sort_array(int* arr, unsigned size, Description description)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            swapper(arr[i], arr[j], description);
        }
    }
}

void print_array(const int* arr, unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << (i < size -1 ? ", ": "\n");
    }
}
