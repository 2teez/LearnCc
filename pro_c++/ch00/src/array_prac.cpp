// array_prac.cpp

// A complete C++ Program
#include <iostream>
#include <print>
#include <cstddef>
#include <format>
#include <array>
#include <string>

int main(int argc, char** argv)
{

   std::array<std::string, 3> langs {"C++", "Python", "Java"};

   std::println(std::cout, "Languages:");
   for (const auto& lang : langs) {
       std::cout << std::format("{}\n", lang);
   }

    return 0;
}
