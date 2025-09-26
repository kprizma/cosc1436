// Lab 1
// Prizma Kunwar
// COSC 1436 - Fall 2025

#include <iostream>
#include <string>
#include <iomanip>
void main()
{
    std::cout << "Lab 1 " << std::endl;
    std::cout << "Prizma Kunwar" << std::endl;
    std::cout << "COSC 1436 - Fall 2025" << std::endl << std::endl;

    // prompting user for their name.
    std::string name;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);
   

    // prompting user for 4 lab gardes.
    int lab1, lab2, lab3, lab4;
    std::cout << "Please enter lab 1: ";
    std::cin >> lab1;

    std::cout << "Please enter lab 2: ";
    std::cin >> lab2;

    std::cout << "Please enter lab 3: ";
    std::cin >> lab3;

    std::cout << "Please enter lab 4: ";
    std::cin >> lab4;

    // prompting user for 3 exam garde.
    int exam1, exam2, exam3;
    std::cout << "Please enter exam 1: ";
    std::cin >> exam1;

    std::cout << "Please enter exam 2: ";
    std::cin >> exam2;

    std::cout << "Please enter exam 3: ";
    std::cin >> exam3;

    int participation, finalexam;
    std::cout << "Please enter participation: ";
    std::cin >> participation;

    std::cout << "Please enter Final exam: ";
    std::cin >> finalexam;

    // calculating lab and exam average.
    double labAverage = (lab1 + lab2 + lab3 + lab4) / 4.0;
    double examAverage = (exam1 + exam2 + exam3) / 3.0;
    double classAverage = (labAverage * 0.65) + (examAverage * 0.20) + (participation * 0.05) + (finalexam * 0.10);


   //set decimal formatting
    std::cout << std::fixed << std::setprecision(2) << std::endl; 



    // displaying lab grades.
    std::cout <<  name << ", your lab grades are: " << std::endl;
    std::cout << " lab1 = " << lab1 << std::endl;
    std::cout << " lab2 = " << lab2 << std::endl;
    std::cout << " lab3 = " << lab3 << std::endl;
    std::cout << " lab4 = " << lab4 << std::endl << std::endl;
   



    // displaying exam grades.
    std::cout << name << ", your exam grade are: " << std::endl;
    std::cout << " exam1 = " << exam1 << std::endl;
    std::cout << " exam2 = " << exam2 << std::endl;
    std::cout << " exam3 = " << exam3 << std::endl << std::endl;
    
    // diaplaying other grades.
    std::cout << name << ", your other grades are: " << std::endl;
    std::cout << "Participation = " << participation << std::endl;
    std::cout << "Final Exam = " << finalexam << std::endl << std::endl;



    // calculating and displaying the class average.
    std::cout << name << ", your class grade is: " << std::endl;
    std::cout << " Lab Average (65%) = " << labAverage << " %" << std::endl;
    std::cout << " Exam Average (20%) = " << examAverage << " %" << std::endl;
    std::cout << " Participation (5%) = " << participation << " %" << std::endl;
    std::cout << " Final Exam (10%) = " << finalexam << " %" << std::endl;
    std::cout << " Class Average = " << classAverage << " %" << std::endl;






} 

