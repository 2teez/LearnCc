// teller.cpp

// A complete C++ Program
import std;

int main()
{

    std::cout << "Enter your name and (age in years): ";
    std::string name;
    double age = -1;
    std::cin >> name >> age;
    age = age * 12;
    std::cout << "My name is " << name << ", and I am " << age << " months old\n";

    return 0;
}
