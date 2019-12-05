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

class Person
{
private:
	string _name;
	int _age;

public:
	Person(string new_name = "", int new_age = 0)
	{
		_name = new_name;
		_age = new_age;
	}
	// Gets
	string getName() { return _name; }
	int getAge() { return _age; }

	// Sets
	void setName(string new_name) { _name = new_name; }
	void setAge(int new_age) { _age = new_age; }
};

class Officer : public Person
{
private:
	int _salary;
	string _rank;
public:
	Officer(int new_salary = 0, string new_rank = "Private")
		: _salary(new_salary), _rank(new_rank)
	{
	}

	// Gets
	int getSalary() { return _salary; }
	string getRank() { return _rank; }

	// Sets
	void setSalary(int new_salary) { _salary = new_salary; } 
	void setRank(string new_rank) { _rank = new_rank; }
};

ostream& operator<<(ostream &strm, Person &person) {
	return strm << "Name: " << person.getName() << endl
		<< "Age: " << person.getAge() << endl;
}

ostream& operator<<(ostream &strm, Officer &officer) {
	return strm << "Name: " << officer.getName() << endl
		<< "Age: " << officer.getAge() << endl
		<< "Salary: " << officer.getSalary() << endl
		<< "Rank: " << officer.getRank();
}

int main()
{
	Officer officer1;
	officer1.setName("Bob");
	officer1.setAge(20);
	officer1.setSalary(1234);
	cout << officer1 << endl
	<< "_____________" << endl;
	officer1.setRank("Whatever above private is called");
	cout << officer1 << endl
	<< "______________________________________" << endl;
	return 0;
}
