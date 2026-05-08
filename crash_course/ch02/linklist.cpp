// linklist.cpp

// A complete C++ Program
#include <iostream>

struct Element
{
    Element* next;
    char prefix[2];
    short operating_number;

    void insert_after(Element* element);
};

int main(int argc, char** argv)
{

    Element tr1, tr2, tr3;
    tr1.prefix[0] = 'T';
    tr1.prefix[1] = 'K';
    tr1.operating_number = 421;
    tr1.insert_after(&tr2);
    tr2.prefix[0] = 'F';
    tr2.prefix[1] = 'N';
    tr2.operating_number = 2187;
    tr2.insert_after(&tr3);
    tr3.prefix[0] = 'L';
    tr3.prefix[1] = 'S';
    tr3.operating_number = 005;

    for (Element* curr = &tr1; curr != nullptr; curr = curr->next)
    {
        std::cout << curr->prefix[0] << curr->prefix[1] << " " << curr->operating_number << std::endl;
    }
    return 0;
}

void Element::insert_after(Element* element)
{
    element->next = this->next;
    this->next = element;
}
