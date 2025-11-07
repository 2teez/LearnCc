// timerclass.cpp

// A complete C++ Program
#include <iostream>
#include <string>

struct Timerclass
{
    Timerclass(unsigned int seconds = 0, unsigned int minutes = 0, unsigned int hours = 0);
    Timerclass(const Timerclass&);
    Timerclass& operator=(const Timerclass&);
    Timerclass(const Timerclass&&) = delete;
    Timerclass& operator=(const Timerclass&&) = delete;
    ~Timerclass() = default;

    private:
        unsigned int seconds;
        unsigned int minutes;
        unsigned int hours;
}

int main(int argc, char** argv)
{

    std::string hello {"Hello, World!"};
    std::cout << hello << std::endl;

    return 0;
}
