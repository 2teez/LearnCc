// substr.cpp

// A complete C++ Program
#include <iostream>

const char* get_substr(const char*, const char*);
void string_reverse(const char*);

int main(int argc, char** argv)
{

    const char* result = get_substr("orl", "Hello, world!");
    if (result != nullptr)
    {
       std::cout << result << "\n";
    }
    //
    string_reverse("\nhello, world again?!");

    return 0;
}

const char* get_substr(const char* sub, const char* str)
{
    if (!*sub) return str;
    for(const char* p = str; *p; ++p) {
        const char* s1 = p;
        const char* s2 = sub;
        while(*s1 && *s2 && *s1 == *s2)
        {
            ++s1;
            ++s2;
        }
        if (!*s2)
        {
            return p;
        }
    }
    return nullptr;
}

void string_reverse(const char* s)
{
    if(*s)
    {
        string_reverse(s+1);
    }
    else
    {
        return;
    }
    std::cout << *s;
}
