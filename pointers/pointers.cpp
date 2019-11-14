#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>

using namespace std;

int foo(int &num) {
    num++;
    cout << "Inside: " << num << endl;
    return num;
}

void bar(int *arr) {
    arr[0] += 6;
}

// void bar(int *myArray) {

// }

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int myArr[] = {1,2,3};
    bar(*myArr);
    cout << myArr[0];
    // int a=3,b=7;
    // cout << &a << "|" << &b << endl;
    // cout << a << ", " << b << endl;
    // swap(&a, &b);
    // cout << a << ", " << b << endl;

    // int num = 1;
    // cout << &num << endl;
    // foo(num);
    // cout << "Outside: " << num << endl;

    // int arr[50];// = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // cout << "Outside arr start: " << arr << endl;
    // cout << "Outside arr end: " << *(&arr+1) << endl;

    // //for (int i = 0; i < (*(&arr + 1) - arr); i++)
    // //    cout << "  [" << i << "]: " << &arr[i] << endl;
    

    return 0;
}
