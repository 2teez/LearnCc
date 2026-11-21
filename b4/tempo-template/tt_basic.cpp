// tt_basic.cpp

// A complete C++ Program
#include <iostream>

template <typename T>
T add(T a, T b);

template <typename T, typename Predicate>
int count_if(T, T, Predicate);

int main(int argc, char** argv)
{

    double a {3.09}, b {0.135};
    std::cout << add(4, 8) << "\n";
    std::cout << add(a, b) << "\n";
    //
    auto numbers = {3,9,0,4,7,8,2,1};
    std::cout <<
    count_if(
        std::begin(numbers),
        std::end(numbers),
        [](int const i){
            return 0 == i % 2;
        }) << "\n";

    return 0;
}

template <typename T>
T add(T const a, T const b)
{
    return a + b;
}

template <typename T, typename Predicate>
int count_if(T start, T end, Predicate p)
{
    int total {};
    for (auto i = start; i != end; i++)
    {
        if (p(*i))
        {
            total += 1;
        }
    }
    return total;
}
