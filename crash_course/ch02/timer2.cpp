// timer2.cpp

// A complete C++ Program
#include <iostream>
#include <stdexcept>
#include <iomanip>

struct Timer {
    Timer(): Timer{0, 0, 0}
    {}

    Timer(int h, int m, int s)
    {
        if (h < 0 || h > 23)
        {
            throw std::invalid_argument("hour must be between 0 and 23");
        }
        if (m < 0 || m > 59)
        {
            throw std::invalid_argument("minute must be between 0 and 59");
        }
        if (s < 0 || s > 59)
        {
            throw std::invalid_argument("second must be between 0 and 59");
        }
        timestamp[0] = h;
        timestamp[1] = m;
        timestamp[2] = s;
    }

    friend std::ostream& operator<<(std::ostream& os, const Timer& t);

    private:
        int timestamp[3];
};

int main()
{
    try
    {
        Timer t{70, 30, 45};
    }
    catch(const std::invalid_argument& ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
        return 1;
    }

    return 0;
}

std::ostream& operator<<(std::ostream& os, const Timer& t)
{
    os << std::setw(2) << std::setfill('0') << t.timestamp[0] << ":"
       << std::setw(2) << std::setfill('0') << t.timestamp[1] << ":"
       << std::setw(2) << std::setfill('0') << t.timestamp[2];
    return os;
}
