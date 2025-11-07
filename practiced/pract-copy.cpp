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

   friend std::iostream& operator<<(std::iostream& os, const Person& p)
   {
	os << "Person[ Name: " << p.name << ", Age: "<< p.age << "]\n";
	return os;
   }

   private:
     std::string name;
     unsigned int age;
};


int main(int argc, char** argv)
{

    auto java = Person{"java", 32};
    Person java_cop {};
    std::cout << java << java_copy << "\n";

    return 0;
}

