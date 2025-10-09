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
    // Movie Details
    std::string title;            //Required
    std::string description;       // optional
    int runLength;                 // required
    int releaseYear;               // optional , but between 1900 - 2100
 // double userRating;              // optional, 1.0 - 10.0
    bool isClassic;                   // Required, false
    std::string genres               // optional ( comma separated list of genres)

};

int main()

{
    // Demo prefix/ postfix-increment/ decrement
  
    // demo nested loop 10*12 = 120
    //     1 2 3 4 5 
    //   1 1 2 3 4 5
    //   2 2 4 6 8 10
    //   3 3 6 9 12 15

 /* for (int rows = 1; rows <= 12; ++rows)
    {
        
        for (int cols = 1; cols <=10; ++cols)
        {
            if (cols != 0)
                std::cout << std::setw(4) << (rows * cols);
            else
                std::cout << cols;
        }

        std::cout << std::endl;
       
    }
    */



    bool done = false;
    do //while (!done)
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

        switch (choice) { ... }
    } while (!done);
    
     
    // int id;
    Movie movie = {0};


 


    
    // get movie details
    std::cout << "Enter movie title: ";
    std::cin.ignore();
    std::getline(std::cin, movie.title);

    //...
    while (movie.title == "")

    {
        std::cout << "Title is required" << std::endl;
        std::getline(std::cin, movie.title);
    }

    std::cout << "Enter the run length (in minutes): ";
    /*runLength = -1;
    while (runLength < 0);
    {
        std::cin >> runLength;
        if (runLength < 0);
        std::cout << "ERROR: Run length must be at least 0" << std::endl;
        
    }*/

    std::cin >> runLength;
    while (runLength < 0)
    {
        //Error
        std::string message = "Run length must be at least 0";
        std::cout << "ERROR: " << message << std::endl;
        std::cin >> runLength;

    }

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> movie.releaseYear;

    if (releaseYear < 1900 || releaseYear > 2100)
    {
        std::cout << " Release year must be at least 1900" << std::endl;
        releaseYear = 1900;

    } else if (releaseYear > 2100)
    {
        std::cout << " Release year must be between 1900 and 2100" << std::endl;
        releaseYear = 1900;
    }
    if (releaseYear < 1900)
        std::cout << "Enter the optional description: ";
    std::getline(std::cin, description);


    // validate 
    std::cout << "Enter the optional user rating (1.0-10.0): ";
    std::cin >> userRating;
    if (userRating < 1.0 || userRating > 10.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0 " << std::endl;
        userRating = 1.0;
    }
    /*
if (userRating < 1.0)
{
    std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
    userRating= 1.0;
    */
 /*
} else if (userRating > 10.0)
{

}
*/

    std::cout << "Is this a classic (Y/N)? ";
    std::string input;
    std::cin >> input;

    // if (Eb) S (else S)
    /*if (_strcmpi(input.c_str(), "Y") == 0)
    isClassic = true;
    if (_strcmpi(input.c_str(), "N") == 0)
        isClassic = false;
    else
        std::cout << "You must enter either Y or N"; */




    isClassic = false;
    if (_strcmpi(input.c_str(), "Y") == 0)
        isClassic = true;
    if (_strcmpi(input.c_str(), "N") == 0)
        isClassic = false;
    else
        std::cout << "You must enter either Y or N";


    //view movie
    //title (year)
    //run length (min)
    // user rating = ##
    // is classic?
  //  description
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << title << " (" << releaseYear << ")" << std::endl;
    std::cout << "Run Length " << runLength << "mins" << std::endl;
    std::cout << "User Rating = " << userRating << std::endl;
   // if (isClassic)
   //     std::cout << "Is Classic? Yes" << std::endl;
  //  else
    //    std::cout << "Is Classic? No" << std::endl;


/* std::string classindicator;
* if (isclasssic)
* classindicator = yes;
* else
* classindicator = no;
* //conditional_expression::= Eb ? et : ef
*/

   // std::string classicIndicator;
    //if (isClassic)
    //    classicIndicator = "Yes";
   // else
    //    classicIndicator = "No";
   // std::cout << "Is Classic?" << classicIndicator << std::endl;



    std::cout << "Is Classic? " << (isClassic ? "Yes" : "No") << std::endl;
    if (description != "")
        std::cout << description << std::endl;
    std::cout << std::endl;
}




    //TODO: HANDLE OTHER VALUES




void relationalDemo()
{
    std::cout << "Enter two values: ";

    int left, right;
    std::cin >> left >> right;

    // Relational Operators ::= > >= < <= == !=
    // Warning1  - equality and equals are similar and work in the same situations
    // warning2- be very very careful of floatin point comparision for equality
    //    consider using >= or <= instead unless comparing to an integer
    // warning 3 - strings compare by character values not by locale

    bool areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;
    areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;

   // areEqual = 10 == left;
   // areEqual = 10 = left;


    
    std::cout << "> " << (left > right) << std::endl;
    std::cout << "< " << (left < right) << std::endl;
    std::cout << ">= " << (left >= right) << std::endl;
    std::cout << "<= " << (left <= right) << std::endl;
    std::cout << "== " << (left == right) << std::endl;
    std::cout << "!= " << (left != right) << std::endl;

    // output shows (1 for true and 0 for false)
    //always put literal on left side

    float someValue = (10 / 3.0) * 3.0;
    float someOthervalue = (10 * 3.0) / 3.0;
    areEqual = someValue == someOthervalue;
    std::cout << areEqual << std::endl;

    //comparison works but is case sensitive
    std::string name1 = "Bob";
    std::string name2 = "bob";
    std::cout << (name1 == name2) << std::endl;

    // to compare strings case insensitive use the strcmpi
    // > 0 ::= left > right
    // < 0 ::= left< right
    // == 0 ::= left == right

    areEqual = _strcmpi(name1.c_str(), name2.c_str()) == 0;


}