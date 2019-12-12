#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <fstream>

// In miles
#define MINIMUM_MILES 0
#define MAXIMUM_MILES 999999

// In gallons
#define MAX_FUEL 15
// Amount of fuel to be spent per drive
#define FUEL_INCREMENT 1

// In miles per gallon
#define FUEL_ECONOMY 24

#include "Car.h"
#define CAR_HAS_FUEL(car) (car.getFuelAmount()>0)
#define CAR_NOT_FULL(car) (car.getFuelAmount()!=MAX_FUEL)

#define ARRAY_LENGTH(arr) (*(&arr + 1) - arr)


using namespace std;

void pprint(double* arr, int length)
{
  cout << "{ ";
  for (int i = 0; i < (length - 1); i++)
  {
    cout << arr[i] << ", ";
  }
  cout << arr[length - 1] << " }" << endl;
}

int main()
{
  FuelGauge fuel_gauge1;
  Odometer odometer1;

  Car car1(fuel_gauge1, odometer1);
  
  car1.setMileage(129783);
  cout << "The odometer currently reads " << car1.getMileage() << " miles." << endl;
  cout << "The fuel gauge reads " << car1.getFuelAmount() << " gallons." << endl;
  cout << "You're out of gas!" << endl;
  cout << "Filling gas tank..." << endl;

  while (CAR_NOT_FULL(car1))
  {
    car1.fuel();
    cout << "The fuel gauge reads " << car1.getFuelAmount() << " gallons" << endl;
  }
  
  cout << "Going for a drive..." << endl;

  while (CAR_HAS_FUEL(car1))
  {
    car1.displayInfo();
  	car1.drive();
  }

  car1.displayInfo();
  
  cout << "Testing the odometer!" << endl;
  while (CAR_NOT_FULL(car1))
  {
    car1.fuel();
  }
  car1.setMileage(MAXIMUM_MILES - (FUEL_ECONOMY*2));

  cout << "Going for a drive..." << endl;

  for (int i = 0; i < 4; i++)
  {
    car1.displayInfo();
  	car1.drive();
  }

  cout << "Retesting the odometer!" << endl;
  while (CAR_NOT_FULL(car1))
  {
    car1.fuel();
  }
  car1.setMileage(MAXIMUM_MILES - (FUEL_ECONOMY*2) - 7);

  cout << "Going for a drive..." << endl;

  for (int i = 0; i < 4; i++)
  {
    car1.displayInfo();
  	car1.drive();
  }
  

  return 0;
}
