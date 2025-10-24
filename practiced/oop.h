
#ifndef __OOP__
#define __OOP__
#

class Vehicle {
  public:
  int passenagers;
  int fuelcap;
  int mpg;

  Vehicle(){}
  Vehicle(int passenagers, int fuelcap, int mpg);
  int range();
};

#endif //__OOP__
