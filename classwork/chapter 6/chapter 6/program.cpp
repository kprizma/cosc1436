/*
* chapter 4
*cosc 1436
*/
#include <iostream>
#include <string>
#include <iomanip>
    
// movie details
struct Movie {....};

/// <summary> view details of a movie. </summary>
/// <remarks>
/// more details including paragraphs of data if you want.
/// </remarks>


void ViewMovie()
{
    Movie movie;

    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres " << movie.genres << std::endl;
    if (movie.description != "")
        std::cout << movie.description << std::endl;
    std::cout << std::endl;
}
int main()

{
    // display main menu
    bool done = false;
    do 
    {
        std::cout << "Movie Library" << std::endl;
        std::cout << "-------------" << std::endl;
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
    case 'a': AddMovie(); break;

    case 'V':
    case 'v': ViewMovie(); break;
    

    case 'D':
    case 'd': std::cout << "Delete not implemented" << std::endl; done = true; break;

    case 'E':
    case 'e': std::cout << "Edit not implemented" << std::endl; done = true; break;

    case 'Q':
    case 'q': return 0;

    default: std::cout << "Invalid choice" << std::endl; break;
};
 } while (!done);


 Movie movie; = {0};

    std::cout << "Enter movie title: ";
    std::cin.ignore();
    std::getline(std::cin, movie.title);

    while (movie.title == "")

    {
        std::cout << "Title is required" << std::endl;
        std::getline(std::cin, movie.title);
    }

    std::cout << "Enter the run length (in minutes): ";
   
    do
    {
        std::cin >> movie.runLength;
        if (movie.runLength < 0)
        {
            std::string message = "Run length must be at least 0";
            std::cout << "ERROR: " << message << std::endl;
        }

    } while (movie.runLength < 0);


    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> movie.releaseYear;

    while (movie.releaseYear < 1900 || movie.releaseYear > 2100)
    {
        std::cout << "Release year must be between 1900 and 2100" << std::endl;
        //releaseYear = 1900;
        std::cin >> movie.releaseYear;
    }

    std::cout << "Enter the optional description: ";
    std::cin.ignore();
    std::getline(std::cin, movie.description);


    done = false;

    for (int index = 0; index < 5; ++index)
    {
        std::string genre;

        std::cout << "Enter the genre (or blank to continue): ";
        std::getline(std::cin, genre);
        if (genre == "")
           
            break;
        else if (genre == " ")
            continue;

        movie.genres = movie.genres + ", " + genre;

    }


    while (true)
    {
        if (_strcmpi(input.c_str(), "Y") == 0)
        {
            movie.isClassic = true;
            //done = true;
            break;
        } else if (_strcmpi(input.c_str(), "N") == 0)
        {
            movie.isClassic = false;
            //done = true;
            break;
        } else {
            std::cout << "You must enter either Y or N";

            std::cin >> input;
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

    void relationalDemo()
    {
        std::cout << "Enter two values: ";

        int left, right;
        std::cin >> left >> right;


        bool areEqual = left == right;
        std::cout << "areEqual = " << areEqual << std::endl;
        areEqual = left == right;
        std::cout << "areEqual = " << areEqual << std::endl;


        std::cout << "> " << (left > right) << std::endl;
        std::cout << "< " << (left < right) << std::endl;
        std::cout << ">= " << (left >= right) << std::endl;
        std::cout << "<= " << (left <= right) << std::endl;
        std::cout << "== " << (left == right) << std::endl;
        std::cout << "!= " << (left != right) << std::endl;

        float someValue = (10 / 3.0) * 3.0;
        float someOtherValue = (10 * 3.0) / 3.0;
        areEqual = someValue == someOtherValue;
        std::cout << areEqual << std::endl;

        std::string name1 = "Bob";
        std::string name2 = "bob";
        std::cout << (name1 == name2) << std::endl;

      
        areEqual = _strcmpi(name1.c_str(), name2.c_str()) == 0;
    }



  