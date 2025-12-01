// practiced_fold_expression.cpp

// A complete C++ Program
#include <iostream>
#include <string>

template <typename ...T>
auto summation(T ...args)
{
    return (args + ...);
}

int main(int argc, char** argv)
{

    std::string g1 {"Hello"};
    std::string g2 {", World"};
    std::cout << summation(g1, g2) << std::endl;

    return 0;
}
