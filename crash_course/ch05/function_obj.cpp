
// A complete C++ Program
#include <iostream>

template <typename T, typename Func>
constexpr auto operation(Func func, T a, T b)
{
    return func(a, b);
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    const auto result = operation(add, 5, 3);
    std::cout << result << std::endl;

    return 0;
}
