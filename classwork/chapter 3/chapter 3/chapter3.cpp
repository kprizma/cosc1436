#include <iostream>
#include <string>
void main()
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



    
}