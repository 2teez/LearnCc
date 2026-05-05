#include "types_main.hpp"

Calculator::Calculator(Operations op)
    : _op(op)
{
}

int Calculator::calculate(int a, int b)
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
