// exe41.cpp

// A complete C++ Program
#include <iostream>

int main(int argc, char** argv)
{

    int first_number, second_number {};
    std::cout << "Enter the first number: ";
    std::cin >> first_number;
    std::cout << "Enter the second number: ";
    std::cin >> second_number;
    auto result {first_number - second_number};
    if (result >= 0)
    {
        std::cout << "first number " << first_number << ", is greater than, or equal to "
            << "second number " << second_number << std::endl;
    }
    else
    {
        std::cout << "second number " << second_number << ", is greater than "
            << "first number " << second_number << std::endl;
    }

    return 0;
}
