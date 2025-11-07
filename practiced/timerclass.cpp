// timerclass.cpp

// A complete C++ Program
#include <iostream>

struct TimerClass
{
    TimerClass(unsigned int = 0, unsigned int = 0, unsigned int = 0);
    TimerClass(const TimerClass&);
    TimerClass& operator=(const TimerClass&);
    TimerClass(const TimerClass&&) = delete;
    TimerClass& operator=(const TimerClass&&) = delete;
    ~TimerClass() = default;

    // set the time components
    void set_seconds(unsigned int = 0);
    void set_minutes(unsigned int = 0);
    void set_hours(unsigned int = 0);
    // friend function
    friend std::ostream& operator<<(std::ostream& os, const TimerClass& tc);

    private:
        unsigned int hours;
        unsigned int minutes;
        unsigned int seconds;

};

int main(int argc, char** argv)
{

    auto t1 = TimerClass {15,31,60};
    std::cout << t1 << "\n";

    return 0;
}

TimerClass::TimerClass(
    unsigned int lhours, unsigned int lminutes, unsigned int lseconds
) : hours{lhours}, minutes{lminutes}, seconds{lseconds}
{
    // check the seconds, minutes and hours
    if (seconds > 59)
    {
        seconds = 0;
    }
    if (minutes > 59)
    {
        minutes = 0;
    }
    if (hours > 23)
    {
        hours = 0;
    }
}

TimerClass::TimerClass(const TimerClass& tc)
  : hours{tc.hours}, minutes{tc.minutes}, seconds{tc.seconds}  {}

TimerClass& TimerClass::operator=(const TimerClass& tc)
{
    if (this != &tc)
    {
        this->seconds = tc.seconds;
        this->minutes = tc.minutes;
        this->hours = tc.hours;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const TimerClass& tc)
{
    os << "Timer[" << tc.hours << "H::" << tc.minutes << "M::" << tc.seconds << "S]\n";
    return os;
}

void TimerClass::set_seconds(unsigned int sec)
{
    if (sec > 59)
    {
        seconds = 0;
    }
}

void TimerClass::set_minutes(unsigned int min)
{
    if (min > 59)
    {
        minutes = 0;
    }
}

void TimerClass::set_hours(unsigned int hr)
{
    if (hr > 23)
    {
        hours = 0;
    }
}
