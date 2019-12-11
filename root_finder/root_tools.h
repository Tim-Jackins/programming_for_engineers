#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <fstream>

#define _USE_MATH_DEFINES

using namespace std;



// class Circle
// {
// private:
// 	double _radius;

// public:
// 	Circle(int new_radius)
// 	{
// 		_radius = new_radius;
// 	}
// 	// Gets
// 	double getRadius() { return _radius; }
//   double getDiameter() { return _radius * 2; }

// 	// Sets
// 	void setRadius(double new_radius) { _radius = new_radius; }
//   void setDiameter(double new_diameter) { _radius = new_diameter / 2; }

// 	// Methods
//   double circumference();
//   double area();
  

// 	// Operators
// 	// Fraction operator+ (Fraction frac2);
// 	// Fraction operator- (Fraction frac2);
// };

// double Circle::circumference(){
// 	return 2.0 * M_PI * _radius;
// }

// double Circle::area(){
//   return M_PI * pow(_radius, 2);
// }

// ostream& operator<<(ostream &strm, Circle &circle) {
// 	return strm << "Circle with radius: " << circle.getRadius();
// }