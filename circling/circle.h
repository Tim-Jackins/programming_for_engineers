#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <fstream>

#define _USE_MATH_DEFINES

using namespace std;

class Circle
{
private:
	double _radius;
	double _center_x;
	double _center_y;

public:
	Circle(double new_radius, double* new_center)
	{
		_radius = new_radius;
		_center_x = new_center[0];
		_center_y = new_center[0];
	}

	// Gets
	double getRadius() { return _radius; }
  double getDiameter() { return _radius * 2; }
	double getCenterX() { return _center_x; }
	double getCenterY() { return _center_y; }

	// Sets
	void setRadius(double new_radius) { _radius = new_radius; }
  void setDiameter(double new_diameter) { _radius = new_diameter / 2; }
	void setCenterX(double new_center_x) { _center_x = new_center_x; }
	void setCenterY(double new_center_y) { _center_y = new_center_y; }

	// Methods
  double circumference();
  double area();
	
	bool testPoint(double x, double y)
	{
		bool isOn = (pow(x - _center_x, 2) + pow(y - _center_y, 2)) == pow(_radius, 2);
		
		cout << (pow(x - _center_x, 2) + pow(y - _center_y, 2)) << endl;
		cout << pow(_radius, 2) << endl;

		return isOn;
	}

	// Operators
	// Fraction operator+ (Fraction frac2);
	// Fraction operator- (Fraction frac2);
};

double Circle::circumference(){
	return 2.0 * M_PI * _radius;
}

double Circle::area(){
  return M_PI * pow(_radius, 2);
}

ostream& operator<<(ostream &strm, Circle &circle) {
	return strm << "Circle with radius: " << circle.getRadius();
}
