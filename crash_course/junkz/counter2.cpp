
// A complete C++ Program
#include <iostream>

struct Counter
{
    explicit Counter(char letter);
    int operator()(const char*) const;
    private:
        char letter;
};

int main()
{


    Counter s_counter{'s'};

    int tally {};
    std::cout << "Tally: " << tally << "\n";
    auto sally = s_counter("Sally sells seashells by the seashore.");
    std::cout << "Sally: " << sally << "\n";
    tally += sally;
    std::cout << "Tally: " << tally << "\n";
    auto sailor = s_counter("Sailor went to sea to see what he could see.");
    std::cout << "Sailor: " << sailor << "\n";
    tally += sailor;
    std::cout << "Tally: " << tally << "\n";

    return 0;
}

Counter::Counter(char letter): letter{letter}
{
}

int Counter::operator()(const char* st) const
{
    int result {};
    while(*st++)
    {
	    if (*st == letter)
	    {
		    ++result;
	    }
    }
    return result;
}
