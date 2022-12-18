// Guard Against Multiple Builds
#ifndef STUDENT_H
#define STUDENT_H

// Importing required libraries
#include <iostream>
#include <string>

// Including user defined header file
#include "./Admin.h"

//indicating standard namespace to use
using namespace std;

// Single Level Inheritance
class STUDENT : public ADMIN
{
public:
    string STUDENT_PASSWORD;

    // Default Constructor 
    STUDENT();                                  

    int STUDENT_MAIN_MENU_FUNCTION(int choice);

    // Checking Functions
    bool LOGIN_VALIDATION_FUNCTION();
    bool STUDENT_FILL_OUT_THE_FEEDBACK_FORM_FUNCTION(int choice);
    bool PRINT_SUBMITTED_FEEDBACK_FORM();

    // Setter Functions
    void CHANGE_PASSWORD();
};
#endif                          // !STUDENT