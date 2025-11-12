// array_main.cpp

// A complete C++ Program

#include <iostream>
#include <vector>
#include <string>
#include "array.h"

int main(int argc, char** argv)
{

    auto arr  = Array<int>{};
    std::cout << arr << "\n";

    auto arr_str  = Array<std::string>(2);
    std::cout << arr_str << "\n";

    int nums[] {2, 4, 6};
    auto nnums {Array(nums, std::size(nums))};
    std::cout << nnums << "\n";
    ///
    std::string myname[] = {"java", "clojure", "elxir"};
    auto names = Array(myname, 3);
    std::cout << names << "\n";
    //
    names = names.push("python", 0);
    std::cout << names << "\n";
    return 0;
}
