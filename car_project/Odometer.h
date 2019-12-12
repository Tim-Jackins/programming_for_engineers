#include <iostream>
#include <string>
#include <stdint.h>
#include <stdlib.h>

// In miles
#ifndef MINIMUM_MILES
#define MINIMUM_MILES 0
#endif

// In miles
#ifndef MAXIMUM_MILES
#define MAXIMUM_MILES 999999
#endif

using namespace std;

class Odometer
{
private:
  int _mileage;

public:
  Odometer(int new_mileage = 0)
  {
    _mileage = new_mileage;
  }

  // Gets
  double getMileage() { return _mileage; }

  // Sets
  void setMileage(int new_mileage) { _mileage = new_mileage; }

  // Operators
  Odometer operator++(int) // A++
  {
    Odometer temp = *this ;
    // Do increment of "this" value
    int new_mileage = FUEL_ECONOMY * FUEL_INCREMENT + _mileage;
    if (new_mileage > MAXIMUM_MILES)
    {
      new_mileage -= MAXIMUM_MILES;
      // new_mileage = MINIMUM_MILES;
    }
    _mileage = new_mileage;
    return temp;
  }
};

// ostream& operator<<(ostream &strm, Circle &circle) {
// return strm << "Circle with radius: " << circle.getRadius();
// }
