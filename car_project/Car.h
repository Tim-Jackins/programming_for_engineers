#include <iostream>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include "FuelGuage.h"
#include "Odometer.h"

// In miles per gallon
#ifndef FUEL_ECONOMY
#define FUEL_ECONOMY 24
#endif

using namespace std;

class Car : public FuelGauge, public Odometer
{
private:
  FuelGauge _fuel_gauge;
  Odometer _odometer;

public:
  Car(FuelGauge &new_fuel_gauge, Odometer &new_odometer)
  {
    _fuel_gauge = new_fuel_gauge;
    _odometer = new_odometer;
  }

  // Gets
  int getFuelAmount() { return _fuel_gauge.getFuelAmount(); }
  double getMileage() { return _odometer.getMileage(); }

  // Sets
  void setMileage(int new_mileage) { _odometer.setMileage(new_mileage); }

  // Methods
  void displayInfo()
  {
    // cout << "Fuel:     " << _fuel_gauge.getFuelAmount() << " gallons" <<
    // endl << "Odometer: " << _odometer.getMileage() << " miles" << endl;
    cout << "The odometer currently reads " << _odometer.getMileage() << " miles." <<
    endl << "The fuel gauge reads " << _fuel_gauge.getFuelAmount() << " gallons." << endl;

  }

  void drive()
  {
    _fuel_gauge--;
    _odometer++;
    // cout << FUEL_INCREMENT << " Gallon spent" << endl;
    // cout << FUEL_ECONOMY * FUEL_INCREMENT << " miles driven" << endl;
  }

  void fuel()
  {
    _fuel_gauge++;
  }
};

// ostream& operator<<(ostream &strm, Circle &circle) {
// return strm << "Circle with radius: " << circle.getRadius();
// }
