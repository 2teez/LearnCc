
// A complete C++ Program
#include <iostream>
#include <stdexcept>

namespace Templar::Template
{
    template <typename From, typename To>
    struct Narrorer
    {
        To cast(From value)
        {
            const auto converted = static_cast<To>(From);
            const auto new_value = static_cast<From>(converted);

            if (converted != new_value)
            {
                throw std::runtime_error {"Narrowed conversion!"};
            }
        }
    }
}

using temple = Templar::Template;

template <typename From>
using short_value = temple::Narrower<short, From>;

int main()
{

    try
    {
        const short_value<int> caster;
        const auto cyclic_short = caster.cast(142857);
        std::cout << cyclic_short << std::endl;
    }
    catch (const std::runtime_error& re)
    {
        std::cout << re.what() << std::endl;
    }

    return 0;
}
