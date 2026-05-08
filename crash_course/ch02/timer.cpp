// timer.cpp

// A complete C++ Program
#include <iostream>

struct Timestamp
{
	Timestamp();
	Timestamp(int, int, int);
	Timestamp(const Timestamp&) = default;
	Timestamp operator=(const Timestamp&) = default;
	Timestamp& (Timestamp&&) noexcept = default;
	Timestamp& operator=(Timestamp&&) noexcept = default;
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
	Timer& (Timestamp&&) noexcept;
	Timer operator=(const Timestamp&);
	Timer& operator=(Timestamp&&) noexcept;
	~Timer();

        friend std::ostream& operator<<(std::ostream&, const Timestamp&);

	private:
		Timestamp timestamp;
};

int main(int argc, char** argv)
{


    return 0;
}

Timestamp::Timestamp(): hour{0}, minute{0}, second{0} 
{}

Timestamp::Timestamp(int hr, int min, int sec): hour{hr}, minute{min}, second{sec}
{}

