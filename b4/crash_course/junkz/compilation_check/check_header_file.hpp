
#ifndef __CHECK_HEADER_FILE__
#define __CHECK_HEADER_FILE__
// include the structure of the header file
//
#include <iostream>

struct Person {
    private:
        const char* name;
        int age;
    public:
        Person(const char* name, int age);
        const char* getName() const;
        int getAge() const;
        friend std::ostream& operator<<(std::ostream&, const Person&);
};

#include "check_header_file.inl"

#endif //__CHECK_HEADER_FILE__
