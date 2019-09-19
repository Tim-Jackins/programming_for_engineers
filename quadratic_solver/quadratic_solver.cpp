#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <bits/stdc++.h>

#define ITERATION_LIMIT 10000

using namespace std;


double quad(double a, double b, double c, double x)
{
  /*
    a, b, c are the coefficients of a quadratic
    x is the value at which the quadratic is evaluated
  */
  return (a * x * x + b * x + c); // returns f(x) for the quad ax^2+bx+c
}

double slope(double a, double b, double c, double x)
{
  /*
    a, b, and c are the coefficients of the quadratic
    x is the value at which the derivative is evaluated
  */
  return (2 * a * x + b); // returns f'(x) for the quad ax^2+bx+c
}

double det(double a, double b, double c)
{
  /*
    a, b, and c are the coefficients of the quadratic
    x is the value at which the derivative is evaluated
  */
  return (b * b - 4 * a * c); // returns the determinent of the quad ax^2+bx+c
}

double vert(double a, double b, double c)
{
  /*
    a, b, and c are the coefficients of the quadratic
    x is the value at which the derivative is evaluated
  */
  return (-b) / (2 * a); // returns the vertex of the quad ax^2+bx+c
}

double newtonRhapson(double a, double b, double c, double x, double err, double tol)
{
  int count = 0;
  while ((abs(err) >= tol) and (count < ITERATION_LIMIT))
  {
    err = quad(a, b, c, x) / slope(a, b, c, x);

    // Newton Rhapson:
    // x(i+1) = x(i) - f(x) / f'(x)
    x = x - err;

    count++;
  }
  cout << count;
  if (count > 10000) cout << "Oops, I hit the iteration limit";
  return x;
}

bool isPerfectSquare(double x)
{
  /*
    1. Take the square root of the number.
    2. Take floor/ceil/round of the square root which we got in step 1.
    3. Subtract value we got in step 2 from the square root.
    4. If the output of step 3 is 0 then the number is perfect square else not.
  */
  double sqrRoot = sqrt(x);
  double rootFloor = floor(sqrRoot);
  return !(sqrRoot - rootFloor);
}

double cleanDouble(string promptString, string promptName)
{
  double cleanedInput;
  string userInput;
  cout << promptString;
  getline(cin, userInput);
  try
  {
    for (char i : userInput)
    {
      if (isalpha(i))
      {
        throw "Input contains character";
      }
    }
    cleanedInput = stod(userInput);
  }
  catch (...)
  {
    cout << '\n'
         << "Please insert a valid " << promptName << "!\n";
    return cleanDouble(promptString, promptName);
  }
}

int main()
{
  system("clear");
  double a, b, c;     // coeffs ax^2+bx+c, user input
  double x;           // value at which f(x) will be evaluated
  double determinant; // determinant of ax^2+bx+c
  double tol;         // error tolerance (for while loop)
  double err;         // error described fo f(x)/f'(x)

  //get the quadratic from the user...
  cout << "This program will numerically find a zeros of a quadratic function multiple methods.\n";
  cout << "For the quadratic ax^2 + bx+ c, please insert...\n\n";

  a = cleanDouble("a: ", "coefficient");
  b = cleanDouble("b: ", "coefficient");
  c = cleanDouble("c: ", "coefficient");

  determinant = det(a, b, c);

  if (determinant < 0)
  { // Two zeros that are complex conjugates
    cout << "Complex conjugates ಠ_ಠ:\n";
    if (isPerfectSquare(abs(determinant)))
    {
      cout << (2 * -b)/(2 * a) << " ± " << sqrt(abs(determinant)) / (2 * a) << "i";
    }
    else
    {
      cout << "Gross decimals with imaginary numbers!" << '\n'
           << "(╯°□°）╯︵ ┻━┻";
    }
  }
  else if (determinant == 0)
  { // One zero with a multiplicity of two
    cout << "You've picked a vertex!\n";
    double vertex;
    vertex = (-b) / (2 * a);
    cout << "x= " << vertex;
  }
  else if (isPerfectSquare(determinant))
  { // Two distint rational zeros
    cout << "Two distinct rational zeros:" << '\n';
    double x1, x2;
    x1 = (-b + sqrt(determinant)) / (2 * a);
    x2 = (-b - sqrt(determinant)) / (2 * a);

    cout << "x= " << x1 << ", " << x2;
  }
  else
  {
    cout << "Approximating with Rhapson Newton method!\n";
    tol = cleanDouble("Enter a tolerance: ", "tolerance");
    err = quad(a, b, c, x) / slope(a, b, c, x);

    x = newtonRhapson(a, b, c, x, err, tol);

    double vertex = vert(a, b, c);
    double otherx = -(x - 2 * vertex); //newtonRhapson(a, b, c, , err, tol);

    cout << "Root approximations (ε <= " << tol << "):\n";
    cout << "x= " << x << ", " << otherx;
  }
  return 0;
}

/*
Pretty Imaginery test:

This program will numerically find a zeros of a quadratic function multiple methods.
For the quadratic ax^2 + bx+ c, please insert...

a: 1
b: 4
c: 5
Complex conjugates ಠ_ಠ:
-4 ± 1i


Gross Imaginery test:

This program will numerically find a zeros of a quadratic function multiple methods.
For the quadratic ax^2 + bx+ c, please insert...

a: 1
b: 4
c: 4.75
Complex conjugates ಠ_ಠ:
Gross decimals with imaginary numbers!
(╯°□°）╯︵ ┻━┻


Vertex root test:

This program will numerically find a zeros of a quadratic function multiple methods.
For the quadratic ax^2 + bx+ c, please insert...

a: 1
b: 1
c: .25
You've picked a vertex!
x= -0.5


Perfect square determinant test:

This program will numerically find a zeros of a quadratic function multiple methods.
For the quadratic ax^2 + bx+ c, please insert...

a: 1
b: -1
c: -6
Two distinct rational zeros:
x= 3, -2


Newton Rhapson Approximation:

This program will numerically find a zeros of a quadratic function multiple methods.
For the quadratic ax^2 + bx+ c, please insert...

a: 1
b: 15
c: 5
Approximating with Rhapson Newton method!
Enter a tolerance: .001
Root approximations (ε <= 0.001):
x= -0.341089, -14.6589

*/
