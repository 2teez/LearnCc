// dynamic_variables.cpp

// A complete C++ Program
#include <iostream>
#include <string>

struct Person
{
   private:
     std::string name {};
     unsigned int age {0};
   public:
     Person(std::string n="",unsigned a=0):name(n), age(a){}
     friend std::ostream& operator<<(std::ostream& os, const Person& p)
     {
         os << "Name: " << p.name << " , Age: " << p.age << "\n";
         return os;
     }
     ~Person()
     {
         std::cout << "Dropping person with name " << name << " and age " << age << "\n";
     }
};

int main(int argc, char** argv)
{

    Person *persons[] {new Person("pithon", 34),new Person("java", 12),
        new Person("rust", 5), new Person()};
    for(auto person: persons)
    {
        std::cout << person << *person << "\n";
    }
    for(auto person: persons)
    {
        delete person;
    }
    return 0;
}
