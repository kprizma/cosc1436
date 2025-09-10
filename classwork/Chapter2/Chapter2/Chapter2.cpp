// Your Name
// Lab
// COSC 1436 Fall 2025
#include <iostream>
// #include replace the line with the file

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

    area = length * width;

    length = width = 100;

    //Airthmetic Operators
    // arith_op ::= + | - | /
    length = length + 10;
    width = width - 20;



    // int division ::= int / int produces an int, remainder is lost
    int result = 10 / 3; // = 3

    // modulos is remainder and only works  for integral types
     int remainder = 10 % 3;  // = 1


     int negativelength = -length;

     // scope - lifetime of a variable
     { //starting a new block 
         int newVariable1 = 10;
         double newVariable2 = 45.7;
     }

     {
         char newVariable1 = 'A';
     }

     //std::cout << newVariable1;

     // string C++
     //Assign value using assignment operator
     std::string studentName;
     studentName = "Bob";

     studentName = studentName + " Wilson";

      // literal - great for static values
     // variable -  great for writable values.
     // Named constant - variable that has a constant value.

     const double Pi = 3.14159;

     //A = Pi * R2
     double areaCircle = Pi * (radius * radius);

     //another example

     const int numberOfLabGrades = 5;
     const int numberOfExamGrades = 4;


    
    //    int/int = int (integer division )
    //     int + int = int 
    //    double * double = double
     


    // breakpoints tells the debuger to execute.
    // the yellow arrow represents the next instructions to next line.
    // //breakpoints are only for debugging.
    // local value allows you to look all the variables and value.
    // to step you can use f1
    
    // rather we can say length = width = 100;

        // variables are always used as noun
    //all identifier should start with the letter digits or underscore you will not need underscore n this class so dont use it.
    // | a vertical bar indicates or.
    // + means 1 or more
    // you cant have a identifier as a keywords
    // identifier must be unique no repeatation

    //camel casing are all lowercase, capitalise on word boundaries.



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