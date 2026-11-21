
#ifndef __THREED__
#define __THREED__
#

class ThreeD
{
  int x;
  int y;
  int z;
  public:
      ThreeD();
      ThreeD(int x, int y, int z);
      ThreeD operator+(const ThreeD&) const;
      ThreeD operator=(const ThreeD&);
      ThreeD operator--();
      ThreeD operator --(int);
      void show_threeD() const;
      friend void show_threeD(const ThreeD& lhs);
      ~ThreeD(){};
};

#endif //__THREED__
