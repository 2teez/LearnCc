
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

    const auto result2 = operation([](int a, int b) { return a - b; }, 5, 3);
    std::cout << result2 << std::endl;

    try {
        const auto result3 = operation([](int a, int b) {
            if ( b == 0) throw std::runtime_error("division by zero");
            return a * b; }, 5, 3);
        std::cout << result3 << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
