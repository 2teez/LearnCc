// polyincpp.cpp

// A complete C++ Program
#include <iostream>
#include <memory>
#include <string>

class MyClassA
{
    public:
        virtual std::string get_string() const = 0;
        virtual ~MyClassA() = default;
};

class MyClassB: public MyClassA
{
    public:
        std::string get_string() const override;
};

class MyClassC: public MyClassA
{
    public:
        std::string get_string() const override;
};

int main(int argc, char** argv)
{

    std::unique_ptr<MyClassA> my_class = std::make_unique<MyClassB>();
    std::cout << my_class->get_string();
    //
    my_class = std::make_unique<MyClassC>();
    std::cout << my_class->get_string() << std::endl;
    return 0;
}

std::string MyClassB::get_string() const
{
    return "Hello, ";
}

std::string MyClassC::get_string() const
{
    return "World!";
}
