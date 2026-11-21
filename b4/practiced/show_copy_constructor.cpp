// show_copy_constructor.cpp

// A complete C++ Program
#include <iostream>
#include <string>

std::string get_a_name(const std::string&) noexcept;

class Employee
{
    std::string name;
    std::string other_name;

    public:
        explicit Employee(const std::string& nname = "no Name", const std::string& oother_name = "");
        Employee(const Employee&);
        Employee& operator=(const Employee&);
        friend std::ostream& operator<<(std::ostream& os, const Employee& emp);
        ~Employee() = default;
};

inline std::string check_value(const std::string& value)
{
    return value.empty() ? get_a_name("Enter a name: ") : value;
}

int main(int argc, char** argv)
{

    Employee manager, engineer("chimaze", "raza");
    std::cout << manager << "\n" << engineer << "\n";
    engineer = manager;
    std::cout << manager << "\n" << engineer << "\n";
    return 0;
}

std::string get_a_name(const std::string& msg) noexcept
{
    std::cout << msg;
    std::string name;
    std::getline(std::cin, name);
    return name;
}

Employee::Employee(
    const std::string& nname,
    const std::string& oother_name
): name(nname), other_name(check_value(oother_name))
{}

Employee::Employee(const Employee& emp)
: name(emp.name), other_name(check_value(emp.other_name))
{}

Employee& Employee::operator=(const Employee& emp)
{
    if (this == &emp)
    {
        return *this;
    }
    name = emp.name;
    other_name = emp.other_name;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Employee& emp)
{
    if (emp.name == "no Name")
    {
         os << emp.other_name;
    }
    else
    {
         os << emp.name << ", " << emp.other_name;
    }
    return os;
}
