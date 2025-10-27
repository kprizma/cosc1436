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
}

//creating the falling distance function
double CalculateFallingDistance(int time)
{
    double distance = 0.5 * Gravity * (time * time);
    return distance;
}



