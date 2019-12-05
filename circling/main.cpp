#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <fstream>
#include "circle.h"

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
	cout << "Hello World" << endl;
	
	double my_center[] = {1.0, 1.0};
	Circle circle1(1.0, my_center);
	
	// cout << "Radius:        " << circle1.getRadius() << endl;
  // cout << "Diameter:      " << circle1.getDiameter() << endl;
  // cout << "Circumference: " << circle1.circumference() << endl;
  // cout << "Area:          " << circle1.area() << endl;

	cout << circle1.testPoint(1.0, 2.0) << endl;

	return 0;
}
