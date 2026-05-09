
// A complete C++ Program
#include <iostream>
#include <concepts>

int mode(const int*, std::size_t);

template <std::integral T>
T mode(const T* arr, std::size_t length)
{
    if (length == 0) return T{};

    T* counter = new T[length]{};
    for (std::size_t i = 0; i < length; i++)
    {
        counter[arr[i]]++;
    }
    T max {};
    T count {};
    for (std::size_t i = 0; i < length; ++i)
    {
        if (counter[i] > max)
        {
            max = counter[i];
            count = i;
        }
    }
    delete [] counter;
    return count;
}

int main()
{
    int arr[] {1, 2, 5, 3, 4, 5, 2, 6, 1, 2, 3, 2, 4, 5, 1, 2};
    std::size_t size = std::size(arr);
    std::cout << mode(arr, size) << std::endl;

    // array of doubles
    //double darr[] {1.5, 2.5, 3.5, 4.5, 5.5};
    //std::size_t dsize = std::size(darr);
    //std::cout << mode(darr, dsize) << std::endl;

    return 0;
}

int mode(const int* arr, std::size_t length)
{
    if (length == 0) return 0;

    int* counter = new int[length]{};
    for (std::size_t i = 0; i < length; i++)
    {
        counter[arr[i]]++;
    }

    int count = 0;
    int max = 0;
    for (std::size_t i = 0; i < length; ++i)
    {
        if (counter[i] > max)
        {
            max = counter[i];
            count = i;
        }
    }

    delete [] counter;
    return count;
    }
