// exe41.cpp

// A complete C++ Program
#include <iostream>
#include <ios>
#include <iomanip>

inline int user_input(std::string msg="Prompt: ")
{
    char value {};
    std::cout << msg;
    std::cin >> value;
    return value;
}

int main(int argc, char** argv)
{

    // get user input
    char letter {static_cast<char>(user_input("Enter first number: "))};

    switch (letter) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
          std::cout << letter << " is lower case vowel\n";
          break;
          case 'A': case 'E': case 'I': case 'O': case 'U':
          std::cout << letter << " is upper case vowel\n";
          break;
        default:
          std::cout << letter << " is a consonant!\n";
          break;
    }
    // display letter with code in hexdecimal number
    std::cout << std::hex << std::showbase
              << letter << std::setw(8)
              << static_cast<unsigned int>(letter) << std::endl;

    return 0;
}
