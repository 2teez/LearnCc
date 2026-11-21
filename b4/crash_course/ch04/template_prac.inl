//#include "template_prac.hpp"
//
#include <concepts>
template <typename T>
concept Averageable =
std::default_initializable<T> &&
requires(T a, T b)
{
    { a += b } -> std::same_as<T&>;
    { a / size_t{1}} -> std::convertible_to<T>;
};

template <std::size_t Length, Averageable T>
T mean(const T (&arr)[Length])
{
    T result {};
    for (std::size_t i = 0; i < Length; ++i)
    {
        result += arr[i];
    }
    return result / Length;
}
