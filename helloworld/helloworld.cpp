#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Employee
{
  /*
    Must match the data types of the data in the files with names in filenames!
  */
  string name;
  int salary;
  int years_worked;
};

int foo(int *num)
{
  *num += 2;
  return *num;
}

string toupper(string str)
{
  string ret_string = "";
  for (int i = 0; i < str.length(); i++)
  {
    ret_string += toupper(str[i]);
  }

  return ret_string;
}

bool greaterThan(string a, string b)
{
  int min_length;
  a = toupper(a);
  b = toupper(b);

  cout << a << "|" << b << endl;

  if (a.length() > b.length())
  {
    min_length = b.length();
  }
  else
  {
    min_length = a.length();
  }

  for (int i = 0; i < min_length; i++)
  {
    if (a[i] != b[i])
    {
      cout << a[i] << " > " << b[i] << " = " << (a[i] > b[i]) << endl;
      return a[i] > b[i];
    }
  }

  return (a.length() > b.length());
}

int binarySearch(vector<Employee> arr, int lower_bound, int upper_bound, string x)
{
  if (upper_bound >= lower_bound)
  {
    int mid = lower_bound + (upper_bound - lower_bound) / 2;

    cout << arr[mid].name << endl;
    if (arr[mid].name.compare(x) == 0)
    {
      return mid;
    }

    if (greaterThan(arr[mid].name, x))
    {
      return binarySearch(arr, lower_bound, mid - 1, x);
    }

    return binarySearch(arr, mid + 1, upper_bound, x);
  }

  // We reach here when element is not
  // present in array
  return -1;
}

string displayEmployeeInfo(const Employee &emp)
{
  string info = "";
  info += emp.name + "|";
  info += to_string(emp.salary) + "|";
  info += to_string(emp.years_worked);
  return info;
}

void cleanInput(string prompt_string, string prompt_name, double *output)
{
  double cleaned_input;
  string user_input;
  cout << prompt_string;
  getline(cin, user_input);
  try
  {
    for (int i = 0; i < user_input.length(); i++)
    {
      if (isalpha(user_input[i]))
      {
        throw "Input contains character";
      }
    }
    cleaned_input = stod(user_input);
    *output = cleaned_input;
  }
  catch (...)
  {
    cout << '\n'
         << "Please insert a valid " << prompt_name << "!\n";
    return cleanInput(prompt_string, prompt_name, output);
  }
}

void cleanInput(string prompt_string, string prompt_name, int *output)
{
  int cleaned_input;
  string user_input;
  cout << prompt_string;
  getline(cin, user_input);
  try
  {
    for (int i = 0; i < user_input.length(); i++)
    {
      if (isalpha(user_input[i]))
      {
        throw "Input contains character";
      }
    }
    cleaned_input = stoi(user_input);
    *output = cleaned_input;
  }
  catch (...)
  {
    cout << '\n'
         << "Please insert a valid " << prompt_name << "!\n";
    return cleanInput(prompt_string, prompt_name, output);
  }
}

void swap(Employee *x, Employee *y)
{
  Employee holder = *x;
  *x = *y;
  *y = holder;
}

int main()
{
  int num1 = 1;
  //cout << foo(&num1) << "|" << num1 << endl;

  Employee tempEmployee;
  vector<Employee> test;

  tempEmployee.name = "ADAMS";
  tempEmployee.salary = 88150;
  tempEmployee.years_worked = 1;
  test.push_back(tempEmployee);
  tempEmployee.name = "ALLEN";
  tempEmployee.salary = 98048;
  tempEmployee.years_worked = 5;
  test.push_back(tempEmployee);
  tempEmployee.name = "ANDERSON";
  tempEmployee.salary = 40607;
  tempEmployee.years_worked = 9;
  test.push_back(tempEmployee);
  tempEmployee.name = "BAKER";
  tempEmployee.salary = 139342;
  tempEmployee.years_worked = 1;
  test.push_back(tempEmployee);
  // tempEmployee.name = "BROWN";
  // tempEmployee.salary = 149495;
  // tempEmployee.years_worked = 1;
  // test.push_back(tempEmployee);
  // tempEmployee.name = "CAMPBELL";
  // tempEmployee.salary = 117099;
  // tempEmployee.years_worked = 5;
  // test.push_back(tempEmployee);
  // tempEmployee.name = "CARTER";
  // tempEmployee.salary = 81707;
  // tempEmployee.years_worked = 1;
  // test.push_back(tempEmployee);
  // tempEmployee.name = "CLARK";
  // tempEmployee.salary = 141711;
  // tempEmployee.years_worked = 1;
  // test.push_back(tempEmployee);
  // tempEmployee.name = "COLLINS";
  // tempEmployee.salary = 112395;
  // tempEmployee.years_worked = 2;
  // test.push_back(tempEmployee);

  // for (int i = 0; i < test.size(); i++)
  // {
  //   cout << displayEmployeeInfo(test[i]) << endl;
  // }

  // int x = 0, y = 2;

  // swap(test[x], test[y]);
  // cout << endl
  //      << endl;

  // for (int i = 0; i < test.size(); i++)
  // {
  //   cout << displayEmployeeInfo(test[i]) << endl;
  // }

  // string x = "CLARK";

  // int result = binarySearch(test, 0, test.size() - 1, x);
  // (result == -1) ? cout << "Element is not present in array"
  //                : cout << "Element is present at index " << result;
  
  // string myName;
  // char myNewName[50];
  
  // cout << "throw it: ";
  // cin.getline(myNewName, 50);
  // cout << myNewName << endl;

  // cout << "throw it string: ";
  // getline(cin, myName, '#');
  // cout << myName << endl;

  
  
  return 0;
}
