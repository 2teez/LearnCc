// func_prac.cpp

// A complete C++ Program
#include <iostream>

struct Functions
{
  int apply() volatile
  {
      return ++incr;
  }
  private:
    int incr {};
};

template <typename T>
constexpr const T sumup(T arg)
{
    return arg;
}

template <typename T, typename... Args>
constexpr const T sumup(T x, Args... args)
{
    return x + sumup(args...);
}

// using template alias
template <typename T>
using fn = T(*)(T, T);

// using function pointer
// typedef int(*func)(int, int);   // C-style and old style in cpp

template <typename T>
T add(T a, T b)
{
    std::cout << "Generic ADD template called" << "\n";
    return a + b;
}

template <>
int add(int a, int b)
{
    std::cout << "Specialized ADD template called" << "\n";
    return a + b;
}

template <typename T>
T subtract(T a, T b)
{
    std::cout << "Generic SUBTRACT template called" << "\n";
    return a - b;
}

template <>
int subtract(int a, int b)
{
    std::cout << "Specialized SUBTRACT template called" << "\n";
    return a - b;
}

template <typename T>
T do_math(T a, T b, fn<T> f)
{
    return f(a, b);
}

template <typename T, typename F>
T do_math(T a, T b, F f)
{
    return f(a, b);
}

int main(int argc, char** argv)
{

   volatile Functions fn {};
   std::cout << "Count: " << fn.apply() << "\n";
   std::cout << "Count: " << fn.apply() << "\n";
   std::cout << "Count: " << fn.apply() << "\n";
   /// using sumup
   std::cout << sumup(5,9,3,8,0,1) << "\n";
   //
   // using template alias
   auto a_i = 3, b_i = 8;
   auto a_d = 0.43, b_d = 3.12;

   //
   std::cout << do_math(a_i, b_i, add) << "\n";
   std::cout << do_math(a_d, b_d, add) << "\n";
   //
   std::cout << do_math(a_i, b_i, subtract) << "\n";
   std::cout << do_math(a_d, b_d, subtract) << "\n";
   //
   // using lambda expression in cpp
   try
   {
       std::cout << do_math(2.5, 3.56, [](auto a, auto b){
           return a / b;
        }) << "\n";
   }
   catch (const std::exception& ex)
   {
       std::cout << ex.what() << "\n";
   }
   return 0;
}
