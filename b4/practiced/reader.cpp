// reader.cpp

// A complete C++ Program
#include <iostream>
#include <fstream>

constexpr int SIZE = 20;

int main(int argc, char** argv)
{
    char filename[SIZE];
    std::cout << "Enter a filename: ";
    std::cin.getline(filename, SIZE);

    std::fstream in(filename, std::ios::in | std::ios::binary);
    if (!in)
    {
        std::cout << "Can't open file" << filename << "\n";
        return -1;
    }

    char ch;
    while(in.get(ch))
    {
        std::cout << ch;
    }

    in.close();

    return 0;
}
