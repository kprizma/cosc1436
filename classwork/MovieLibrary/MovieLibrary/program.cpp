/*
* final version
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


int AddToMovieArray(Movie movies[], int size, Movie movie)
{
    //Enumerate the array looking for the first blank movie
    for (int index = 0; index < size; ++index)
    {
        if (movies[index].title == "")
        {
            //Set the array element
            movies[index] = movie;
            return index;
        }
    }

    DisplayError("No space available for new movie");
    return -1;
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
void ViewMovies(Movie movies[], int size)
{
    // enumerate movies until we run out
    for (int index = 0; index < size; ++index)
    {
        if (movies[index].title == "")
            return;
        ViewMovie(movies[index]);
    };
       
   
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

void DeleteMovie()
{
    Movie movie;
    if (!Confirm("Are you sure you want to delete" + movie.title + "?"))
        return;

    // to to: Delete movie
   // DisplayWarning("Not implemented yet");
    movie.title = "";
}

void EditMovie()
{
    DisplayWarning("Not Implemented yet");
}


void PointerDemo()
{
    // pointer to an Int, 

    int localInt = 1234;

    // pointer to an int
    int * pInt;
    pInt = &localInt;
    localInt = 9876;

    // dereferencing a pointer returns the original type T
    // dereference-op := *ptr
    *pInt = 5678;

    // An unitialized pointer points to garbage
    // iNITIALIZED POINTER TO MEMORY 0 WHICH IS INVALID
    // nULL - c version, not preferred as it is still an int
    // nullptr - preferred in C++
    //float* pFloat = NULL;
  float* pFloat = nullptr;
   // pFloat = 0;  don't do this
   // pFloat = 1234;
   
    
    // Always ensure pointer is valid (not null) before dereferencing
    // if (pFloat != nullptr)
    if (pFloat )
    {
        // this is going to crash hard if pointer is Null
        *pFloat = 123.45;
    }
  // Initializing a pointer
    // nullptr
    float localFloat = 123.45;

    // initialize a pointer to a local variable or parameter
    pFloat = &localFloat;  // addresss of localfloat, must be a variable

    *pFloat = 456.78;  // localFloat = 456.78
    
    //Inittialize a pointer to an array element
    float someFloats[10] = {0};
    pFloat = &someFloats[1];   // Ptr references second element

    //compiler error , types must exactly match
  //pFloat = pInt;  // float* = int*

    // dynamic memory
    // new-op ::=new T returns t*
    pFloat = new float;
    *pFloat = 89.76;

    for (int index = 0; index < 10000; ++index)
    {
        pFloat = new float;
        *pFloat = index;

        // deleting a pointer twice will crash or corrupt memory
        delete pFloat;
        pFloat = nullptr;

        // ensure you call delete for each pointer you allocate using new
        delete pFloat;
        pFloat = nullptr;
        // *pFloat = index; // using a deallocated pointer may crash or corrupt
    }


    // pointer assignment must exactly match the types used (no coercion)
    // pfloat = float;
    //somefloat[1] = float
    // &(Et) = T*
    // &(someFloats[1] = &(float) = float*
}


int main()
{
    PointerDemo();

    //Cannot calculate the size of an array at runtime so use a const int variable
    const int MaximumMovies = 100;
    Movie movies[MaximumMovies];

    //Display main menu
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
            case 'a': AddToMovieArray(movies, MaximumMovies, AddMovie()); break;

            case 'V':
            case 'v': ViewMovies(movies, MaximumMovies); break;

            case 'D':
            case 'd': DeleteMovie(); break;

            case 'E':
            case 'e': EditMovie(); break;

            case 'Q':
            case 'q': done = true;

            default: DisplayError("Invalid choice"); break;
        };
    } while (!done);
}




// Pointer
// pointer are 8 bytes
// pointer address memory value
// pointrs value is always a memory address. 
// memory address 0 is always invalid