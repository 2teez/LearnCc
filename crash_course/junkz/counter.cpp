
// A complete C++ Program
#include <iostream>

struct Counter
{
    explicit Counter(char letter);
    void count_it(const char*);
    void print() const;
    private:
        char letter;
        int count;
};

int main()
{
    Counter counter{'l'};
    counter.count_it("Hello, World!");
    counter.print();

    Counter counter2{'s'};
    counter2.count_it("Sailor went to sea to see what he could see.");
    counter2.print();

    return 0;
}

Counter::Counter(char letter): letter{letter}, count{0}
{
}

void Counter::count_it(const char* str)
{
    while(*str++)
    {
        if (*str == letter)
        {
            ++count;
        }
    }
}

void Counter::print() const
{
    std::cout << letter << ": " << count << std::endl;
}
