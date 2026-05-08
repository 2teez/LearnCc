// timer.cpp

// A complete C++ Program
#include <iostream>

struct Timestamp
{
	Timestamp();
	Timestamp(int, int, int);
	Timestamp(const Timestamp&) = default;
	Timestamp(Timestamp&&) noexcept = default;
	Timestamp& operator=(const Timestamp&) = default;
	Timestamp& operator=(Timestamp&&) noexcept = default;
	friend std::ostream& operator<<(std::ostream&, const Timestamp&);
	~Timestamp(){}

	int hour;
	int minute;
	int second;
};

struct Timer
{
	Timer();
	Timer(Timestamp timestamp);
	Timer(const Timestamp&);
	Timer& operator=(const Timestamp&);
	Timer(Timestamp&&) noexcept;
	Timer& operator=(Timestamp&&) noexcept;
	~Timer();

        friend std::ostream& operator<<(std::ostream&, const Timestamp&);

	private:
		Timestamp timestamp;
};

int main(int argc, char** argv)
{

    Timestamp t1{}, t2{3, 4, 34};
    std::cout << t1 << t2 << std::endl;

    return 0;
}

Timestamp::Timestamp(): hour{0}, minute{0}, second{0}
{}

Timestamp::Timestamp(int hr, int min, int sec): hour{hr}, minute{min}, second{sec}
{}

std::ostream& operator<<(std::ostream& os, const Timestamp& ts)
{
	os << ts.hour << ":" << ts.minute << ":" << ts.second << std::endl;
	return os;
}
