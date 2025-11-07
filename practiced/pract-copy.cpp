// pract-copy.cpp

// A complete C++ Program
#include <iostream>
#include <string>


struct Person
{
   Person(const std::string& nname = "", unsigned int aage = 0)
	   : name(nname), age(aage) {}
   Person(const Person& p): name(p.name), age(p.age) {}

   ~Person() = default;

   friend std::ostream& operator<<(std::ostream& os, const Person& p)
   {
       os << "Person[Name: " << p.name << ", Age: "<< p.age << "]\n";
       return os;
   }

   void incr_age()
   {
	   age += 1;
   }

   void change_name(std::string new_name = "")
   {
	name = new_name;
   }


   private:
     std::string name;
     unsigned int age;
};


int main(int argc, char** argv)
{

    auto java = Person{"java", 32};
    Person java_copy {java};
    std::cout << java << java_copy << "\n";

    // after using the copy constructor
    java.incr_age();
    java.change_name("openjvm");
    std::cout << java << java_copy << "\n";

    return 0;
}
