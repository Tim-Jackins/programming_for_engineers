#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

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
  /*
    Display employee info tab separated
  */
  string info = "";
  info += emp.name + "\t\t";
  info += to_string(emp.salary) + "\t\t";
  info += to_string(emp.years_worked);
  return info;
}

string displayEmployeeArray(const Employee arr[], int length)
{
  /*
    Display employee data in array arr of length length in csv format
  */
  string full_info = "";
  full_info += "Name\t\tSalary\t\tSeniority\n";

  for (int i = 0; i < length; i++)
  {
    full_info += displayEmployeeInfo(arr[i]);
    full_info += '\n';
  }

  return full_info;
}

string displayCSVEmployeeInfo(const Employee &emp)
{
  /*
    Display employee info comma separated
  */
  string info = "";
  info += emp.name + ",";
  info += to_string(emp.salary) + ",";
  info += to_string(emp.years_worked);
  return info;
}

string displayCSVEmployeeArray(const Employee arr[], int length)
{
  /*
    Display employee data in array arr of length length in csv format
  */
  string full_info = "";
  full_info += "Name,Salary,Seniority\n";

  for (int i = 0; i < length; i++)
  {
    full_info += displayCSVEmployeeInfo(arr[i]);
    full_info += '\n';
  }

  return full_info;
}

void openFiles(const string filenames[], ifstream files[])
{
  /*
    Open files if ifstream array
  */

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
  /*
    Close files if ifstream array
  */

  for (int i = 0; i < number_of_files; i++)
  {
    files[i].close();
  }
}

string toupper(string str)
{
  /*
    Make string str uppercase
  */
  string ret_string = "";
  for (int i = 0; i < str.length(); i++)
  {
    ret_string += toupper(str[i]);
  }

  return ret_string;
}

bool greaterThan(string a, string b)
{
  /*
    Function to check the condition a > b
  */

  int min_length;
  a = toupper(a);
  b = toupper(b);

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
      return a[i] > b[i];
    }
  }

  return (a.length() > b.length());
}

vector<Employee> readSortData(ifstream *files, const int number_of_files)
{
  vector<Employee> employee_info;

  string file_values[number_of_files];
  int line_index = 0;
  // Assuming all files are of the same length read them until there's NOTHING LEFT
  while (files[0] >> file_values[0])
  {
    // Read from all open files
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
        // Perform insertion placement
        if (greaterThan(past_employee.name, temp_employee.name))
        {
          employee_info.insert(employee_info.begin() + ((vector_index - 1 < 0) ? 0 : vector_index - 1), temp_employee);
          completed_loop = false;
          break;
        }
        else
        {
          past_employee = employee_info[vector_index];
        }
      }
      if (completed_loop) // For loop exits without placing temp_employee
      {
        employee_info.push_back(temp_employee);
      }
      /*
        The weird for if structure is to be a c++ version of pythons for else loop

        for item in container:
          if search_something(item):
            # Found it!
            process(item)
            break
          else:
            # Didn't find anything..
            not_found_in_container()
      */
    }

    line_index++;
  }
  return employee_info;
}

int binarySearch(Employee arr[], int lower_bound, int upper_bound, string x)
{
  /*
    Perform binary search on an array of Employees

    arr:
      Array to be searched
    
    lower_bound:
      Lower bound of search
    
    upper_bound:
      Upper bound of search

    x:
      Employee to look for
  */
  if (upper_bound >= lower_bound)
  {
    int mid = lower_bound + (upper_bound - lower_bound) / 2;

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

void cleanInput(string prompt_string, string prompt_name, int *output)
{
  /*
    Clean integar inputs

    prompt_string:
      What should the user be prompted with
    
    prompt_name:
      The name of thing you're entering
    
    output:
      Where the output is saved
  */
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

void cleanInput(string prompt_string, string prompt_name, string *output)
{
  /*
    Clean string inputs

    prompt_string:
      What should the user be prompted with
    
    prompt_name:
      The name of thing you're entering
    
    output:
      Where the output is saved
  */
  string cleaned_input;
  string user_input;
  cout << prompt_string;
  getline(cin, user_input);
  try
  {
    for (int i = 0; i < user_input.length(); i++)
    {
      if (!isalpha(user_input[i]))
      {
        throw "Input contains number";
      }
    }
    cleaned_input = toupper(user_input);
    *output = cleaned_input;
  }
  catch (...)
  {
    cout << '\n'
         << "Please insert a valid " << prompt_name << "!\n";
    return cleanInput(prompt_string, prompt_name, output);
  }
}

void cleanInput(string prompt_string, string prompt_name, char *output)
{
  /*
    Clean character inputs

    prompt_string:
      What should the user be prompted with
    
    prompt_name:
      The name of thing you're entering
    
    output:
      Where the output is saved
  */
  char cleaned_input;
  string user_input;
  cout << prompt_string;
  getline(cin, user_input);
  try
  {
    if ((user_input.length() == 1) and ((user_input.compare("y") == 0) or (user_input.compare("n") == 0)))
    {
      cleaned_input = user_input[0];
      *output = cleaned_input;
    }
    else
    {
      throw "Input doesn't follow rules";
    }
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
  /*
    Swaps 2 employee structs
  */
  Employee holder = *x;
  *x = *y;
  *y = holder;
}

int partition(Employee arr[], int low, int high, int option)
{
  /*
    Run quicksort partition on employee array
  */
  Employee pivot = arr[high]; // pivot
  int i = (low - 1);          // Index of smaller element

  for (int j = low; j <= high - 1; j++)
  {
    switch (option) // Sort based on user choice
    {
    case 1: // Name
      // If current element is smaller than the pivot
      if (greaterThan(pivot.name, arr[j].name))
      {
        i++; // increment index of smaller element
        swap(arr[i], arr[j]);
      }
      break;
    case 2: // Salary
      // If current element is smaller than the pivot
      if (pivot.salary > arr[j].salary)
      {
        i++; // increment index of smaller element
        swap(arr[i], arr[j]);
      }
      break;
    case 3: // Years worked
      // If current element is smaller than the pivot
      if (pivot.years_worked > arr[j].years_worked)
      {
        i++; // increment index of smaller element
        swap(arr[i], arr[j]);
      }
      break;
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void employeeQuickSort(Employee arr[], int low, int high, int option = 1)
{
  /*
  arr:
    employee info array that needs to be sorted

  low: start of array

  high: end of array

  Option: By what field should we order the employees
    1. Name
    2. Salary
    3. Seniority
  */

  if ((low < high) and (option != 1)) // no need to sort for option one because of readSortData
  {
    /* pi is partitioning index, arr[p] is now  
        at right place */
    int pi = partition(arr, low, high, option);

    // Separately sort elements before
    // partition and after partition
    employeeQuickSort(arr, low, pi - 1, option);
    employeeQuickSort(arr, pi + 1, high, option);
  }
}

int main()
{

  system("clear");
  /*
    Must match the employee struct!
  */
  string filenames[] = {"list_of_names", "list_of_salaries", "list_of_years_worked"};

  // Create file object for every file named in filenames
  int number_of_files = ARRAY_LENGTH(filenames);
  ifstream files[number_of_files];

  const clock_t begin_time_read = clock();

  // Open files, sort them using what feels like an insertion sort, close files
  openFiles(filenames, files);
  vector<Employee> employee_info_vector = readSortData(files, number_of_files);
  closeFiles(files, number_of_files);

  // Cool little trick for array to vector conversion
  Employee employee_info[employee_info_vector.size()];
  copy(employee_info_vector.begin(), employee_info_vector.end(), employee_info);

  cout << "Data loaded in " << (1000.0 * (clock() - begin_time_read)) / CLOCKS_PER_SEC << " ms" << endl;

  // Prompt user to search database
  char search_choice = 'n';
  cleanInput("Would you like to search the database for an employee (y or n): ", "character (y or n)", &search_choice);

  // Keep prompting and searching until the user types n
  while (search_choice == 'y')
  {
    string query_name;
    cleanInput("What is the name of the employee you would like to look up: ", "name of an employee", &query_name);

    clock_t begin_time_query = clock();
    int result = binarySearch(employee_info, 0, ARRAY_LENGTH(employee_info) - 1, query_name);
    (result == -1) ? cout << "Couldn't find employee " << query_name << " in database." << endl
                   : cout << "Name\t\tSalary\t\tSeniority" << endl
                          << "-----------------------------------------" << endl
                          << displayEmployeeInfo(employee_info[result]) << endl;
    cout << "Query completed in " << (1000.0 * (clock() - begin_time_query)) / CLOCKS_PER_SEC << " ms" << endl;

    cout << endl;
    cleanInput("Would you like to search the database for an employee (y or n): ", "character (y or n)", &search_choice);
  }

  // Prompt user for report sort options
  cout << "1. Alphabetical list" << endl
       << "2. Salary rank list" << endl
       << "3. Seniority rank list" << endl;

  int option;
  cleanInput("Which report should I prepare: ", "integar (1, 2, 3)", &option);
  while (!((1 <= option) and (option <= 3)))
  {
    cout << "The number you submit must be either 1, 2, or 3" << endl;
    cleanInput("Which report should I prepare: ", "integar (1, 2, 3)", &option);
  }

  const clock_t begin_time_sort = clock();

  // Sort db with respect to the chosen column
  employeeQuickSort(employee_info, 0, ARRAY_LENGTH(employee_info) - 1, option);

  cout << "Report: " << endl
       << displayEmployeeArray(employee_info, ARRAY_LENGTH(employee_info)) << endl;

  cout << "Report sorted in " << (1000.0 * (clock() - begin_time_sort)) / CLOCKS_PER_SEC << " ms and saved in report.csv";

  // Save report to file
  ofstream output_file;
  output_file.open("report.csv");
  if (!output_file)
  {
    cout << "Unable to open file: report.csv";
    exit(1);
  }
  output_file << displayCSVEmployeeArray(employee_info, ARRAY_LENGTH(employee_info));
  output_file.close();

  return 0;
}
