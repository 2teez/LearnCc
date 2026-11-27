// repeated_words.cpp

// A complete C++ Program
import std;

int main(int argc, char** argv)
{

    int number_of_words = 0;
    std::string previous;
    std::string current;
    while (std::cin >> current)
    {
        if (previous == current)
        {
            ++number_of_words;
            std::cout << "Reapeated words: " << current << ", " << previous << ".\n";
            std::cout << "Word number " << number_of_words << " repeated " << current << "\n";
        }
        previous = current;
    }

    return 0;
}
