// Your Name
// Lab
// COSC 1436 Fall 2025
#include <iostream>

int main()
{
    // Every statement in C++ must end with a semicolon
    // statement = Anything hat does something in the language.
 //std::cout << "Hello World" << " " << "Prizma ";
    std::cout << "Hello World " << "Prizma " << std::endl;
    std::cout << "I am " << 20 << " years old" << std::endl;

    std::cout << "Hello World " << "Prizma\n";
    std::cout << "Hello World\tPrizma";
    std::cout << "Hello World \"Prizma\"";
    std::cout << "C:\\Windows";
    std::string name;
    name = "Name";
    std::cout << "Hello World " << name;
    //var-decl ::= T id;
    //type = defines whAT CAN BE STORED IN THE VARIATION AND IN WHAT FORMAT.
    int age;
    age = 20;
    std::cout << "You are " << age << " years old";
    //Area of rectangle calculator
    // A= kw
    int length;
    int width;
    //int length = 10, width = 20;  ( you can code as like this way too )
    length = 10;
    width = 20;
    // uninitialized variable  - you must assign a  value to a variable before you read it.
    int area;
    
   area = length * width;
    std::cout << " Area of rectangle is " << area << std::endl;
    // 2 different approaches to variable declarations
    // block - all variables together
    int radius, diameter;
    std::string circleName;

    //now i can use the variables
    //inline  - variables are declared just before thayare used
    //int radius, diameter;
    // use radius,diameter
    //std::string, diamter;
    //use circlename 
    double pi;
    pi = 3.14159;
    char letterGrade;
    letterGrade = 'A';

    bool ispassing;
    ispassing = true;

    length = 100;
    width = 100;
    // rather we can say length = width = 100;

        // variables are always used as noun
    //all identifier should start with the letter digits or underscore you will not need underscore n this class so dont use it.
    // | a vertical bar indicates or.
    // + means 1 or more
    // you cant have a identifier as a keywords
    // identifier must be unique no repeatation



//<< = output string operator//
//"..." = string literal// literal means read only memory
// The value 20 is integer literal
// floating point literals - one or more digits + fraction
// 3.14159 or 3E10 -3E10 3E-10  (it can besmall doesn't matter)
//std::endl  = endline//
//(preprocessor directive) # include <iostream>
//Escape sequence - special meaning to the compiler
// - starts with \ followed by a character
// \n =newline
// \t = tab
// \" = double quote
// \\ = slash
// variable - Named memory location where data is stored 
   // asn_ ::= E = E   KNOWN AS LEFT VALUE AND RIGHT VALUE 
}