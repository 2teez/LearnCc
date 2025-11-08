// tt_headers_main.cpp

// A complete C++ Program
#include <iostream>
#include "tt_headers.h"

int main(int argc, char** argv)
{
    auto greets = Wrapper("Hello, World!");
    std::cout << greets.get() << "\n";

    return 0;
}
