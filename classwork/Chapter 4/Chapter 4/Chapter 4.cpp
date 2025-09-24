/*
* chapter 4
*cosc 1436
*/
#include <iostream>
#include <string>

int main()
{
    // Movie Details
    std::string title;            //Required
    std::string description;       // optional
    int runLength;                 // required
    int releaseYear;               // optional , but between 1900 - 2100
    double userRating;              // optional, 1.0 - 10.0
    bool isClassic;                   // Required, false

    // get movie details
    std::cout << "Enter movie title: ";
    std::getline(std::cin, title);

    //TITLE IS REQUIRED
    bool isEmpty = title == "";
    if (isEmpty) 
           std::cout << "Title is required" << std::endl;

    std::cout << "Enter the run length (in minute): ";
    std::cin >> runLength;
    if (runLength < 0);
    {

        std::cout << "Run length must be at least 0" << std::endl;
        runLength = 0;
    };

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> releaseYear;
    
    if (releaseYear < 1900)
    {
        std::cout << " Release year must be at least 1900" << std::endl;
        releaseYear = 1900;

    } else if (releaseYear > 2100)
    {
        std::cout << " Release year must be between 1900 and 2100" << std::endl;
        releaseYear = 1900; 
    }
      if (releaseYear < 1900 )
    std::cout << "Enter the optional description: ";
    std::getline(std::cin, description);

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

    if (_strcmpi(input.c_str(), "Y") == 0)
    isClassic = true;
    if (_strcmpi(input.c_str(), "N") == 0)
    isClassic = false;
    else
        std::cout << "You must enter either Y or N";

    //TODO: HANDLE OTHER VALUES

  }


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