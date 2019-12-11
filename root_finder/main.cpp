#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <fstream>
#include "root_tools.h"

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

int getFirstDigit(int n) 
{ 
	// Remove last digit from number 
	// till only one digit is left 
	while (n >= 10) 
		n /= 10;
	// return the first digit 
	return n;
} 

int getDigitalRoot(int num)
{
	// cout << "New num: " << num << endl;

	string string_of_num = to_string(num);
	int sum = 0;

	for (int i = 0; i < string_of_num.length(); i++)
	{
		sum += string_of_num[i] - 48;
	}

	// cout << "Digital root: " << sum << endl;

	return (sum > 9) ? getDigitalRoot(sum) : sum;
}

bool isPerfectSquare(int num)
{
	int first_digit = getFirstDigit(num);
	int digital_root = getDigitalRoot(num);

	if (first_digit == 2 || first_digit == 3 || first_digit == 7 || first_digit == 8)
  {
		// Ending digit cannot be 2, 3, 7 or 8
    return false;
  }
  else if (digital_root == 1 || digital_root == 4 || digital_root == 7 || digital_root == 9)
  {
		// Digital root must be 1, 4, 7, or 9
    return true;
  }
  
  return false;
}

double nthRoot(int A, int N, double digit_accuracy)
{ 
    // intially guessing a random number between 0 and 9 
    double xPast = rand() % 10; 

		double error = pow(10, -digit_accuracy);
		cout << error << endl;
    
    double deltaX = 2147483647.0; // Largest value an integar can take
		double xCurr;
  
    while (deltaX > error) 
    { 
			// calculating current value from previous 
			// value by newton's method
			// https://planetmath.org/nthrootbynewtonsmethod
			xCurr = ((N - 1.0) * xPast + (double)A /
																		pow(xPast, N-1)) /
						(double)N;
			deltaX = abs(xCurr - xPast); 
			xPast = xCurr;
    }

		float rounded_up = ceilf(xCurr * pow(10, digit_accuracy)) / pow(10, digit_accuracy);
  
    return xCurr; 
} 

int main()
{
	// int num1 = 623461;
	// cout << getDigitalRoot(num1) << endl;
  // cout << (isPerfectSquare(num1) ? "Yes" : "No") << endl;

	double digit_accuracy = 3;
	int A = 30;
	int N = 3;
	cout << nthRoot(A, N, digit_accuracy) << endl;
  

	return 0;
}
