/*
* chapter 4
*cosc 1436
*/
#include <iostream>
#include <string>
#include <iomanip>
  
// movie details
struct Movie
{
    std::string title;          //Required
    std::string description;    //Optional
    int runLength;              //Required, 0
    int releaseYear;            //Optional, but between 1900-2100
    bool isClassic;             //Required, false
    std::string genres;         //Optional (comma separated list of genres)
};


/// <summary>Defines possible foreground colors.</summary>
enum class ForegroundColor {
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Cyan = 36,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightCyan = 96
};

// function prototypes
// forward declarations/ referencing
void DisplayError(std::string);


void ResetTextColor()
{
    std::cout << "\033[0m";
}



void SetTextColor (ForegroundColor color)
{
    std::cout << "\033[" << (int)color << "m";
}

bool Confirm ( std::string message)
    {
    std::cout << message << "(Y/N)";
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
            DisplayError("You must enter either Y or N");

            std::cin >> input;
         }
    }
 }

// <summary> displays an error message. </summary>
// <param name = "message"> message to display. </param>
void DisplayError(std::string message)
{
    
  //  std::cout << "\033[91m"
    SetTextColor(ForegroundColor::BrightRed);
    std::cout << "Error: " << message << std::endl;
    ResetTextColor();
}
// <summary> displays an error message. </summary>
// <param name = "message"> message to display. </param>
void DisplayWarning(std::string message)
{
    SetTextColor(ForegroundColor::BrightYellow);
    std::cout << message << std::endl;
    ResetTextColor();
}


int ReadInt( int minimumValue, int maximumValue)
{
    
    do
    {
        int value;
        std::cin >> value;

        
        if (value >= minimumValue && value <= maximumValue)
            return value;

        DisplayError("Value too small");


    } while (true);
}

int ReadInt(int minimumValue)
{
    return ReadInt(minimumValue, INT_MAX);

}

std::string ReadString(std::string message, bool isRequired)
{
    
    std::cout << message;

    std::string input;
    std::getline(std::cin, input);

    
    while (isRequired && input == "")
    {
        DisplayError(" Value is required ");

        std::getline(std::cin, input);
    }
    return input;
}
/// <summary> view details of a movie. </summary>
/// <remarks>
/// more details including paragraphs of data if you want.
/// </remarks>




// function is a forms of task which is reusable block of code.    reusability , maintainability , performance , encupsulation


void ViewMovie(Movie movie)
{
    if (movie.title == "")
    {
        DisplayWarning("No movies exists");
        return;
    }

    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres " << movie.genres << std::endl;
    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    if (movie.description != "")
        std::cout << movie.description << std::endl;
    std::cout << std::endl;
}

Movie AddMovie()
{
    Movie movie;// = {0};

    //Get movie details

    movie.title = ReadString("Enter movie title: ", true);
    std::cout << "Enter the run length (in minutes): ";
   
    movie.runLength = ReadInt(0);

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> movie.releaseYear;
    movie.releaseYear = ReadInt(1900, 2100);

    movie.description = ReadString("Enter the optional description: ", false);


    // Genres, up to 5
    for (int index = 0; index < 5; ++index)
    {
        std::string genre = ReadString("Enter the genre (or blank to continue): ", false);

        
        if (genre == "")
            break;
        else if (genre == " ")
            continue;

        movie.genres = movie.genres + ", " + genre;

    }
    movie.isClassic = Confirm("Is this a classic movie?");
    return movie;

}

void DeleteMovie(Movie& movie)
{
    if (!Confirm("Are you sure you want to delete" + movie.title + "?"))
        return;

    // to to: Delete movie
   // DisplayWarning("Not implemented yet");
    movie.title = "";
}

void EditMovie(Movie& movie)
{
    DisplayWarning("Not implemented yet");
}

int main()
{
    //Display main menu
    Movie movie;
    bool done = false;
    do
    {
        std::cout << "Movie Library" << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "V)iew Movies" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;

        char choice;
        std::cin >> choice;

       

        switch (choice)
        {
            case 'A':
            case 'a':movie = AddMovie(); break;

            case 'V':
            case 'v': ViewMovie(movie); break;

            case 'D':
            case 'd': DeleteMovie( movie); break;

            case 'E':
            case 'e': EditMovie(movie); break;

            case 'Q':
            case 'q': done = true;

            default: DisplayError("Invalid choice"); break;
        };
    } while (!done);

    //std::cin.ignore();
    //function call ::= func()
    // viewMovie();
}


  // parameter kind   (parameter is only available inside the function.)
//1. input / pass by value (T id)
// 2. inout output / pass by reference  (T & id)
// 3. output / return type

// output Parameter(provide the storage for the parameter but not the value.they are designed to get out the data value.)