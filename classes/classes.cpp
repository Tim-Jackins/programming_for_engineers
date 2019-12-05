#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>  

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

int _gcd(int a, int b) 
{ 
	if (a == 0) 
		return b; 
	if (b == 0) 
		return a; 
  if (a == b) 
    return a; 
  if (a > b) 
    return _gcd(a-b, b); 
  return _gcd(a, b-a); 
} 

class Fraction
{
private:
	int num, denom;

public:
	Fraction(int new_num, int new_denom)
	{
		num = new_num;
		denom = new_denom;
	}
	// Gets
	int getNum() { return num; }
	int getDenom() { return denom; }

	// Sets
	void setNum(int new_num) { num = new_num; }
	void setDenom(int new_denom) { denom = new_denom; }

	// Methods
	void reduce();

	// Operators
	Fraction operator+ (Fraction frac2);
  Fraction operator- (Fraction frac2);
};

void Fraction::reduce(){
	int gcd = _gcd(num, denom);
  num /= gcd;
  denom /= gcd;
}

Fraction Fraction::operator+(Fraction frac2)
{
	int new_num;
	int new_denom;

	if (denom == new_denom){
		cout << "Same denom" << endl;
		new_num = num + frac2.num;
		new_denom = denom;

		Fraction new_frac(new_num, new_denom);
    new_frac.reduce();
		return new_frac;
	}

	new_num = (frac2.num * denom) + (frac2.denom * num);
	new_denom = (frac2.denom * denom);

	Fraction new_frac(new_num, new_denom);
  new_frac.reduce();
	return new_frac;
}

Fraction Fraction::operator-(Fraction frac2)
{
	int new_num;
	int new_denom;

	if (denom == new_denom){
		cout << "Same denom" << endl;
		new_num = num - frac2.num;
		new_denom = denom;

		Fraction new_frac(new_num, new_denom);
    new_frac.reduce();
		return new_frac;
	}

	new_num = (frac2.denom * num) - (frac2.num * denom);
	new_denom = (frac2.denom * denom);

	Fraction new_frac(new_num, new_denom);
  new_frac.reduce();
	return new_frac;
}

ostream& operator<<(ostream &strm, Fraction &frac) {
	return strm << frac.getNum() << "/" << frac.getDenom();
}

int main()
{
	Fraction frac1(2, 3);
	Fraction frac2(1, 3);
	Fraction frac3 = frac1 - frac2;
	cout << frac3 << endl;

	return 0;
}
