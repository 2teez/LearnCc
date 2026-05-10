
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

int main()
{
    const auto result = sum(1, 2, 3, 4, 5);
    std::cout << result << std::endl;

    return 0;
}
