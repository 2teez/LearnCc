// types.cpp

// A complete C++ Program
#include <iostream>

enum class Operations
{
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator
{
    Calculator(Operations op) : _op(op) {}
    int calculate(int a, int b)
    {
        switch(_op)
        {
            case Operations::Add:
                return a + b;
            case Operations::Subtract:
                return a - b;
            case Operations::Multiply:
                return a * b;
            case Operations::Divide:
                return a / b;
            default:
                return 0;
        }
    }
private:
    Operations _op;
};

int main(int argc, char** argv)
{
    Calculator calc(Operations::Add);
    std::cout << calc.calculate(5, 3) << std::endl;

    return 0;
}
