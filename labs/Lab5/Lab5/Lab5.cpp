// Lab 5
// Prizma Kunwar
// COSC 1436 - Fall 2025


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

// Structs
struct Stop
{
    int x;
    int y;
};

// Utility Functions 

void DisplayError(std::string message)
{
    std::cout << "ERROR: " << message << std::endl;
}

bool Confirm(std::string message)
{
    std::cout << message << " (Y/N): ";
    std::string input;
    std::cin >> input;

    while (true)
    {
        if (_strcmpi(input.c_str(), "Y") == 0)
            return true;
        else if (_strcmpi(input.c_str(), "N") == 0)
            return false;
        else
        {
            DisplayError("Enter Y or N");
            std::cin >> input;
        }
    }
}

int ReadInt(int min, int max)
{
    while (true)
    {
        int value;
        std::cin >> value;

        if (value >= min && value <= max)
            return value;

        DisplayError("Value out of range");
    }
}

// Program Info
void DisplayProgramInfo()
{
    std::cout << "Lab 5" << std::endl;
    std::cout << "Prizma Kunwar" << std::endl;
    std::cout << "COSC 1436 - Fall 2025" << std::endl;
    std::cout << std::endl;
}


// Speed
int GetSpeed()
{
    std::cout << "Enter speed (1-60 mph): ";
    return ReadInt(1, 60);
}

// Stop Helpers
double CalculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int GetStopCount(Stop* trip[], int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (trip[i])
            ++count;
        else
            break;
    }
    return count;
}


// Add Stop
void AddStop(Stop* trip[], int size)
{
    int index = GetStopCount(trip, size);
    if (index >= size)
    {
        DisplayError("Trip is full");
        return;
    }

    Stop* stop = new Stop;

    std::cout << "Enter X (-100 to 100): ";
    stop->x = ReadInt(-100, 100);

    std::cout << "Enter Y (-100 to 100): ";
    stop->y = ReadInt(-100, 100);

    trip[index] = stop;
}

// View Trip
void ViewTrip(Stop* trip[], int size, int speed)
{
    int count = GetStopCount(trip, size);
    if (count == 0)
    {
        DisplayError("No stops in trip");
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Stop  Location    Distance (miles)   Time (minutes)" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    double totalDistance = 0;   
    int totalMinutes = 0;

    int prevX = 0, prevY = 0;

    for (int i = 0; i < count; ++i)
    {
        Stop* stop = trip[i];
        double distance = CalculateDistance(prevX, prevY, stop->x, stop->y);
        double hours = distance / speed;
        int minutes = (int)ceil(hours * 60);

        totalDistance += distance;
        totalMinutes += minutes;

        std::cout << std::setw(4) << i + 1
            << std::setw(10) << "(" << stop->x << "," << stop->y << ")"
            << std::setw(14) << distance
            << std::setw(16) << minutes << std::endl;

        prevX = stop->x;
        prevY = stop->y;
    }

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << std::setw(4) << count
        << std::setw(24) << totalDistance
        << std::setw(16) << totalMinutes << std::endl;
}


// Remove Stop
Stop* GetStopByNumber(Stop* trip[], int size, int number)
{
    int index = number - 1;
    if (index < 0 || index >= size)
        return nullptr;
    return trip[index];
}

void RemoveStop(Stop* trip[], int size)
{
    std::cout << "Enter stop number: ";
    int number = ReadInt(1, size);

    Stop* stop = GetStopByNumber(trip, size, number);
    if (!stop)
    {
        DisplayError("Stop not found");
        return;
    }

    delete stop;

    int newIndex = number - 1;
    for (int i = newIndex + 1; i < size; ++i)
    {
        trip[newIndex++] = trip[i];
        if (!trip[i])
            break;
    }

    trip[newIndex] = nullptr;
}


// Clear Trip
void ClearTrip(Stop* trip[], int size)
{
    if (!Confirm("Clear entire trip?"))
        return;

    for (int i = 0; i < size; ++i)
    {
        delete trip[i];
        trip[i] = nullptr;
    }
}


// Menu
char DisplayMenu()
{
    std::cout << std::endl;
    std::cout << "A) Add Stop" << std::endl;
    std::cout << "V) View Trip" << std::endl;
    std::cout << "R) Remove Stop" << std::endl;
    std::cout << "C) Clear Trip" << std::endl;
    std::cout << "Q) Quit" << std::endl;
    std::cout << "Choice: ";

    char choice;
    std::cin >> choice;
    return choice;
}


// Main

int main()
{
    const int MaxStops = 100;
    Stop* trip[MaxStops] = {nullptr};

    DisplayProgramInfo();
    int speed = GetSpeed();

    bool done = false;
    while (!done)
    {
        char choice = DisplayMenu();

        switch (choice)
        {
            case 'A':
            case 'a': AddStop(trip, MaxStops); break;

            case 'V':
            case 'v': ViewTrip(trip, MaxStops, speed); break;

            case 'R':
            case 'r': RemoveStop(trip, MaxStops); break;

            case 'C':
            case 'c': ClearTrip(trip, MaxStops); break;

            case 'Q':
            case 'q':
                if (Confirm("Quit program?"))
                    done = true;
                break;

            default:
                DisplayError("Invalid menu option");
        }
    }

    ClearTrip(trip, MaxStops);
    return 0;
}