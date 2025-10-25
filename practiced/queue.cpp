// queque.cpp

// A complete C++ Program
#include <iostream>
#include <cstdbool>

static const int LENGTH = 5;

class Queue {
    int data[LENGTH];
    int size;
    int get_count;
    int put_count;

    public:
    Queue(int len)
    {
        if(len > LENGTH)
        {
            len = LENGTH;
        }
        len = 1;
        put_count = get_count = 0;
    }
     bool put(int value)
      {
          if (put_count == size)
          {
              std::cout << "Full Queue" << "\n";
              return false;
          }
          put_count += 1;
          data[put_count-1] = value;
          return true;
      }
      int get()
      {
          if (get_count == put_count)
          {
              std::cout << "Empty Queue!.." << "\n";
              return -1;
          }
          get_count += 1;
          return data[get_count - 1];
      }

      void showData() const;
};

int main(int argc, char** argv)
{
    Queue q = 5;
    q.put(5);
   std::cout << q.get() << "\n";
   for (size_t i = 0; i < 4; i++)
   {
       q.put(rand() % 10);
   }

   q.showData();
    return 0;
}

void Queue::showData() const
{
    for (size_t i = 0; i < LENGTH; i++)
    {
        std::cout << data[i] << (i < LENGTH-1 ? ", " : "\n");
    }
    std::cout << std::endl;
}
