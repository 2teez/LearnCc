
// A complete C++ Program
#include <cstdarg>
#include <iostream>
#include <concepts>

template <typename T>
concept Averageable =
std::default_initializable<T> &&
requires(T a, T b)
{
    { a += b } -> std::same_as<T&>;
    { a / size_t{1} } -> std::convertible_to<T>;
};

template <Averageable T>
T mean(T* arr, size_t size)
{
    T sum {};
    for (size_t i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum / size;
}

int main()
{

    // int arrary
    int arr[] {1, 2, 3, 4, 5};
    std::cout << mean(arr, std::size(arr)) << std::endl;

    // float array
    float arr2[] {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::cout << mean(arr2, std::size(arr2)) << std::endl;

    // double array
    double arr3[] {1.0, 2.0, 3.0, 4.0, 5.0};
    std::cout << mean(arr3, std::size(arr3)) << std::endl;

    return 0;

    return 0;
}
