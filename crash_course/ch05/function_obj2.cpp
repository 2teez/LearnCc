
// A complete C++ Program
#include <iostream>
#include <functional>

template <typename T>
T operation(std::function<T (T, T)> fn, T a, T b)
{
	return fn(a, b);
}

int addition (int a, int b)
{
	return a + b;
}

int main()
{
    auto lambda_fn = [](int a, int b) { return a + b;};
    std::cout << "Using Lamda Function: " << operation<int>(lambda_fn, 5, 3) << "\n";
    std::cout << "Using Normal Function: " << operation<int>(addition,5, 4) << "\n";
    std::cout << "Using Normal Function: "
        << operation<double>([](double a, double b) { return a + b; }, 5.34, 4.12) << "\n";

    return 0;
}
