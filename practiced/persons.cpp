// persons.cpp

// A complete C++ Program
#include <iostream>
#include <string>

class Person
{
    std::string first_name;
    std::string last_name;
    public:
    Person(
        std::string fname = "",
        std::string lname = ""
    ): first_name(fname), last_name(lname) {}

      ~Person() {}
      std::string get_fullname() const
      {
          return first_name + " " + last_name;
      }
      friend std::ostream& operator<<(std::ostream& os, const Person&);
      friend std::istream& operator>>(std::istream& is, Person&);
};

int main(int argc, char** argv)
{

    Person lang {"Java", "james"};
    std::cout << lang << std::endl;
    //
    Person langs[3];
    for(size_t i = 0; i < 3; i++)
    {
        std::cin >> langs[i];
        std::cout << langs[i] << "\n";
    }

    return 0;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.get_fullname();
    return os;
}

std::istream& operator>>(std::istream& is, Person& p)
{
    std::cout << "Enter your name: ";
    is >> p.first_name >> p.last_name;
    return is;
}
