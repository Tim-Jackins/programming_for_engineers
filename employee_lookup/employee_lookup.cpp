#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <fstream>
#include <stdlib.h>

#define DEBUG true

#define ARRAY_LENGTH(arr) (*(&arr + 1) - arr)

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

string displayEmployeeInfo(const Employee &emp)
{
  string info = "";
  info += emp.name + "|";
  info += to_string(emp.salary) + "|";
  info += to_string(emp.years_worked);
  return info;
}

void openFiles(const string filenames[], ifstream files[])
{
  for (int i = 0; i < ARRAY_LENGTH(filenames); i++)
  {
    files[i].open(filenames[i] + ".txt");
    if (!files[i])
    {
      cout << "Unable to open file: " << filenames[i] + ".txt";
      exit(1);
    }
  }
}

void closeFiles(ifstream files[], int number_of_files)
{
  for (int i = 0; i < number_of_files; i++)
  {
    files[i].close();
  }
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
  // cout << "measuring " << a << "|" << b << endl;
  if (a.length() > b.length())
  {
    min_length = b.length();
  }
  else
  {
    min_length = a.length();
  }
  // cout << "minlength = " << min_length << endl;

  for (int i = 0; i < min_length; i++)
  {
    if (a[i] != b[i])
    {
      // cout << a[i] << " > " << b[i] << " = " << (a[i] > b[i]) << endl;
      return a[i] > b[i];
    }
  }

  return (a.length() > b.length());
}

vector<Employee> readSortData(ifstream *files)
{

}

int main()
{
  system("clear");
  /*
    Must match the employee struct!
  */
  string filenames[] = {"list_of_names", "list_of_salaries", "list_of_years_worked"};

  int number_of_files = ARRAY_LENGTH(filenames);

  ifstream files[number_of_files];

  openFiles(filenames, files);

  vector<Employee> employee_info;

  string file_values[number_of_files];
  int line_index = 0;
  while (files[0] >> file_values[0])
  {
    for (int i = 1; i < number_of_files; i++)
    {
      files[i] >> file_values[i];
    }

    /*
      Must match the struct and the file list
    */
    Employee temp_employee;
    temp_employee.name = file_values[0];
    temp_employee.salary = stoi(file_values[1]);
    temp_employee.years_worked = stoi(file_values[2]);
    
    // cout << endl << "Sorting {" << temp_employee.name << "}" << endl;
    
    if (employee_info.size() == 0)
    {
      // cout << "Placing " << temp_employee.name << " at start." << endl;
      employee_info.push_back(temp_employee);
    }
    else
    {
      bool completed_loop = true;
      Employee past_employee = employee_info[0];

      for (int vector_index = 1; vector_index <= employee_info.size(); vector_index++)
      {
        if (greaterThan(past_employee.name, temp_employee.name))
        {

          // cout << temp_employee.name << " goes before " << past_employee.name << endl;
          employee_info.insert(employee_info.begin() + ((vector_index - 1 < 0) ? 0 : vector_index - 1), temp_employee);
          // for (int j = 0; j < employee_info.size(); j++)
          // {
          //   cout << employee_info[j].name << " ";
          // }
          // cout << endl;
          completed_loop = false;
          break;
        }
        else
        {
          past_employee = employee_info[vector_index];
        }
      }
      if (completed_loop)
      {
        // cout << "Placing " << temp_employee.name << " last" << endl;
        employee_info.push_back(temp_employee);
        // for (int j = 0; j < employee_info.size(); j++)
        // {
        //   cout << employee_info[j].name << " ";
        // }
        // cout << endl;
      }
    }

    line_index++;
  }
  // cout << endl;

  closeFiles(files, number_of_files);

  for (int i = 0; i < employee_info.size(); i++)
  {
    cout << displayEmployeeInfo(employee_info[i]) << endl;
  }

  return 0;
}
