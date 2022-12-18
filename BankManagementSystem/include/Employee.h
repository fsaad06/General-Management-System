// Guard Against Multiple Builds
#ifndef EMPLOYEE
#define EMPLOYEE

// Importing required libraries 
#include <iostream>

// Including user defined header file
#include "./Customer.h"

//indicating standard namespace to use
using namespace std;


class employee : private customer // employee class inheriting the properties of customer class
{
private:
    int emp_id;

public:
    employee() {}
    employee(int emp_id){
        this->emp_id = emp_id;
    }

    void showEmpId();
    void write_account();            // function to write record in binary file
    void display_sp(int);            // function to display account details given by user
    void modify_account(int);        // function to modify record of file
    void delete_account(int);        // function to delete record of file
    void display_all();              // function to display all account details
    void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
};
#endif
