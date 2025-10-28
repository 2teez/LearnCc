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
     Person():name(""), age(0){}
     Person(std::string n, unsigned a): name(n), age(a) {}
     friend std::ostream& operator<<(std::ostream& os, const Person& p)
     {
         os << "Name: " << p.name << " , Age: " << p.age << "\n";
         return os;
     }
     ~Person(){}
};

int main(int argc, char** argv)
{

    Person *persons[3] {new Person("pithon", 34),new Person("java", 12), new Person("rust", 5)};
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
