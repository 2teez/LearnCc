// pract-copy.cpp

// A complete C++ Program
#include <iostream>
#include <string>


struct Person
{
   Person(const std::string& nname = "", unsigned int aage = 0)
	   : name(nname), age(aage) {}
   Person(const Person& p): name(p.name), age(p.age) {}
   Person& operator=(const Person&);
   ~Person() = default;

   friend std::ostream& operator<<(std::ostream& os, const Person& p)
   {
       os << "Person[Name: " << p.name << ", Age: "<< p.age << "]\n";
       return os;
   }

   void incr_age(unsigned int num = 1)
   {
	   age += num;
   }

   void change_name(std::string new_name = "")
   {
	name = new_name;
   }


   private:
     std::string name;
     unsigned int age;
};

// using copy assignment
   Person& Person::operator=(const Person& p)
   {
       if (this != &p)
       {
           (*this).name = p.name;
           (*this).age = p.age;
       }
       return *this;
   }


int main(int argc, char** argv)
{

    auto java = Person{"java", 32};
    Person java_copy {java};
    std::cout << java << java_copy << "\n";

    // after using the copy constructor
    java.incr_age();
    java.change_name("openjvm");
    std::cout << java << java_copy << "\n";

    // using copy assignment
    auto clojure {java};
    std::cout << clojure << java;

    // change the clojure name to clojure
    clojure.change_name("clojure");

    // increase age was used in an unconventional way
    // but to illustrate copy assignment is working
    clojure.incr_age(-20);
    std::cout << clojure << java;
    return 0;
}
