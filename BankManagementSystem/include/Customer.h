// Guard Against Multiple Builds
#ifndef CUSTOMER
#define CUSTOMER

// Importing required libraries 
#include <iostream>

// Including user defined header file
#include "./Bank.h"

//indicating standard namespace to use
using namespace std;

// Instead of defining as default (private), defining Data Variables as PROTECTED to be used by child classes
class customer : public Bank // Customer class inheriting properties from bank class
{
protected:
    int accNumber;
    char name[20];
    int balance;
    char type;

public:
    void create_account();              // initializing funcitons
    void show_account() const;
    void modify();
    void deposit(int);
    void withdraw(int);
    void report() const;
    int retAccNumber() const;
    int retBalance() const;
    char retAccType() const;
};
#endif