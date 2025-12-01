// structed_binding.cpp

// A complete C++ Program
#include <exception>
#include <iostream>

class Arithematic_Error: public std::exception {
    public:
    explicit Arithematic_Error(const std::string& msg): msg_(msg) {}
    private:
    std::string msg_;
};

struct employee
{
    std::string name {};
    unsigned age = 0;
    unsigned salary = 1000;
};

std::pair<int, int> divide_reminder(int, int);

int main(int argc, char** argv)
{

    try
    {
        auto [division, reminder] = divide_reminder(31, 3);
        std::cout << division << "; " << reminder << "\n";
    } catch (const Arithematic_Error& ae)
    {
        std::cerr << ae.what() << "\n";
    }
    // structure unbundling
    auto staffs = std::vector<employee> {employee{"java", 23}, employee{"exlixir", 12, 500}};
    staffs.push_back(employee{"clojure", 14});

    for(const auto &[name, age, salary]: staffs)
    {
        std::cout << "Name: " << name << ", Salary: " << salary << ", Age: " << age << "\n";
    }


    return 0;
}

std::pair<int, int> divide_reminder(int nume, int deno)
{
    if (deno == 0)
        throw Arithematic_Error("can't divide by Zero!");
    return {nume/deno, nume % deno};
}
