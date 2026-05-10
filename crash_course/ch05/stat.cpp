
// A complete C++ Program
#include <iostream>
#include <stdexcept>

namespace Templar::Template
{
    template <typename To, typename From>
    struct Narrower
    {
        To cast(From value) const
        {
            const auto converted = static_cast<To>(value);
            const auto new_value = static_cast<From>(converted);

            if (value != new_value)
            {
                throw std::runtime_error {"Narrowed conversion!"};
            }

            return converted;
        }
    };
};

template <typename To, typename From>
using temple = Templar::Template::Narrower<To, From>;

template <typename From>
using short_caster = temple<short, From>;

int main()
{

    try
    {
        const short_caster<int> caster;
        const auto cyclic_short = caster.cast(142857);
        std::cout << cyclic_short << std::endl;
    }
    catch (const std::runtime_error& re)
    {
        std::cout << re.what() << std::endl;
    }

    return 0;
}
