#include <iostream>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <stdexcept>

// In gallons
#ifndef MAX_FUEL
#define MAX_FUEL 15
#endif

// In gallons
#ifndef FUEL_INCREMENT
#define FUEL_INCREMENT 1
#endif

using namespace std;

class FuelGauge
{
private:
  // In gallons
  int _fuel_amount;

  // Sets
  void setFuelAmount(int new_fuel_amount) { _fuel_amount = new_fuel_amount; }

public:
  FuelGauge(int new_fuel_amount = 0)
  {
    _fuel_amount = new_fuel_amount;
  }

  // Gets
  int getFuelAmount() { return _fuel_amount; }

  // Methods
  FuelGauge operator++(int)
  {
    FuelGauge temp = *this ;
    if ((_fuel_amount + FUEL_INCREMENT) > MAX_FUEL)
    {
      throw overflow_error( "Your gallon has overflowed!" );
    }
    else
    {
      setFuelAmount(_fuel_amount + FUEL_INCREMENT);
    }
    return temp;
  }

  FuelGauge operator--(int)
  {
    FuelGauge temp = *this ;
    if ((_fuel_amount - FUEL_INCREMENT) < 0)
    {
      throw underflow_error( "Your car has run out of gas!" );
    }
    else
    {
      setFuelAmount(_fuel_amount - FUEL_INCREMENT);
    }
    return temp;
  }
};

// ostream& operator<<(ostream &strm, FuelGauge &circle) {
// return strm << "Circle with radius: " << circle.getRadius();
// }
