#include "check_header_file.hpp"

Person::Person(const char* name, int age) : name{name}, age{age} {

}

const char* Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Name: " << person.name << ", Age: " << person.age;
    return os;
}
