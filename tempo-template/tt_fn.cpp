// tt_fn.cpp

// A complete C++ Program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T, typename U = long>
U contains(const T&, const std::vector<T>&);

std::string get_user_input(const char*);

char get_first_letter(const char*);

int main(int argc, char** argv)
{

    std::string hello {"hello, world!"};
    auto greet = std::vector<char>(hello.begin(), hello.end());
    auto it = get_first_letter(get_user_input("Enter seeking value: ").c_str());
    if (it != ' ')
    {
        auto answer = contains(it, greet);
        std::cout << hello <<
            " contains the value [" << it <<"]: "<< ((answer != -1) ? "yes" : "no") << "\n";
    }

    return 0;
}

template <typename T, typename U>
U contains(const T& value, const std::vector<T>& vec)
{
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end())
    {
        return static_cast<int>(std::distance(vec.begin(), it));
    }
    return -1;
}

std::string get_user_input(const char* msg)
{
    std::cout << msg;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

char get_first_letter(const char* str)
{
    if (str && str[0] != ' ')
    {
        return str[0];
    }
    return ' ';
}
