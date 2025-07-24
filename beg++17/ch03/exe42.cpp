// exe41.cpp

// A complete C++ Program
#include <iostream>

bool is_multiple(int, int);
inline void aligned(int &first_number, int &second_number)
{
    // check the number for which is bigger
    // store the larger number in the variable
    // first_number and the other in the second number
    if (second_number > first_number)
    {
        int temp {second_number};
        second_number = first_number;
        first_number = temp;
    }
}

inline int user_input(std::string msg="Prompt: ")
{
    int value {};
    do
    {
        std::cout << msg;
        std::cin >> value;
        if (value <= 0) {
            std::cout << "Invalid value of " << value << std::endl;
        }
    }
    while(value <= 0);
    return value;
}

int main(int argc, char** argv)
{

    // get user input
    int first_number = user_input("Enter first number: ");
    int second_number = user_input("Enter second number: ");

    // check the greater of the number
    // and align the number making the greater number
    // come first and the lesser number second
    aligned(first_number, second_number);

    // show result of the input values
    std::cout << std::boolalpha << second_number << " is a multiple of "
        << first_number << " : " << is_multiple(first_number, second_number)
        << std::endl;

    return 0;
}

bool is_multiple(int first_number, int second_number)
{
    // check if the second number is a multiple
    // of the first number
    if (0 == first_number % second_number)
    {
        return true;
    }
    return false;
}
