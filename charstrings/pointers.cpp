#include <iostream>
#include <cctype>

#define SIZE 10
#define ARRAY_LENGTH(arr) (*(&arr + 1) - arr)

using namespace std;

int main()
{
    char name[SIZE];
    string myName = "Jack";
    myName += "A C T";
    cout << myName.length();

    //for (int i = 0; i < ARRAY_LENGTH(name); i++) {
    //    cout << name[i];
    //}

    return 0;
}
