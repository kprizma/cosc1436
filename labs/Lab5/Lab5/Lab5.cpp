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








