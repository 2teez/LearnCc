
#ifndef __TT_HEADERS__
#define __TT_HEADERS__

template <typename T>
struct Wrapper
{
    explicit Wrapper(T value);
    T const& get() const;
    private:
        T data;
};

#include "tt_headers.inl"

#endif //__TT_HEADERS__
