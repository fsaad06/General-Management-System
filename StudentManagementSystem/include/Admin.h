// Guard Against Multiple Builds
#ifndef ADMIN_H
#define ADMIN_H

//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>

// Including user defined header file
#include "./IndependantFunctions.h"
#include "./CaesarCipher.h"

//indicating standard namespace to use
using namespace std;

// Multiple Inheritance
class ADMIN: public ENCRYPTION, public DECRYPTION
{
    string USERNAME;
    string PASSWORD;
public:
    string LOWER_USERNAME;
    bool LOGIN_SUCCESSFUL;

    ADMIN();                // Default Constructor 

    // setter Functions
    void SET_USERNAME(string SET_THIS_USERNAME); 
    void SET_PASSWORD(string SET_THIS_PASSWORD); 

    // getter Functions
    string GET_USERNAME(); 
    string GET_PASSWORD(); 

    // Checking Functions
    bool LOGIN_FUNCTION(bool ITS_ADMIN);
    bool SEARCH_IN_FEEDBACK_FORM();
    bool CHECK_EXISTING_FILE(const string& FILE_NAME);

    // Helping Functions
    void ADD_QUESTION();
    void REMOVE_QUESTION();
    void TOTAL_STUDENTS();
    void SEARCH_STUDENT();
    void REMOVE_STUDENT();
    void ADD_STUDENT();
    void TOTAL_SUBMITTED_FEEDBACKS();
    void PRINT_FEEDBACK_FORM();
    void REMOVE_SUBMITTED_FEEDBACK();
    string GET_LOGIN_DATA(const string& FILE_NAME);
    
    // Admin Power
    int ADMIN_MAIN_MENU_FUNCTION(int choice);
    int ADMIN_MANAGE_FEEDBACK_FORM_MENU_FUNCTION(int choice);
    int ADMIN_EDIT_FEEDBACK_FORM_MENU_FUNCTION(int choice);
    int ADMIN_MANAGE_STUDENTS_MENU_FUNCTION(int choice);
    int ADMIN_MANAGE_SUBMITTED_FEEDBACKS_MENU_FUNCTION(int choice);

    // Functions to be later Defined by Child Class
    virtual bool LOGIN_VALIDATION_FUNCTION();
    virtual void CHANGE_PASSWORD();
    virtual bool PRINT_SUBMITTED_FEEDBACK_FORM();

    // Encrypting and De-Encrypting Functions
    void ENCRYPT(const string& FILE_NAME)override;
    void DECRYPT(const string& FILE_NAME)override;  
};

#endif                                      // !ADMIN

