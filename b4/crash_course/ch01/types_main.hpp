#ifndef __TYPE_MAIN_HPP__
#define __TYPE_MAIN_HPP__

enum class Operations
{
    Add,
    Subtract,
    Multiply,
    Divide
};


struct Calculator
{
    Calculator(Operations op);
    int calculate(int a, int b);

private:
    Operations _op;
};

#endif
