// pract_smart_ptr.cpp

// A complete C++ Program
#include <iostream>
#include <string>
#include <memory>
#include <array>

template <typename T>
void printer(const std::unique_ptr<T>&);

template <typename T>
void printer(const std::shared_ptr<T>&);

int main(int argc, char** argv)
{

    std::shared_ptr<std::array<std::string, 3>> greetings (
        std::make_shared<std::array<std::string, 3>>(
            std::array<std::string, 3>{"hello", "bonjour", "e ka ro"}));

    printer(greetings);

      /// using std::unique_ptr
      std::unique_ptr<std::array<std::string, 3>> langs (
          std::make_unique<std::array<std::string, 3>>(
              std::array<std::string, 3>{"python", "raku", "clojure"}));

    printer(langs);

    return 0;
}

template <typename T>
void printer(const std::unique_ptr<T>& langs)
{
    for(const auto& lang: *langs)
    {
        std::cout << lang << "\n";
    }
}

template <typename T>
void printer(const std::shared_ptr<T>& greetings)
{
    for(const auto& greet: *greetings)
    {
        std::cout << greet << "\n";
    }
}
