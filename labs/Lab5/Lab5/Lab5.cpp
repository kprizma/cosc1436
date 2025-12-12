// Lab 5
// Prizma Kunwar
// COSC 1436 - Fall 2025



#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void ShowProgramInformation()
{
        std::cout << "Lab 5" << std::endl;
        std::cout << "Prizma Kunwar" << std::endl;
        std::cout << "COSC 1436 - Fall 2025" << std::endl << std::endl;
}

const int MaximumStops = 100;
const int StringSize = 100;

/*
    Function: ClearInputBuffer
    Purpose: Clears the input buffer to handle leftover characters.
*/
void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(1000);
}

/*
    Function: ReadInt
    Purpose: Reads an integer from the user, validating input.
    Returns: A valid integer.
*/
int ReadInt(const char prompt[])
{
    int value;
    std::cout << prompt;

    while (!(cin >> value))
    {
        ClearInputBuffer();
        std::cout << "Invalid input. Please enter an integer: ";
    }

    ClearInputBuffer();
    return value;
}

/*
    Function: ReadString
    Purpose: Reads a string from the user safely.
*/
void ReadString(const char prompt[], char outString[], int size)
{
    std::cout << prompt;
    std::cin.getline(outString, size);

    while (strlen(outString) == 0)
    {
        std::cout << "Invalid input. Please try again: ";
        std::cin.getline(outString, size);
    }
}

/*
    Function: ToUpper
    Purpose: Converts a character to uppercase.
*/
char ToUpper(char ch)
{
    return static_cast<char>(toupper(ch));
}

/*
    Function: Confirm
    Purpose: Prompts user for Yes/No confirmation.
    Returns: true if yes, false otherwise.
*/
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

/*DATA STRUCTURES */

struct Point
{
    int x;
    int y;
};

struct Stop
{
    Point* location;
};

/* FUNCTION PROTOTYPES*/

void AddStop(Stop* trip[], int size, int& count);
void ViewBeginning(Stop* trip[], int count);
void ViewMiddle(Stop* trip[], int count);
void ViewEnd(Stop* trip[], int count);
void RemoveStop(Stop* trip[], int& count);
void ClearTrip(Stop* trip[], int& count);


/*
    Function: AddStop
    Purpose: Adds a new stop to the trip.
*/
void AddStop(Stop* trip[], int size, int& count)
{
    if (count >= size)
    {
        std::cout << "Trip is full. Cannot add more stops." << std::endl;
        return;
    }

    std::cout << "Adding new stop.."  << std::endl;

    int x = ReadInt("Enter X coordinate: ");
    int y = ReadInt("Enter Y coordinate: ");

    Stop* newStop = new Stop;
    newStop->location = new Point;

    newStop->location->x = x;
    newStop->location->y = y;

    trip[count] = newStop;
    count++;

    std::cout << "Stop added" << std::endl;
}

/*
    Function: ViewBeginning
    Purpose: Displays the first stop in the trip.
*/
void ViewBeginning(Stop* trip[], int count)
{
    if (count == 0)
    {
        std::cout << "No stops available."  << std::endl;
        return;
    }

    std::cout << "Beginning Stop:" << std::endl;
    std::cout << "Stop 1: ( "
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

    int index = ReadInt("Enter stop number to remove: ");
    index;

    if (index < 0 || index >= count)
    {
        std::cout << "Invalid stop number." << std::endl;
        return;
    }

    delete trip[index]->location;
    delete trip[index];

    for (int i = index; i < count - 1; i++)
        trip[i] = trip[i + 1];

    count;

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

/*MAIN*/

int main()
{
    Stop* trip[MaximumStops] = {nullptr};
    int stopCount = 0;
    char choice;

    std::cout << "Welcome to Trip Manager" << std::endl;

    do
    {
        std::cout << std::endl << "Menu: " << std::endl;
        std::cout << "A - Add Stop" << std::endl;
        std::cout << "B - View Beginning Stop" << std::endl;
        std::cout << "M - View Middle Stop" << std::endl;
        std::cout << "E - View End Stop" << std::endl;
        std::cout << "R - Remove Stop" << std::endl;
        std::cout << "C - Clear Trip" << std::endl;
        std::cout << "Q - Quit" << std::endl;
        std::cout << "Enter choice: ";

        std::cin >> choice;
        ClearInputBuffer();
        choice = ToUpper(choice);

        switch (choice)
        {
            case 'A': AddStop(trip, MaximumStops, stopCount); break;
            case 'B': ViewBeginning(trip, stopCount); break;
            case 'M': ViewMiddle(trip, stopCount); break;
            case 'E': ViewEnd(trip, stopCount); break;
            case 'R': RemoveStop(trip, stopCount); break;
            case 'C': ClearTrip(trip, stopCount); break;
            case 'Q': break;

            default:
                std::cout << "Invalid selection." << std::endl;
        }

    } while (choice != 'Q');

    ClearTrip(trip, stopCount);

    cout << std::endl << "Goodbye" << std::endl;
    return 0;
}