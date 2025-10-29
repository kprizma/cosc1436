// Lab 3 - Falling Distance
// Prizma Kunwar
// COSC 1436 - Fall 2025

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const double Gravity = 9.8;

void ShowProgramInformation()
{
    std::cout << "Falling Distance" << std::endl;
    std::cout << "Prizma Kunwar" << std::endl;
    std::cout << "COSC 1436 - Fall 2025" << std::endl << std::endl;
}

//prompting user for falling time
int GetFallingTime()
{
    int time;
    std::cout << "Please enter the number of seconds? ";
    std::cin >> time;
    while (time < 1 || time > 60)
    {
        std::cout << " ERROR: Time must be between 1 and 60 seconds." << std::endl;
        std::cout << "Please enter the number of seconds? ";
        std::cin >> time;
    }
    return time;
}

//Asking user what units to display results in (meters or feet)
char GetUnits()
{
    char units;
    std::cout << "Do you want the results in meters or feet? ";
    std::cin >> units;
    while (units != 'm' && units != 'M' && units != 'f' && units != 'F')
    {
        std::cout << "ERROR: Please enter 'm' for meters or 'f' for feet." << std::endl;
        std::cout << "Do you want the results in meters or feet? ";
        std::cin >> units;

    }
    return units;
}

//calculating the falling distance function using the formula 0.5 * g * t^2.
double CalculateFallingDistance(int seconds)
{
    double distance = 0.5 * Gravity * (seconds * seconds);
    return distance;
}

//calculating velocity using the formula g * t.
double CalculateVelocity(int seconds)
{
    double velocity = Gravity * seconds;
    if (velocity > 90)
        velocity = 90;

   return velocity;
}

//converting meters to feet.
double ConvertToFeet(double meters)
{
    double feet = meters * 3.28084;
    return feet;
}
void DisplayTable(int seconds, char units)
{
    std::cout << std::endl;
    std::cout << " Seconds          Distance          Velocity" << std::endl;
    std::cout << " ===========================================" << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    for (int t = 1; t <= seconds; ++t)
    {
        double distance = CalculateFallingDistance(t);
        double velocity = CalculateVelocity(t);
        if (units == 'f')
        {
            distance = ConvertToFeet(distance);
            velocity = ConvertToFeet(velocity);
        }
        std::cout << std::setw(6) << t
            << std::setw(14) << distance << " " << (units == 'f' ? "ft" : "m")
            << std::setw(10) << velocity << " " << (units == 'f' ? "ft/s" : "m/s")
            << std::endl;
    }
}
void DisplayError(std::string message)
{
    std::cout << "Error: " << message << std::endl;
}
int main()
{
    ShowProgramInformation();

    int time = GetFallingTime();
    char units = GetUnits();

    DisplayTable(time, units);

    return 0;
}


