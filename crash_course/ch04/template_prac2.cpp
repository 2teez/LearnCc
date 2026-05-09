
// A complete C++ Program
#include <iostream>
#include <string>

int mode(int*, std::size_t);

template <typename T>
T mode(T*, std::size_t);

int main()
{
    int arr[] {1, 2, 5, 3, 4, 5, 2, 6, 1, 2, 3, 2, 4, 5, 1, 2};
    std::size_t size = std::size(arr);
    std::cout << mode(arr, size) << std::endl;

    return 0;
}

template <typename T>
T mode(T* arr, std::size_t size)
{
    T* counter = new T[size]{};
    for (std::size_t i = 0; i < size; i++)
    {
        counter[arr[i]]++;
    }
    T max = 0;
    T count = 0;
    for (std::size_t i = 0; i < size; ++i)
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

int mode(int* arr, std::size_t size)
{
    int* counter = new int[size]{};
    for (std::size_t i = 0; i < size; i++)
    {
        counter[arr[i]]++;
    }

    int count = 0;
    int max = 0;
    for (std::size_t i = 0; i < size; ++i)
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
