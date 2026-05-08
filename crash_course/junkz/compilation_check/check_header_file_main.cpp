// check_header_file_main.cpp

// A complete C++ Program
#include <iostream>
#include "check_header_file.hpp"

int main(int argc, char** argv)
{

    Person java {"Java", 30};
    std::cout << java.getName() << " is " << java.getAge() << " years old." << std::endl;

    printfln(java.getName());
    printfln(java.getAge());

    // Use the overloaded operator<< to print the Person object
    std::cout << java << std::endl;

    return 0;
}
