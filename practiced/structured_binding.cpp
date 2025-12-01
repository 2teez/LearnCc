// structed_binding.cpp

// A complete C++ Program
#include <exception>
#include <iostream>
#include <vector>

class arithmetic_error: public std::exception {
    public:
    explicit arithmetic_error(const std::string& msg): msg_(msg) {}
    const char* what() const noexcept override {
        return msg_.c_str();
    }
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
    } catch (const arithmetic_error& ae)
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
        throw arithmetic_error("can't divide by Zero!");
    return {nume/deno, nume % deno};
}
