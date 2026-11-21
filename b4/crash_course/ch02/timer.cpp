// timer.cpp

// A complete C++ Program

#include <iostream>
#include <iomanip>

struct Timestamp
{
	Timestamp();
	Timestamp(int, int, int);
	Timestamp(const Timestamp&) = default;
	Timestamp(Timestamp&&) noexcept = default;
	Timestamp& operator=(const Timestamp&) = default;
	Timestamp& operator=(Timestamp&&) noexcept = default;
	friend std::ostream& operator<<(std::ostream&, const Timestamp&);
	~Timestamp() = default;

	private:
	    int hour {};
	    int minute {};
	    int second {};
};

struct Timer
{
	Timer();
	explicit Timer(Timestamp timestamp);
	//Timer(const Timestamp&);
	Timer& operator=(const Timestamp&);
	//Timer(Timestamp&&) noexcept;
	//Timer& operator=(Timestamp&&) noexcept;
	~Timer() = default;

	friend std::ostream& operator<<(std::ostream&, const Timer&);
	private:
		Timestamp timestamp {};
};

int main(int argc, char** argv)
{

    Timestamp t1{}, t2{3, 4, 61};
    std::cout << t1 << "\n" << t2 << std::endl;

    Timer timer{t2};
    std::cout << timer << std::endl;

    return 0;
}

Timestamp::Timestamp() = default;

Timestamp::Timestamp(int hr, int min, int sec): hour{hr}, minute{min}, second{sec}
{
    if (hr < 0 || hr > 23)
    {
        hour = 0;
    }

    if (min < 0 || min > 59)
    {
        minute = 0;
    }

    if (sec < 0 || sec > 59)
    {
        second = 0;
    }
}

std::ostream& operator<<(std::ostream& os, const Timestamp& ts)
{
	os << std::setw(2) << std::setfill('0') << ts.hour << ":"
	<< std::setw(2) << std::setfill('0') << ts.minute << ":"
	<< std::setw(2) << std::setfill('0') << ts.second;
	return os;
}

Timer::Timer() = default;

Timer::Timer(Timestamp timestamp): timestamp{std::move(timestamp)}
{}

//Timer::Timer(const Timestamp& ts): timestamp{ts}
//{}

//Timer& Timer::operator=(const Timestamp& ts)
//{
//	timestamp = ts;
//	return *this;
//}

//Timer::Timer(Timestamp&& ts) noexcept: timestamp{std::move(ts)}
//{}

//Timer& Timer::operator=(Timestamp&& ts) noexcept
//{
//	timestamp = std::move(ts);
//	return *this;
//}

std::ostream& operator<<(std::ostream& os, const Timer& timer)
{
	os << timer.timestamp;
	return os;
}
