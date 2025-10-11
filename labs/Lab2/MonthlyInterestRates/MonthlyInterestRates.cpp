// Lab 1
// Prizma Kunwar
// COSC 1436 - Fall 2025

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

void main()
{
    std::cout << "Lab 2" << std::endl;
    std::cout << "Prizma Kunwar" << std::endl;
    std::cout << "COSC 1436 - Fall 2025" << std::endl << std::endl;

    // prompting the user for the initial loan.
    int loanAmount = 0;
    std::cout << "Please enter the loan amount ($1 - $1000): ";
    std::cin >> loanAmount;

    while (loanAmount < 1 || loanAmount > 1000)
    {
        std::cout << "That is an invalid value." << std::endl;
        std::cout << "Please enter the loan amount ($1 - $1000): ";
        std::cin >> loanAmount;
    }

    // prompting the user for the interest rate.
    double interestRate = 0.0;
    std::cout << "Please enter the interest rate (1.0% - 100.0%): ";
    std::cin >> interestRate;

    while (interestRate < 1.0 || interestRate > 100.0)
    {
        std::cout << "That is an invalid value." << std::endl;
        std::cout << "Please enter the interest rate (1.0% - 100.0%): ";
        std::cin >> interestRate ;
    }
   double nterestRate = interestRate / 100.0;

    //prompting for payment amount
   double monthlyPayment = 0.0;
   std::cout << " How much do you want to pay each month?" ;
   std::cin >> monthlyPayment;
   
   while (monthlyPayment < 0 || monthlyPayment > loanAmount)
   {
       std::cout << " This is an invalid value. " << std::endl;
       std::cout << " How much do you want to pay each month? ";
       std::cin >> monthlyPayment;
   }

    
}


