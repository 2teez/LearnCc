// reader2.cpp

// A complete C++ Program
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char** argv)
{

    std::string filename;
    std::cout << "Enter a filename: ";
    if (!std::getline(std::cin, filename))
    {
        return EXIT_FAILURE;
    }

    std::ifstream in(filename, std::ios::binary);
    if (!in)
    {
        std::cerr << "Can't open " << filename << "\n";
        return EXIT_FAILURE;
    }

    std::cout << in.rdbuf();

    return 0;
}
