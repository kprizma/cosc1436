#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>


void main()
{

    //Get values for x and y
    std::cout << "Enter values for X and Y: ";

    int x, y;
    std::cin >> x >> y;
     
    // function x y result
    // -------
    // 
    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::setw(9) << "Function" << std::setw(7) << "X" << std::setw(7) << "Y" << std::setw(12) << " Result" << std::endl;
    std::cout << std::setw(35) << std::setfill('-') << "" << std::endl;

    std::cout << "pow" << x << y << pow(x, y) << std::endl;
    std::cout << "sqrt" << x << y << sqrt(x) << std::endl;

    std::cout << "ceil" << x << y << ceil(x) << std::endl;
    std::cout << "floor" << x << y << floor(x) << std::endl;

    std::cout << "round" << x << y << round(x) << std::endl;
    std::cout << "trunc" << x << y << trunc(x) << std::endl;






}
void ExpressionDemo()

{
    // prompt user for radius of circle
    std::cout << "Enter radius: ";

    // cin is used to get input from user
    // use the input stream operator >> before the variable names 
    int radius = 0;
    std::cin >> radius;

    const double Pi = 3.14159;

    // Area = Pi * R^2
    // double * int * int = double
    double area = Pi * radius * radius;
    std::cout << "Area = " << Pi << " * " << radius << " * " << radius << std::endl;
    std::cout << " Area = " << area << std::endl;


    //Traiangle
    std::cout << "Enter base and height of triangle: ";

    int base = 0, height = 0;
  //std::cin >> base;
  //std::cin >> height;
    std::cin >> base >> height;


    // area = 1/2 * base * height
    // (int / int) * int * int
    area = (1.0 / 2) * base * height;
    std::cout << "Area = " << area << std::endl;


    std::cout << "Enter name: ";

    std::string name;
  //std::cin >> name;
    std::cin.ignore(); //it helps to refresh the ignore
    std::getline(std::cin, name);  //getline is used to read strings with spaces in them
    std::cout << name << std::endl;

    //overflow and underflow
    short smallValue = 32767;
    smallValue = smallValue + 1;

    short largeValue = -32768;
    largeValue = largeValue - 1;

   
    std::cout << smallValue << " " << largeValue << std::endl;

    //type coercion - compiler implicity converts an expression's type to a larger type
    // type casting - you explicitly convert an expression's type to another type
      //

    int left = 10;
    int right = 3;

    double intDivision = 10 / 3; // int
    intDivision = 10.0 / 3; // double / int = double
    intDivision = 10 / 3.0;

    intDivision = left / right; //int / int = int

    intDivision = (double)left / right; //double / int = double
    intDivision = left / (double)right; //int / double

    intDivision = (double)(left / right); // int/int = int = (double)int

    intDivision = static_cast<double>(left) / right; // double / int = double
    intDivision = left / static_cast<double>(right);  //int / double = double
    

   //this is wrong and will not produce 5
    intDivision = (int)"5";
   //ntDivision = static_cast<int>("5");//compiler error




    //math functions
    // pow(x,y) = power x to the y power
    //sqrt(x) = square root of x
    //abs(x) = absolute value of x
    //ceil(x) = smallest possible integral value = x
    // floor(x) = largest possible integral value = x
    // round(x) = rounds a float to an int using midpoint rounding
    // trunc (x) = truncates a float to an int
    //exp (x) = EXPONENTIAL E raises to X power, E = 2.17828
    // log(x) = logarithm, inverse of exp

    double result;
    result = pow(5, 3);  // 5 * 5 * 5 = 125
    result = pow(125, -3); // cube root of 125

    result = sqrt(100); // 10
    result = sqrt(pow(5, 2)); //5

    result = abs(-10); //10
    result = abs(10);  //10

    result = ceil(14.5);  //15
    result = floor(3.1);  //3

    result = round(14.5);  //15
    result = round(3.1);    //3

    result = trunc(14.5);  //14
    result = trunc(3.1);   //3
    result = (int)14.5;

    result = exp(4);
    result = log(exp(4));  //4

    
}