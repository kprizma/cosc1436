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
    DisplayWarning("Not Implemented yet");
}
void Display(int value)
{
    std::cout << "int" << std::endl;
}
void Display(double value)
{
    std::cout << "double" << std::endl;
}
void Display(float value)
{
    std::cout << "float" << std::endl;
}
void Display(short value1, double value2)
{
    std::cout << "int, double" << std::endl;
}

void Display(short value, float)
{
    std::cout << "short, float" << std::endl;
}
void Display(int, short)
{
    std::cout << "int, short" << std::endl;
}
void Dispplay(short, int)
{
    std::cout << "int, short" << std::endl;
}
/*void TestFunctionOverloading()
{
    Display(10); //Display(int)
    Display(4.56); //Display(double)
    Display((short)34);   // Display(int = shortest type coercion
    Display(10, 4.56F); // Display (int, double)

    long lValue = 10000L;
    Display(lValue, 4.56);

    Display('c' , 4.56F);
    Display((short)5, (short)10);
    
}*/
int Factorial(int value)
{
    if (value <= 1)
        return 1;
    return value * Factorial(value - 1);
}
void ArrayDemo()
{
    const int MaxNumbers = 100;
    int numbers[MaxNumbers] = {0};

   // int daysInMonth[12] = {31, 28, 31, 30, 31, 31, 30, 31, 30, 31};

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31};

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    
    // approach 2 for any array
    //for (int index = 0; index < MaxNumbers; ++index)
       // numbers[index] = index + 1;

    int rangeIndex = 0;
    for (int number: numbers)
        number = ++rangeIndex;

    
    for (int index = 0; index < MaxNumbers; ++index)
        std::cout << numbers[index] << std::endl;

    // prefix/ postfix and arrays
    // ++x := x = x+1; ret x
    // x++ := temp = x; x = x+1; ret temp
    int outIndex = 0;
    std::cout << ++numbers[outIndex] << std::endl;  /// modifies ++numbers[0], numbers[0] = 2, prints 2
    std::cout << numbers[outIndex]++ << std::endl; /// modifies element, numbers[0]++, numbers[0] = 3, prints 2
    std::cout << numbers[++outIndex] << std::endl; // modifies index, numbers[++0], outIndex = 1;
                                                    // numbers[1], prints 2 
    std::cout << numbers[outIndex++] << std::endl;   // modifies index, numbers  [1++] , outIndex = 2
                                                    // numbers[1] , prints 2

    // arrays
    // access elememts
    // can't
    int numbers3[MaxNumbers] = {0};
    bool areArraysEqual = numbers == numbers3;
    std::cout << numbers;
    //std::cin >> numbers;
}

int main()
{
    ArrayDemo();
    // cannot calculate the size of an array at runtime so use a const int variable
     const int  MaximumMovies = 100;
    

    // TO DO; Leaving this for now to avoid breakign code
    
    Movie movie;
    Movie movies[MaximumMovies];
    Movie firstElement = movies[0];

    //display main menu
    bool done = false;
    do
    {
        std::cout << "Movie Library" << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "V)iew Movie" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;

        char choice;
        std::cin >> choice;

       

        switch (choice)
        {
            case 'A':
            case 'a':movies[0] = AddMovie(); break;

            case 'V':
            case 'v': ViewMovies(movies, MaximumMovies); break;

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


// an element is a singular value stored in an array.
// an arrya is an list of values of same type
// c++ doesnot allow you to dislay arrray without size.
// 1. size is required at decimal
// 2. size > 0
// 3. size must be const/int expression known  at compile time