// Lab 1
// Prizma Kunwar
// COSC 1436 - Fall 2025

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int main()
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
        std::cout << "That is an invalid value." << std::endl;
        std::cout << "Please enter the loan amount ($1 - $1000): ";
        std::cin >> loanAmount;
    }

    // prompting the user for the interest rate.
    double interestRate = 0.0;
    std::cout << "Please enter the interest rate (%): ";
    std::cin >> interestRate;

    while (interestRate < 1.0 || interestRate > 100.0)
    {
        std::cout << "That is an invalid value." << std::endl;
        std::cout << "Please enter the interest rate (1.0% - 100.0%): ";
        std::cin >> interestRate;
    }
    double interestRateDecimal = interestRate / 100.0;

     //prompting for payment amount
    double monthlyPayment = 0.0;
    std::cout << " How much do you want to pay each month? ";
    std::cin >> monthlyPayment;

    while (monthlyPayment <= 0 || monthlyPayment > loanAmount)
    {
        std::cout << " This is an invalid value. " << std::endl;
        std::cout << " How much do you want to pay each month? ";
        std::cin >> monthlyPayment;

    }

    // displaying monthly table 
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl;
    std::cout << "Month  "
        << std::setw(12) << "Balance"
        << std::setw(15) << "Payment"
        << std::setw(15) << "Interest"
        << std::setw(15) << "            New Balance" << std::endl;

    std::cout << std::string(70, '-') << std::endl;

    //initializing variables
    double balance = loanAmount;
    double interest = 0.0;
    double totalPayments = 0.0;
    double totalInterest = 0.0;

    for (int month = 1; month <= 12; month++)
    {
        if (month == 1)
        {
            std::cout << std::setw(2) << month
                << std::setw(8) << "$" << std::setw(7) << balance
                << std::setw(10) << "$" << std::setw(7) << 0.00
                << std::setw(10) << "$" << std::setw(7) << 0.00
                << std::setw(10) << "$" << std::setw(7) << balance
                << std::endl;
        } else
        {
            if (monthlyPayment > balance)
            {
                monthlyPayment = balance;

            }
                
            double previousBalance = balance;

            balance = balance - monthlyPayment;
            totalPayments = totalPayments + monthlyPayment;

            if (balance > 0)
            {
                interest = balance * interestRateDecimal;

            }

               
            else

                interest = 0.0;

            balance = balance + interest;
            totalInterest = totalInterest + interest;

            if (balance < 0)
                balance = 0.0;

            std::cout << std::setw(2) << month
                << std::setw(8) << "$" << std::setw(7) << previousBalance
                << std::setw(10) << "$" << std::setw(7) << monthlyPayment
                << std::setw(10) << "$" << std::setw(7) << interest
                << std::setw(10) << "$" << std::setw(7) << balance
                << std::endl;

            if (balance <= 0)
            {
                for (int i = month + 1; i <= 12; ++i)
                {
                    std::cout << std::setw(2) << i
                        << std::setw(8) << "$" << std::setw(7) << 0.00
                        << std::setw(10) << "$" << std::setw(7) << 0.00
                        << std::setw(10) << "$" << std::setw(7) << 0.00
                        << std::setw(10) << "$" << std::setw(7) << 0.00
                        << std::endl;


                }
                break;
            }
        }
    }
    std::cout << std::string(70, '-') << std::endl;
    std::cout << std::setw(2) << " "
        << std::setw(10) << "Total"
        << std::setw(10) << " "
        << std::setw(10) << "$ " << std::setw(7) << totalPayments
        << std::setw(10) << "$ " << std::setw(7) << totalInterest
        << std::endl;
}
