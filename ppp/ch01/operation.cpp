// operation.cpp

// A complete C++ Program
#include <cstdlib>
import std;

int main()
{

    std::string operation;
    double operand_1;
    double operand_2;
    std::cout << "Enter an operation, follow by two operands: + 121 56\n";
    std::cin >> operation >> operand_1 >> operand_2;

    if (operation == "+")
    {
        std::cout << operand_1 + operand_2 << "\n";
    }
    else if (operation == "*")
    {
        std::cout << operand_1 * operand_2 << "\n";
    }
    else if (operation == "-")
    {
        std::cout << operand_1 - operand_2 << "\n";
    }
    else if (operation == "/")
    {
        if (operand_2 == 0)
        {
            std::cerr << "can't divide by zero.\n";
            return EXIT_FAILURE;
        }
        std::cout << operand_1 / operand_2 << "\n";
    }

    return 0;
}
