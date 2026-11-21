// pract_enum2.cpp

// A complete C++ Program
#include <exception>
#include <iostream>

struct DivideByZero: public std::exception {
    DivideByZero(std::string msg): log{msg} {}
    const char* what() const noexcept override
    {
        return log.c_str();
    }
    private:
        std::string log;
};

enum class Operation
{
    Add,
    Subtract,
    Multiply,
    Divide,
};

template <typename T>
struct Calculator
{
    Calculator(Operation);
    ~Calculator() = default;
    T calculate(T, T) const;
    private:
    Operation operation;
};

int main(int argc, char** argv)
{

    auto cal {Calculator<int>(Operation::Divide)};
    try
    {
        std::cout << cal.calculate(4, 0) << "\n";
    }
    catch (const DivideByZero& dbz)
    {
        std::cerr << dbz.what() << "\n";
    }

    return 0;
}

template <typename T>
Calculator<T>::Calculator(Operation op): operation{op}
{}

template <typename T>
T Calculator<T>::calculate(T a, T b) const
{
   T result {};
   switch (operation)
   {
       case Operation::Add:
           result = a + b;
           break;
       case Operation::Subtract:
           result = a - b;
           break;
       case Operation::Multiply:
           result = a * b;
           break;
       case Operation::Divide:
           if (b == 0)
           {
               throw DivideByZero("Can't Divide by Zero..");
           }
           result = a / b;
           break;
   }
   return result;
}
