// Lab 5
// Prizma Kunwar
// COSC 1436 - Fall 2025

#include <iostream>
#include <iomanip>
using namespace std;

void ShowProgramInformation()
{
        std::cout << "Lab 5" << std::endl;
        std::cout << "Prizma Kunwar" << std::endl;
        std::cout << "COSC 1436 - Fall 2025" << std::endl << std::endl;
}

// structure to represent stop
struct stop
{
    int x;
    int y;
};

//function to display the main menu. 
void DisplayMenu() 
{
    cout << "Main Menu" << endl;
    cout << "A - Option A" << endl;
    cout << "B - Option B" << endl;
    cout << "C - Option C" << endl;
    cout << "Q - Quit" << endl;
}

int main() 
{
    char choice;
    char confirm;

    do 
    {
        DisplayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 'A' || choice == 'a')
        {
            cout << "You selected Option A" << endl;
        } 
        else if (choice == 'B' || choice == 'b') 
        {
            cout << "You selected Option B" << endl;
        }
        else if (choice == 'C' || choice == 'c') 
        {
            cout << "You selected Option C" << endl;
        } 
        else if (choice == 'Q' || choice == 'q')
        {
            cout << "Are you sure you want to quit? (Y/N): ";
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y')
            {
                break;
            }
        } 
        else
        {
            cout << "Invalid selection. Please try again" << endl;
        }
    }
    while (true);

    cout << "Program terminated" << endl;
    return 0;
}








#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int MaximumStops = 100;
const int StringSize = 100;

/*
    Function: ClearInputBuffer
    Purpose: Clears the input buffer to handle leftover characters.
*/
void ClearInputBuffer()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

/*
    Function: ReadInt
    Purpose: Reads an integer from the user, validating input.
    Returns: A valid integer.
*/
int ReadInt(const char prompt[])
{
    int value;
    cout << prompt;

    while (!(cin >> value))
    {
        ClearInputBuffer();
        cout << "Invalid input. Please enter an integer: ";
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
    cout << prompt;
    cin.getline(outString, size);

    while (strlen(outString) == 0)
    {
        cout << "Invalid input. Please try again: ";
        cin.getline(outString, size);
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

    cout << prompt;
    cin >> choice;
    ClearInputBuffer();

    choice = ToUpper(choice);

    while (choice != 'Y' && choice != 'N')
    {
        cout << "Invalid response. Enter Y or N: ";
        cin >> choice;
        ClearInputBuffer();
        choice = ToUpper(choice);
    }

    return choice == 'Y';
}

/************** DATA STRUCTURES ****************/

struct Point
{
    int x;
    int y;
};

struct Stop
{
    Point* location;
};

/************** FUNCTION PROTOTYPES **************/

void AddStop(Stop* trip[], int size, int& count);
void ViewBeginning(Stop* trip[], int count);
void ViewMiddle(Stop* trip[], int count);
void ViewEnd(Stop* trip[], int count);
void RemoveStop(Stop* trip[], int& count);
void ClearTrip(Stop* trip[], int& count);

/************************************************/

/*
    Function: AddStop
    Purpose: Adds a new stop to the trip.
*/
void AddStop(Stop* trip[], int size, int& count)
{
    if (count >= size)
    {
        cout << "Trip is full. Cannot add more stops.\n";
        return;
    }

    cout << "Adding new stop...\n";

    int x = ReadInt("Enter X coordinate: ");
    int y = ReadInt("Enter Y coordinate: ");

    Stop* newStop = new Stop;
    newStop->location = new Point;

    newStop->location->x = x;
    newStop->location->y = y;

    trip[count] = newStop;
    count++;

    cout << "Stop added!\n";
}

/*
    Function: ViewBeginning
    Purpose: Displays the first stop in the trip.
*/
void ViewBeginning(Stop* trip[], int count)
{
    if (count == 0)
    {
        cout << "No stops available.\n";
        return;
    }

    cout << "Beginning Stop:\n";
    cout << "Stop 1: ("
        << trip[0]->location->x << ", "
        << trip[0]->location->y << ")\n";
}

/*
    Function: ViewMiddle
    Purpose: Displays the middle stop in the trip.
*/
void ViewMiddle(Stop* trip[], int count)
{
    if (count == 0)
    {
        cout << "No stops available.\n";
        return;
    }

    int mid = count / 2;

    cout << "Middle Stop:\n";
    cout << "Stop " << (mid + 1) << ": ("
        << trip[mid]->location->x << ", "
        << trip[mid]->location->y << ")\n";
}

/*
    Function: ViewEnd
    Purpose: Displays the last stop in the trip.
*/
void ViewEnd(Stop* trip[], int count)
{
    if (count == 0)
    {
        cout << "No stops available.\n";
        return;
    }

    cout << "End Stop:\n";
    cout << "Stop " << count << ": ("
        << trip[count - 1]->location->x << ", "
        << trip[count - 1]->location->y << ")\n";
}

/*
    Function: RemoveStop
    Purpose: Removes a stop from the trip.
*/
void RemoveStop(Stop* trip[], int& count)
{
    if (count == 0)
    {
        cout << "No stops to remove.\n";
        return;
    }

    int index = ReadInt("Enter stop number to remove: ");
    index--;  // convert to zero-based

    if (index < 0 || index >= count)
    {
        cout << "Invalid stop number.\n";
        return;
    }

    delete trip[index]->location;
    delete trip[index];

    for (int i = index; i < count - 1; i++)
        trip[i] = trip[i + 1];

    count--;

    cout << "Stop removed.\n";
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

    cout << "Trip cleared.\n";
}

/********************** MAIN ************************/

int main()
{
    Stop* trip[MaximumStops] = {nullptr};
    int stopCount = 0;
    char choice;

    cout << "Welcome to Trip Manager!\n";

    do
    {
        cout << "\nMenu:\n";
        cout << "A - Add Stop\n";
        cout << "B - View Beginning Stop\n";
        cout << "M - View Middle Stop\n";
        cout << "E - View End Stop\n";
        cout << "R - Remove Stop\n";
        cout << "C - Clear Trip\n";
        cout << "Q - Quit\n";
        cout << "Enter choice: ";

        cin >> choice;
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
                cout << "Invalid selection.\n";
        }

    } while (choice != 'Q');

    ClearTrip(trip, stopCount); // ensure cleanup

    cout << "\nGoodbye!\n";
    return 0;
}