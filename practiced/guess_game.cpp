// guess_game.cpp

// A complete C++ Program
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

constexpr int DEFAULT_MAX = 10;

int guessed(int = DEFAULT_MAX);
std::string user_input(const char*);

inline void reset(int& number)
{
    number = 0;
}

int seeded(const char*);

int main(int argc, char** argv)
{
    srand(time(nullptr));
    while(true)
    {
        std::cout << "---- GUESS GAME -----" << std::endl;
        int number_guesses {0};
        int guess_number = guessed(seeded("Will you want to seed the GAME? [y|n]: "));
        while(true)
        {
            std::string input {user_input("Enter your guess number: ")};
            int number;
            try {
                number = std::stoi(input);
            }
            catch(...)
            {
                std::cerr << "Invalid input.... Enter a digit."  << std::endl;
                continue;
            }

            if (number == guess_number)
            {
                std::cout << "Congratulation! You guessed the number in "
                << number_guesses + 1 << " times." << "\n";
                reset(number_guesses); // reset
                break;
            }
            else
            {
                if (number < guess_number)
                {
                    std::cout << "Number entered " << number
                    << " is lower than the guess number " << "\n";
                }
                else
                {
                    std::cout << "Number entered " << number
                    << " is higher than the guess number " << "\n";
                }
                number_guesses += 1;
            }
        }
        if (user_input("Exit the Game? [y]: ") == "y")
        {
            break;
        }

    }
    return 0;
}

int guessed(int number)
{
    return 1 + (rand() % number);
}

std::string user_input(const char* msg)
{
    std::cout << msg;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int seeded(const char* msg)
{
    std::cout << msg;
    std::string input;
    std::getline(std::cin, input);
    if (input == "yes" || input == "y" || input == "YES" || input == "Y")
    {
        try {
            return static_cast<int>(stoi(user_input("Enter the limit of the Guess number: ")));
        }
        catch(...)
        {
            std::cerr << "Invalid number. Using default seed.\n";
            return DEFAULT_MAX;
        }
    }
    return DEFAULT_MAX;
}
