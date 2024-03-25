#include <iostream>
#include <string>

using namespace std;

double calculateInsuranceCost(int age, string carType, bool hasAccidents)
{
    double cost = 0.0;

    if (age < 25)
    {
        if (carType == "sedan")
        {
            if (hasAccidents)
            {
                cost = 500.0;
            }
            else
            {
                cost = 1000.0;
            }
        }
        else if (carType == "suv")
        {
            if (hasAccidents)
            {
                cost = 750.0;
            }
            else
            {
                cost = 1500.0;
            }
        }
        else if (carType == "sports")
        {
            if (hasAccidents)
            {
                cost = 1000.0;
            }
            else
            {
                cost = 2000.0;
            }
        }
    }
    else if (age < 50)
    {
        if (carType == "sedan")
        {
            if (hasAccidents)
            {
                cost = 250.0;
            }
            else
            {
                cost = 500.0;
            }
        }
        else if (carType == "suv")
        {
            if (hasAccidents)
            {
                cost = 375.0;
            }
            else
            {
                cost = 750.0;
            }
        }
        else if (carType == "sports")
        {
            if (hasAccidents)
            {
                cost = 500.0;
            }
            else
            {
                cost = 1000.0;
            }
        }
    }
    else
    {
        if (carType == "sedan")
        {
            if (hasAccidents)
            {
                cost = 200.0;
            }
            else
            {
                cost = 400.0;
            }
        }
        else if (carType == "suv")
        {
            if (hasAccidents)
            {
                cost = 300.0;
            }
            else
            {
                cost = 600.0;
            }
        }
        else if (carType == "sports")
        {
            if (hasAccidents)
            {
                cost = 400.0;
            }
            else
            {
                cost = 800.0;
            }
        }
    }

    return cost;
}

int main()
{
    int age;
    string carType;
    bool hasAccidents;

    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your car type (sedan, suv, sports): ";
    cin >> carType;
    cout << "Do you have any accidents in the past year (yes/no)? ";
    string answer;
    cin >> answer;
    hasAccidents = (answer == "yes" || answer == "y") ? true : false;

    double cost = calculateInsuranceCost(age, carType, hasAccidents);

    cout << "The cost of insurance is: $" << cost << endl;

    return 0;
}
