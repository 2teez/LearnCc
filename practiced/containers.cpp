// containers.cpp

// A complete C++ Program
#include <iostream>
#include <string>
#include <array>
#include <vector>

template <typename T>
void print_content(std::vector<T>);

int main(int argc, char** argv)
{

    std::array<std::string, 3> greetings { "hello", "howdy", "bonjour" };
    print_content(std::vector<std::string>(greetings.begin(), greetings.end()));

    std::vector<unsigned int> numbers {5,9,2,4,32};
    print_content(numbers);
    numbers.push_back(221);
    print_content(numbers);
    numbers.erase(numbers.begin() + 2);
    print_content(numbers);
    return 0;
}

template <typename T>
void print_content(std::vector<T> vec)
{
    std::cout << "SIZE: " << std::size(vec) << " <> " << vec.size() << "\n";
    for( auto v: vec)
    {
     std::cout << v << std::endl;
    }
}
