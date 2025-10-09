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
    std::cout << "Please enter the loan amount: ";
    std::cin >> loanAmount;

    while (loanAmount < 1 || loanAmount > 1000)
    {
        std::cout << "ERROR: Loan amount must be between $1 - $1000." << std::endl;
        std::cout << "Please enter the loan amount: ";
        std::cin >> loanAmount;
    }

    // prompting the user for the interest rate.
    double interestRatePercent = 0.0;
    std::cout << "Please enter the interest rate (%): ";
    std::cin >> interestRatePercent;

    while (interestRatePercent < 1.0 || interestRatePercent > 100.0)
    {
        std::cout << "ERROR: Interst rate must be between 1.0% - 100.0%." << std::endl;
        std::cout << "Please enter the interest rate (%): ";
        std::cin >> interestRatePercent;
    }
   double  interestRatePercent = interestRatePercent / 100.0;

    //

    
}


