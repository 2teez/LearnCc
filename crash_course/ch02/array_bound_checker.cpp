// array_bound_checker.cpp

// A complete C++ Program
#include <iostream>

void read_from(const char*, std::size_t, int);
void write_to(char*, std::size_t, int, char);

int main(int argc, char** argv)
{

    char lower[] = "abc?e";
    char upper[] = "ABC?E";

    write_to(lower, std::size(lower), 3, 'd');
    write_to(upper, sizeof(upper)/sizeof(char), 3, 'D');
    //
    read_from(lower, sizeof(lower)/sizeof(char), 3);
    read_from(upper, sizeof(upper)/sizeof(char), 3);

    // general display of the string
    std::cout << lower << std::endl;
    std::cout << upper << std::endl;

    return 0;
}

void read_from(const char* str, std::size_t size, int index)
{
    if (index <0 || index >= size)
    {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }
    std::cout << str[index] << std::endl;
}

void write_to(char* str, std::size_t size, int index, char ch)
{
    if (index <0 || index >= size)
    {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }
    str[index] = ch;
}
