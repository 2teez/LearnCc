// exe31.cpp

// A complete C++ Program
#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{

    int number {};
    std::cout << "Enter a number: ";
    std::cin >> number;
    int inverted_number { ~number };

    std::cout << "| Original | Inverted | Others |\n";
    std::cout<< std::hex << std::showbase << std::setfill('0') << std::right <<
        "| " << std::setw(8) << number << " | " << std::setw(8) << inverted_number <<
        " | " << std::setw(8) << (inverted_number + 1) << " | "<< std::endl;

    std::cout<< std::dec << std::setfill('0') << std::left <<
        "| " << std::setw(2) << number << " | " << std::setw(2) << inverted_number <<
        " | " << std::setw(2) << (inverted_number + 1) << " | "<< std::endl;

    return 0;
}
