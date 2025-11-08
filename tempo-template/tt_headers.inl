//#include "tt_headers.h"

template <typename T>
Wrapper<T>::Wrapper(T value): data{value} {}

template <typename T>
T const& Wrapper<T>::get() const
{
    return data;
}
