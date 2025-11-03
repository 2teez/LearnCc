// practice_containers.cpp

// A complete C++ Program
#include <iostream>
#include <string>

int main(int argc, char** argv)
{

    std::string str {"Hello, World!"};
    for (auto ch = str.rbegin(); ch != str.rend(); ++ch)
    {
        std::cout << *ch;
    }
    std::cout << std::endl;

    return 0;
}
