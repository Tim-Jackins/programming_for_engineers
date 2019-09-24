#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdint.h>
#include <bits/stdc++.h>

// In usd
#define GAS_COST 0.27
#define MAX_BREAKFAST_COST 9.0
#define MAX_LUNCH_COST 12.0
#define MAX_DINNER_COST 16.0
#define MAX_PARKING_FEE 6.0
#define MAX_TAXI_FEE 10.0
#define MAX_HOTEL_COST 90.0

using namespace std;

double round(double &var)
{
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}

double arraySum(vector<double> &v)
{
    double initial_sum = 0;
    return accumulate(v.begin(), v.end(), initial_sum);
}

int main()
{
    //system("clear");

    double maximumExpense = 0.0;

    int daysSpent;
    cout << "How many days will you be on the trip? ";
    cin >> daysSpent;

    int leaveTimeRaw;
    char leaveModifier;
    int leaveTime;
    cout << "What time will you leave (to the nearest hour)? ";
    cin >> leaveTimeRaw;
    cout << "AM (a) or PM (p)? ";
    cin >> leaveModifier;

    leaveTime = (leaveModifier == 'a') ? leaveTimeRaw : (leaveTimeRaw + 12);

    int homeTimeRaw;
    char homeModifier;
    int homeTime;
    cout << "What time will you arrive home (to the nearest hour)? ";
    cin >> homeTimeRaw;
    cout << "AM (a) or PM (p)? ";
    cin >> homeModifier;

    homeTime = (homeModifier == 'a') ? homeTimeRaw : (homeTimeRaw + 12);

    // Airfare cost start
    double airfareCost;
    cout << "What is the cost of airfare? ";
    cin >> airfareCost;
    maximumExpense += airfareCost;
    // Airfare cost end

    // Hotel cost start
    double hotelCost;
    cout << "What is the total cost for hotels (per night)? ";
    cin >> hotelCost;
    hotelCost *= (daysSpent - 1);
    maximumExpense += MAX_HOTEL_COST * (daysSpent - 1);
    // Hotel cost end

    // Car cost start
    double carCost;
    char carModifier;
    cout << "Did you drive your own car (y/n)? ";
    cin >> carModifier;

    if (carModifier == 'y')
    {
        cout << "How many miles did you drive? ";
        double milesDriven;
        cin >> milesDriven;

        carCost = 0.27 * (double)milesDriven;
    }
    else
    {
        cout << "What is the cost of car rentals? ";
        cin >> carCost;
    }
    maximumExpense += carCost;
    // Car cost end

    // Parking, taxi, and food cost start
    int dayCount = 0;

    // There's no real point to me using a vector instead of an array...
    // I'm pretty sure it made a simpler to make the sum function.
    vector<double> parkingFeeArray(daysSpent);
    vector<double> taxiFeeArray(daysSpent);

    double tempHolder;
    double foodCost = 0.0;

    cout << "For day " << (dayCount + 1) << ", what were your parking fees? ";
    cin >> parkingFeeArray[dayCount];
    if (parkingFeeArray[dayCount] > 0)
        maximumExpense += MAX_PARKING_FEE;
    cout << "For day " << (dayCount + 1) << ", what were your taxi fees? ";
    cin >> taxiFeeArray[dayCount];

    if (leaveTime < 7)
    {
        cout << "How much was breakfast? ";
        cin >> tempHolder;
        foodCost += tempHolder;
        maximumExpense += MAX_BREAKFAST_COST;
    }
    if (leaveTime < 12)
    {
        cout << "How much was lunch? ";
        cin >> tempHolder;
        foodCost += tempHolder;
        maximumExpense += MAX_LUNCH_COST;
    }
    if (leaveTime < 18)
    {
        cout << "How much was dinner? ";
        cin >> tempHolder;
        foodCost += tempHolder;
        maximumExpense += MAX_DINNER_COST;
    }

    for (dayCount = 1; dayCount < (daysSpent - 1); dayCount++)
    {
        cout << "For day " << (dayCount + 1) << ", what were your parking fees? ";
        cin >> parkingFeeArray[dayCount];
        maximumExpense += MAX_PARKING_FEE;
        cout << "For day " << (dayCount + 1) << ", what were your taxi fees? ";
        cin >> taxiFeeArray[dayCount];

        cout << "How much was breakfast? ";
        cin >> tempHolder;
        foodCost += tempHolder;
        maximumExpense += MAX_BREAKFAST_COST;

        cout << "How much was lunch? ";
        cin >> tempHolder;
        foodCost += tempHolder;
        maximumExpense += MAX_LUNCH_COST;

        cout << "How much was dinner? ";
        cin >> tempHolder;
        foodCost += tempHolder;
        maximumExpense += MAX_DINNER_COST;
    }

    cout << "For day " << daysSpent << ", what were your parking fees? ";
    cin >> parkingFeeArray[dayCount];
    if (parkingFeeArray[dayCount] > 0)
        maximumExpense += MAX_PARKING_FEE;
    cout << "For day " << daysSpent << ", what were your taxi fees? ";
    cin >> taxiFeeArray[dayCount];

    if (homeTime > 8)
    {
        cout << "How much was breakfast? ";
        cin >> tempHolder;
        foodCost += tempHolder;
        maximumExpense += MAX_BREAKFAST_COST;
    }
    if (homeTime > 13)
    {
        cout << "How much was lunch? ";
        cin >> tempHolder;
        foodCost += tempHolder;
        maximumExpense += MAX_LUNCH_COST;
    }
    if (homeTime > 19)
    {
        cout << "How much was dinner? ";
        cin >> tempHolder;
        foodCost += tempHolder;
        maximumExpense += MAX_DINNER_COST;
    }
    // Parking, taxi, and food cost end
    
    if (arraySum(taxiFeeArray) > 0)
        maximumExpense += MAX_TAXI_FEE * daysSpent;

    double totalExpenses = airfareCost + hotelCost + carCost + foodCost + arraySum(parkingFeeArray) + arraySum(taxiFeeArray);

    cout << "\nTotal expenses incurred by traveller: " << totalExpenses << endl
         << "Maximum allowable expenses: " << maximumExpense << endl;

    double expenseDelta = maximumExpense - totalExpenses;
    if (expenseDelta > 0)
        cout << "You saved the company $" << expenseDelta << ".";
    else
        cout << "You must reimburse the company for the $" << abs(expenseDelta) << " coverages.";

        return 0;
}

/*

Example stdouts

How many days will you be on the trip? 3
What time will you leave (to the nearest hour)? 6
AM (a) or PM (p)? a
What time will you arrive home (to the nearest hour)? 9
AM (a) or PM (p)? p
What is the cost of airfare? 250.0
What is the total cost for hotels (per night)? 175.0
Did you drive your own car (y/n)? n
What is the cost of car rentals? 75.12
For day 1, what were your parking fees? 5.0
For day 1, what were your taxi fees? 0.0
How much was breakfast? 6.76
How much was lunch? 8.75
How much was dinner? 12.33
For day 2, what were your parking fees? 5.0
For day 2, what were your taxi fees? 0.0
How much was breakfast? 5.12
How much was lunch? 9.87
How much was dinner? 15.52
For day 3, what were your parking fees? 5.0
For day 3, what were your taxi fees? 0.0
How much was breakfast? 6.5
How much was lunch? 7.5
How much was dinner? 12.75

Total expenses incurred by traveller: 775.22
Maximum allowable expenses: 634.12
You must reimburse the company for the $141.1 coverages.


How many days will you be on the trip? 3
What time will you leave (to the nearest hour)? 2
AM (a) or PM (p)? p
What time will you arrive home (to the nearest hour)? 3
AM (a) or PM (p)? p
What is the cost of airfare? 0.0
What is the total cost for hotels (per night)? 210.52
Did you drive your own car (y/n)? y
How many miles did you drive? 109.0
For day 1, what were your parking fees? 8.5
For day 1, what were your taxi fees? 11.5
How much was dinner? 25.75
For day 2, what were your parking fees? 10.0
For day 2, what were your taxi fees? 12.5
How much was breakfast? 11.76
How much was lunch? 13.52
How much was dinner? 21.21
For day 3, what were your parking fees? 10.0
For day 3, what were your taxi fees? 13.75
How much was breakfast? 13.0
How much was lunch? 15.23

Total expenses incurred by traveller: 617.19
Maximum allowable expenses: 331.43
You must reimburse the company for the $285.76 coverages.

*/