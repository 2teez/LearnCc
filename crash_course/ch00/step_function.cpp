#include "step_function.hpp"

int step_function(int x)
{
    int result = 0;
    if (x < 0)
    {
        result = -1;
    }
    else if (x == 0)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }
    return result;
}

int absolute_value(int x)
{
    int result = 0;
    if (x < 0)
    {
        result = x * -1;
    }
    else
    {
        result = x;
    }
    return result;
}
