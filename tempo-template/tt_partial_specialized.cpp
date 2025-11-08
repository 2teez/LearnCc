// tt_partial_specialized.cpp

// A complete C++ Program
#include <iostream>
#include <array>

template <typename T, size_t S>
std::ostream& pretty_print(std::ostream&, std::array<T, S>);

template <size_t S>
std::ostream& pretty_print(std::ostream&, std::array<char, S>);

//
template <typename T>
void print_it(T value)
{
    std::cout << value << "\n";
}

int main(int argc, char** argv)
{

    std::array<char, 14> hello {"Hello, World!"};
    pretty_print(std::cout, hello);

    std::array<int, 8> nums {2,7,0,1,5,3,6,9};
    pretty_print(std::cout, nums);
    // lambda template
    auto double_it_1 = [](int a) { return a + a;};
    auto double_it_2 = [](auto a) { return a + a;};
    auto double_it_3 = []<typename T>(T a) { return a + a;};
    // usage
    print_it(double_it_1(32));
    print_it(double_it_1(3.3098));
    //print_it(double_it_1(std::string{"hey!"}));
    //
    print_it(double_it_2(32));
    print_it(double_it_2(3.3098));
    print_it(double_it_2(std::string{"hey!"}));
    //
    print_it(double_it_3(32));
    print_it(double_it_3(3.3098));
    print_it(double_it_3(std::string{"hey!"}));
    //
    return 0;
}

template <typename T, size_t S>
std::ostream& pretty_print(std::ostream& os, std::array<T, S> arr)
{
    os << "[";

    for (size_t i = 0; i < S; i++)
    {
        os << arr[i] << (i < (S-1) ? "," : "");
    }

    os << "]\n";
    return os;
}

template <size_t S>
std::ostream& pretty_print(std::ostream& os, std::array<char, S> arr)
{
    os << "[";

    for (size_t i = 0; i < S - 1; ++i)
    {
        os << arr[i] << "";
    }

    os << "]\n";
    return os;
}
