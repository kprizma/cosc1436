// Lab 4
// Prizma Kunwar
// COSC 1436 - Fall 2025

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
void DisplayProgramInfo();
int ReadInt(string message, int minimum);
int LoadInitialValues(int values[], int capacity);
char DisplayMenu();
int GetLargest(const int values[], int count);
int GetSmallest(const int values[], int count);
int GetSum(const int values[], int count);
double GetMean(const int values[], int count);
void DisplayValues(const int values[], int count);
void InsertValues(int values[], int capacity, int& count);

//Displays program header information.
void DisplayProgramInfo()
{
    cout << "Lab 4 " << endl;
    cout << "Prizma Kunwar" << endl;
    cout << "COSC 1436 - Fall 2025" << endl << endl;
  
}

//Reads an integer value from the user that is >= minimum.
int ReadInt(string message, int minimum)
{
    int value;

    while (true)
    {
        cout << message;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(200);
            cout << "ERROR: Invalid number." << endl;
        } 
        else if (value < minimum)
        {
            cout << "You must enter a value greater than or equal to 0" << minimum << endl;
        } 
        else
        {
            return value;
        }
    }
}

//Loads the initial values into the array. Stops on 0 or when array is full.
int LoadInitialValues(int values[], int capacity)
{
    if (!values || capacity <= 0)
        return 0;

    int count = 0;

    while (count < capacity)
    {
        int value = ReadInt("Enter a value: ", 0);

        if (value == 0)
            break;

        values[count++] = value;
    }

    return count;
}

//Displaying the main menu and returns the validated choice.
char DisplayMenu()
{
    cout << endl;
    cout << "Main Menu" << endl;
    cout << "----------------" << endl;
    cout << "L) Largest" << endl;
    cout << "S) Smallest" << endl;
    cout << "U) Sum" << endl;
    cout << "M) Mean" << endl;
    cout << "I) Insert" << endl;
    cout << "V) View" << endl;
    cout << "Q) Quit" << endl;

    char choice;
    cin >> choice;
    cin.ignore();

    return toupper(choice);
}

//Getting the largest value in the array.
int GetLargest(const int values[], int count)
{
    if (!values || count <= 0)
        return 0;

    int largest = values[0];
    for (int i = 1; i < count; ++i)
    {
        if (values[i] > largest)
            largest = values[i];
    }
    return largest;
}

/// Getting the smallest value in the array.
int GetSmallest(const int values[], int count)
{
    if (!values || count <= 0)
        return 0;

    int smallest = values[0];
    for (int i = 1; i < count; ++i)
    {
        if (values[i] < smallest)
            smallest = values[i];
    }
    return smallest;
}

/// Computing the sum of all values in the array.
int GetSum(const int values[], int count)
{
    if (!values || count <= 0)
        return 0;

    int sum = 0;
    for (int i = 0; i < count; ++i)
        sum += values[i];
    return sum;
}

/// Computing the mean (average) of the values in the array.
double GetMean(const int values[], int count)
{
    if (!values || count <= 0)
        return 0.0;

    return static_cast<double>(GetSum(values, count)) / count;
}

/// Displaying the values in the array, printing 10 values per line.
void DisplayValues(const int values[], int count)
{
    if (!values || count <= 0)
    {
        cout << "No values to display." << endl;
        return;
    }

    cout << endl;

    for (int i = 0; i < count; ++i)
    {
        cout << setw(6) << values[i];

        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}

/// Allowing the user to insert more values without overwriting existing ones.
void InsertValues(int values[], int capacity, int& count)
{
    if (!values || capacity <= 0)
        return;

    while (count < capacity)
    {
        int value = ReadInt("Enter a value: ", 0);

        if (value == 0)
            return;

        values[count++] = value;
    }

    cout << "Array is full – cannot add more values." << endl;
}

/// Main program entry point.
int main()
{
    const int MaxValues = 100;
    int values[MaxValues] = {0};
    int count = 0;

    DisplayProgramInfo();

    // Story 2 - Get initial values
    count = LoadInitialValues(values, MaxValues);

    bool done = false;

    while (!done)
    {
        char choice = DisplayMenu();

        switch (choice)
        {
            case 'I': InsertValues(values, MaxValues, count); break;

            case 'L':
                if (count == 0)
                    cout << "No values entered." << endl;
                else
                    cout << "Largest = " << GetLargest(values, count) << endl;
                break;

            case 'S':
                if (count == 0)
                    cout << "No values entered." << endl;
                else
                    cout << "Smallest = " << GetSmallest(values, count) << endl;
                break;

            case 'U':
                if (count == 0)
                    cout << "No values entered." << endl;
                else
                    cout << "Sum = " << GetSum(values, count) << endl;
                break;

            case 'M':
                if (count == 0)
                    cout << "No values entered." << endl;
                else
                {
                    cout << fixed << setprecision(4);
                    cout << "Mean = " << GetMean(values, count) << endl;
                }
                break;

            case 'V': DisplayValues(values, count); break;

            case 'Q': done = true; break;

            default: cout << "ERROR: Invalid option." << endl; break;
        }
    }

    return 0;
}
