// tt_basic2.cpp

// A complete C++ Program
#include <iostream>

template <typename T>
class Wrapper
{
   public:
   explicit Wrapper(T const value): value {value}
   {}
   T const& get() const
   {
       return value;
   }
   private:
       T value;
};

void use_wrapper(Wrapper<int>*);

void use_wrapper(Wrapper<std::string>&);

int main(int argc, char** argv)
{

    auto a {Wrapper(45)};
    std::cout << a.get() << "\n";
    use_wrapper(&a);
    auto b {Wrapper<std::string>("howdy")};
    use_wrapper(b);
    return 0;
}

void use_wrapper(Wrapper<int>* ptr)
{
    if (ptr)
    {
        std::cout << ptr->get() << "\n";
    }
}

void use_wrapper(Wrapper<std::string>& ref)
{
    std::cout << ref.get() << "\n";
}
