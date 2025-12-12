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
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* Read an integer with validation */
int ReadInt(const char prompt[], int min = -100, int max = 100)
{
    int value;
    std::cout << prompt;
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
void ViewBeginning(Stop* trip[], int count);
void ViewMiddle(Stop* trip[], int count);
void ViewEnd(Stop* trip[], int count);
void RemoveStop(Stop* trip[], int& count);
void ClearTrip(Stop* trip[], int& count);
double CalculateDistance(Point* p1, Point* p2);



/* Add a stop */
void AddStop(Stop* trip[], int size, int& count)
{
    if (count >= size)
    {
        std::cout << "Trip is full. Cannot add more stops." << std::endl;
        return;
    }

    std::cout << "Adding new stop..." << std::endl;
    int x = ReadInt("Enter X coordinate (-100 to 100): ");
    int y = ReadInt("Enter Y coordinate (-100 to 100): ");

    Stop* newStop = new Stop;
    newStop->location = new Point;
    newStop->location->x = x;
    newStop->location->y = y;

    trip[count] = newStop;
    count++;

    std::cout << "Stop added." << std::endl;
}

/* Remove a stop */
void ViewBeginning(Stop* trip[], int count)
{
    if (count == 0)
    {
        cout << "No stops available." << std::endl;
        return;
    }

    std::cout << "Beginning Stop:" << std::endl;
    std::cout << "Stop 1: ("
        << trip[0]->location->x << ", "
        << trip[0]->location->y << ")" << std::endl;
}

/*
    Function: ViewMiddle
    Purpose: Displays the middle stop in the trip.
*/
void ViewMiddle(Stop* trip[], int count)
{
    if (count == 0)
    {
        std::cout << "No stops available." << std::endl;
        return;
    }

    int mid = count / 2;

    std::cout << "Middle Stop:" << std::endl;
    std::cout << "Stop " << (mid + 1) << ": ("
        << trip[mid]->location->x << ", "
        << trip[mid]->location->y << ")" << std::endl;
}

/*
    Function: ViewEnd
    Purpose: Displays the last stop in the trip.
*/
void ViewEnd(Stop* trip[], int count)
{
    if (count == 0)
    {
        std::cout << "No stops available." << std::endl;
        return;
    }

    std::cout << "End Stop:" << std::endl;
    std::cout << "Stop " << count << ": ("
        << trip[count - 1]->location->x << ", "
        << trip[count - 1]->location->y << ")" << std::endl;
}

/*
    Function: RemoveStop
    Purpose: Removes a stop from the trip.
*/
void RemoveStop(Stop* trip[], int& count)
{
    if (count == 0)
    {
        std::cout << "No stops to remove." << std::endl;
        return;
    }

    int index = ReadInt("Enter stop number to remove: ") - 1;

    if (index < 0 || index >= count)
    {
        std::cout << "Invalid stop number." << std::endl;
        return;
    }

    delete trip[index]->location;
    delete trip[index];

    for (int i = index; i < count - 1; i++)
        trip[i] = trip[i + 1];

    trip[count - 1] = nullptr; // Clear last element
    count--;

    std::cout << "Stop removed." << std::endl;
}

/*
    Function: ClearTrip
    Purpose: Deletes all stops and resets the count.
*/
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

/*
    Function: CalculateDistance
    Purpose: Calculates distance between two points.
*/
double CalculateDistance(Point* p1, Point* p2)
{
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

/* Display all stops with distance and travel time */
void DisplayTripDetails(Stop* trip[], int count, int speed)
{
    if (count == 0)
    {
        std::cout << "No stops available." << std::endl;
        return;
    }

    std::cout << fixed << setprecision(2);
    std::cout << "Stop       Location       Distance (miles)       Time (minutes)" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    double totalDistance = 0.0;
    double travelTime = 0.0;

    Point startPoint = {0, 0}; // starting point (0,0)

    for (int i = 0; i < count; i++)
    {
        double distance = CalculateDistance(&startPoint, trip[i]->location);
        double timeMinutes = ceil((distance / speed) * 60); // convert hours to minutes and round up

        std::cout << (i + 1) << " (" << trip[i]->location->x << "," << trip[i]->location->y << ")  "
            << distance << "   " << timeMinutes << std::endl;

        totalDistance += distance;
        travelTime += timeMinutes;

        startPoint = *trip[i]->location; // next start is current stop
    }

    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "Total     " << totalDistance << "    " << travelTime << std::endl;
}

/*MAIN*/

int main()
{
    Stop* trip[MaximumStops] = {nullptr};
    int stopCount = 0;
    char choice;
    int speed = 0;

    ShowProgramInformation();

    // Prompt for travel speed
    do
    {
        speed = ReadInt("Enter your travel speed (1-60 mph): ");
        if (speed < 1 || speed > 60)
            std::cout << "Invalid speed. Please enter a value between 1 and 60." << std::endl;
    } while (speed < 1 || speed > 60);

    do
    {
        std::cout << std::endl << "Menu: " << std::endl;
        std::cout << "A - Add Stop" << std::endl;
        std::cout << "B - View Beginning Stop" << std::endl;
        std::cout << "M - View Middle Stop" << std::endl;
        std::cout << "E - View End Stop" << std::endl;
        std::cout << "D - Display Trip Details" << std::endl; 
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
            case 'B': ViewBeginning(trip, stopCount); break;
            case 'M': ViewMiddle(trip, stopCount); break;
            case 'E': ViewEnd(trip, stopCount); break;
            case 'D': DisplayTripDetails(trip, stopCount, speed); break; 
            case 'R': RemoveStop(trip, stopCount); break;
            case 'C': ClearTrip(trip, stopCount); break;
            case 'Q':
                if (Confirm("Are you sure you want to quit? (Y/N): "))
                {
                    ClearTrip(trip, stopCount);
                    cout << std::endl << "Goodbye!" << std::endl;
                    return 0;
                }
                break;
            default:
               std::cout << "Invalid selection." << std::endl;
        }

    } while (true);

    return 0;
}