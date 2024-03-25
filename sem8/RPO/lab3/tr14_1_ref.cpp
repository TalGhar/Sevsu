#include <iostream>
#include <string>

using namespace std;

double calculateInsuranceCost(int age, string carType, bool hasAccidents)
{
    double baseCost = 0.0;
    double accidentSurcharge = 0.0;

    if (age < 25)
    {
        baseCost = 1.0;
    }
    else if (age < 50)
    {
        baseCost = 0.5;
    }
    else
    {
        baseCost = 0.4;
    }

    if (carType == "sedan")
    {
        baseCost *= 1000.0;
    }
    else if (carType == "suv")
    {
        baseCost *= 1500.0;
    }
    else if (carType == "sports")
    {
        baseCost *= 2000.0;
    }

    if (hasAccidents)
    {
        accidentSurcharge = 0.5;
    }

    return baseCost + (baseCost * accidentSurcharge);
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
