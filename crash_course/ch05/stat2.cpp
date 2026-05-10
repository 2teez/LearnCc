
// A complete C++ Program
#include <iostream>

template <typename T>
constexpr T sum(T t)
{
    return t;
}

template <typename T, typename... Ts>
constexpr T sum(T t, Ts... ts)
{
    return t + sum(ts...);
}

// using fold expressions
template <typename... Ts>
constexpr auto sum_fold(Ts... ts)
{
    return (ts + ...);
}

int main()
{
    const auto result = sum(1, 2, 3, 4, 5);
    std::cout << result << std::endl;

    const auto result_fold = sum_fold(1, 2, 3, 4, 5);
    std::cout << result_fold << std::endl;

    return 0;
}
