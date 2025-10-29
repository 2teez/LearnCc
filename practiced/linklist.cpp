// linklist.cpp

// A complete C++ Program
#include <iostream>

struct Linklist_item
{
   int value;
   Linklist_item* next_;
};

class Linklist
{
  Linklist_item* head;

  public:
    Linklist(): head(nullptr) {}
    void add(int);
    void print(void);
    Linklist_item* find(int);
    ~Linklist();
};


int main(int argc, char** argv)
{

    Linklist link;
    for (int i = 1; i < 6; i++)
    {
        link.add(i);
    }

    link.print();

    return 0;
}

Linklist::~Linklist()
{
    while(head != nullptr)
    {
        Linklist_item* p = head;
        head = head->next_;
        std::cout << "Deleting " << p->value << "\n";
        delete p;
    }
}

void Linklist::print(void)
{
    for(Linklist_item *p = head; p != nullptr; p = p->next_)
    {
        std::cout << p->value << " ";
    }
    std::cout << std::endl;
}

void Linklist::add(int value)
{
    Linklist_item *np = new Linklist_item;
    np->value = value;
    np->next_ = head;
    head = np;
}

Linklist_item* Linklist::find(int value)
{
    for(Linklist_item* p = head; p != nullptr; p = p->next_)
    {
        if (p->value == value)
        {
            return p;
        }
    }
    return nullptr;
}
