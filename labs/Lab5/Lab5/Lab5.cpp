// Lab 5
// Prizma Kunwar
// COSC 1436 - Fall 2025

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

void ShowProgramInformation()
{
    cout << "Lab 5" << endl;
    cout << "Prizma Kunwar" << endl;
    cout << "COSC 1436 - Fall 2025" << endl << endl;
}

const int MaximumStops = 100;

/* Clear input buffer */
void ClearInputBuffer()
{
    cin.clear();
    cin.ignore(100);
}

/* Read an integer with validation */
int ReadInt(const char prompt[], int min = -100, int max = 100)
{
    int value;
    cout << prompt;
    while (!(cin >> value) || value < min || value > max)
    {
        ClearInputBuffer();
        std::cout << "Invalid input. Enter an integer";
        if (min != -100 || max != 100)
            cout << " between " << min << " and " << max;
        cout << ": ";
    }
    ClearInputBuffer();
    return value;
}

/* Convert character to uppercase */
char ToUpper(char ch)
{
    return static_cast<char>(toupper(ch));
}

/* Confirm Y/N */
bool Confirm(const char prompt[])
{
    char choice;
    std::cout << prompt;
    std::cin >> choice;
    ClearInputBuffer();
    choice = ToUpper(choice);
    while (choice != 'Y' && choice != 'N')
    {
        std::cout << "Invalid response. Enter Y or N: ";
        std::cin >> choice;
        ClearInputBuffer();
        choice = ToUpper(choice);
    }
    return choice == 'Y';
}

/* DATA STRUCTURES */
struct Point
{
    int x;
    int y;
};

struct Stop
{
    Point* location;
};

/* FUNCTION PROTOTYPES */
void AddStop(Stop* trip[], int size, int& count);
void RemoveStop(Stop* trip[], int& count);
void ClearTrip(Stop* trip[], int& count);
double CalculateDistance(Point* a, Point* b);
void ViewTrip(Stop* trip[], int count, int speed);

/* Add a stop */
void AddStop(Stop* trip[], int size, int& count)
{
    if (count >= size)
    {
        std::cout << "Trip is full. Cannot add more stops." << std::endl;
        return;
    }

    std::cout << "Adding new stop..." << std::endl;
    int x = ReadInt("Enter X coordinate (-100 to 100): ", -100, 100);
    int y = ReadInt("Enter Y coordinate (-100 to 100): ", -100, 100);

    Stop* newStop = new Stop;
    newStop->location = new Point;
    newStop->location->x = x;
    newStop->location->y = y;

    trip[count] = newStop;
    count++;

    std::cout << "Stop added." << std::endl;
}

/* Remove a stop */
void RemoveStop(Stop* trip[], int& count)
{
    if (count == 0)
    {
        std::cout << "No stops to remove." << std::endl;
        return;
    }

    int stopNum = ReadInt("Enter stop number to remove: ", 1, count);
    int index = stopNum - 1;

    delete trip[index]->location;
    delete trip[index];

    for (int i = index; i < count - 1; i++)
        trip[i] = trip[i + 1];

    trip[count - 1] = nullptr;
    count;

    std::cout << "Stop removed." << std::endl;
}

/* Clear all stops */
void ClearTrip(Stop* trip[], int& count)
{
    if (!Confirm("Are you sure you want to clear the trip? (Y/N): "))
        return;

    for (int i = 0; i < count; i++)
    {
        delete trip[i]->location;
        delete trip[i];
        trip[i] = nullptr;
    }
    count = 0;
    std::cout << "Trip cleared." << std::endl;
}

/* Calculate distance between two points */
double CalculateDistance(Point* a, Point* b)
{
    double dx = static_cast<double>(b->x - a->x);
    double dy = static_cast<double>(b->y - a->y);
    return sqrt(dx * dx + dy * dy);
}

/* View all stops with distance and travel time */
void ViewTrip(Stop* trip[], int count, int speed)
{
    if (count == 0)
    {
        std::cout << "No stops available." << std::endl;
        return;
    }

    std::cout << fixed << setprecision(2);
    std::cout << std::endl << "Stop          Location          Distance (miles)          Time (minutes)" << std::endl;
    std::cout <<              "-------------------------------------------------------------------------" << std::endl;

    Point startPoint = {0, 0};
    double totalDistance = 0;
    double totalTime = 0;

    for (int i = 0; i < count; i++)
    {
        double dist = CalculateDistance(&startPoint, trip[i]->location);
        double time = ceil((dist / speed) * 60);

        std::cout << setw(2) << (i + 1) << " ("
            << trip[i]->location->x << ","
            << trip[i]->location->y << ")"
            << setw(10) << dist << " "
            << setw(13) << time << std::endl;

        totalDistance += dist;
        totalTime += time;
        startPoint = *trip[i]->location;
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "Total     " << setw(10) << totalDistance << "     " << setw(13) << totalTime << endl;
}

/* MAIN */
int main()
{
    Stop* trip[MaximumStops] = {nullptr};
    int stopCount = 0;
    char choice;

    ShowProgramInformation();

    // Prompt for speed
    int speed = ReadInt("Enter your travel speed (1-60 mph): ", 1, 60);

    do
    {
        std::cout << std::endl << "Menu: " << std::endl;
        std::cout << "A - Add Stop" << std::endl;
        std::cout << "V - View Trip" << std::endl;
        std::cout << "R - Remove Stop" << std::endl;
        std::cout << "C - Clear Trip" << std::endl;
        std::cout << "Q - Quit" << std::endl;
        std::cout << "Enter choice: " << std::endl;

        std::cin >> choice;
        ClearInputBuffer();
        choice = ToUpper(choice);

        switch (choice)
        {
            case 'A': AddStop(trip, MaximumStops, stopCount); break;
            case 'V': ViewTrip(trip, stopCount, speed); break;
            case 'R': RemoveStop(trip, stopCount); break;
            case 'C': ClearTrip(trip, stopCount); break;
            case 'Q':
                if (Confirm("Are you sure you want to quit? (Y/N): "))
                {
                    ClearTrip(trip, stopCount);
                    std::cout << "Goodbye!" << endl;
                    return 0;
                }
                break;
            default:
                std::cout << "Invalid selection." << endl;
        }

    } while (true);

    return 0;
}