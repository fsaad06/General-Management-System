// Guard Against Multiple Builds
#ifndef BANK
#define BANK

// Importing required libraries 
#include <iostream>

// Indicating standard namespace to use
using namespace std;

class Bank // Base class named bank
{
private:
    string Bank_name;
    string Bank_branch;

protected:
    int idOfEmp[5] = {123, 456, 789, 246, 135}; // Assinging Id's of employee's , "you have to enter exact id to perform the action of an employee"

public:
    Bank();                                 // Default Constructor
    Bank(string name, string branch);       // Parametrized Constructor
    void showBankDetails();

    friend void intro();                    // To get Access to Private
};

#endif