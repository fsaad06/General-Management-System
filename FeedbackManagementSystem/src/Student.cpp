// Importing required libraries 
#include<iostream>
#include<string>
#include<fstream>

// Including user defined header files
#include "./../include/Student.h"
#include "./../include/Admin.h"

// Indicating standard namespace to use
using namespace std;

// Default Constructor 
STUDENT::STUDENT()  {
    LOGIN_SUCCESSFUL = false;
}

// LOGIN FUNCTION [OVERLOADED]  
bool STUDENT::LOGIN_VALIDATION_FUNCTION()
{
    cout << "Enter your PASSWORD: " << flush;
    cin >> STUDENT_PASSWORD;
    SET_PASSWORD(STUDENT_PASSWORD);
     string STUDENT_FILE_PATH = "./Students/" + GET_USERNAME() + ".txt";

        fstream CHECK_FILE_EXIST;
        CHECK_FILE_EXIST.open(STUDENT_FILE_PATH.c_str(), ios::in);

        if (CHECK_FILE_EXIST.is_open())
        {
            CHECK_FILE_EXIST.close();
            DECRYPT(STUDENT_FILE_PATH.c_str());
            string CHECK = GET_LOGIN_DATA(STUDENT_FILE_PATH.c_str());
            
            try     //... Exception Handling incase of Unsuccessful Login ...//
            {      
                if (CHECK == GET_PASSWORD())
                {
                    cout << "LOGIN SUCCESSFUL...!" << endl;
                    LOGIN_SUCCESSFUL = true;
                    ENCRYPT(STUDENT_FILE_PATH.c_str());
                    return TRUE;
                }
                else
                {
                    ENCRYPT(STUDENT_FILE_PATH.c_str());
                    throw LOGIN_SUCCESSFUL;
                }
            }
            catch (bool LOGIN_SUCCESSFUL)
            {
                UNREFERENCED_PARAMETER(LOGIN_SUCCESSFUL);
                system("cls");
                cout << flush;
                print_heading();
                cout << "login Failed, Try Again..." << endl << endl;
                bool ITS_STUDENT = FALSE;
                return FALSE;
            }
        }
        else
        {
            system("cls");
            cout << flush;
            print_heading();
            cout << "login Failed, Try Again..." << endl << endl;
            bool ITS_STUDENT = FALSE;
            return FALSE;
        }
    }
    

    // STUDENT MAIN MENU
    int STUDENT::STUDENT_MAIN_MENU_FUNCTION(int choice)
    {
        system("cls");
        print_heading();
        cout << "\t \t You're now logged in as a STUDENT...." << endl << endl << endl;
        cout << "\t \t >> Please choose one of the following options:\n\n";
        cout << "\t \t  ____________________________________________" << endl;
        cout << "\t \t | 1. View The Feedback Form                   |" << endl;
        cout << "\t \t | 2. Fill_Out The Feedback Form               |" << endl;
        cout << "\t \t | 3. View Your Submitted Feedback             |" << endl;
        cout << "\t \t | 4. Change Your Password                     |" << endl;
        cout << "\t \t | 5. Log_Out                                  |" << endl;
        cout << "\t \t | 6. Exit                                     |" << endl;
        cout << "\n \t \t Answer: ";
        try     // Exception Handling 
            {      //////////////////////////////////////////////////////////
                cin >> choice;
                if ((choice <= 6) && (choice >= 1))
                {
                    return choice;
                }
                else
                {
                    throw choice;
                }
            }
            catch (int choice)
            {
                cout << '\a';
                cin.clear();
                cin.ignore(256, '\n');
                choice = 0;
                system("cls");
                cout << flush;
                for (int i = 3; i > 0; i--)
                {
                    cout << "\n\n\n";
                    cout << "\t \t __________________________________________________\n";
                    cout << " \t \t |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                    cout << " \t \t |__________________________________________________\n";
                    Sleep(1000);
                    system("cls");
                }
                STUDENT_MAIN_MENU_FUNCTION(choice);
            }
        
    }

    // FILL_OUT THE FEEDBACK FORM                 
    bool STUDENT::STUDENT_FILL_OUT_THE_FEEDBACK_FORM_FUNCTION(int choice)
    {
        system("cls");
        print_heading();

        string FILE_PATH = "./Feedback Form/Submitted Feedbacks/" + GET_USERNAME() + ".txt";

        if (CHECK_EXISTING_FILE(FILE_PATH.c_str()))
        {
            cout << "\n\n\n";
            cout << "\t \t __________________________________________________\n";
            cout << "\t \t |  FEEDBACK ALREADY SUBMITTED...!                  \n";
            cout << "\t \t |__________________________________________________\n";
            return FALSE;
        }

        string QUESTION_LINE;
        fstream READ_FEEDBACK_FORM;
        fstream WRITE_FEEDBACK_ANSWERS;
        READ_FEEDBACK_FORM.open("./Feedback Form/Feedback Form.txt", ios::in);
        WRITE_FEEDBACK_ANSWERS.open(FILE_PATH.c_str(), ios::app);
        {
            while (getline(READ_FEEDBACK_FORM, QUESTION_LINE))
            {
                cout << QUESTION_LINE << endl << "    1. STRONGLY AGREE    2. AGREE    3. NEUTRAL    4. DISAGREE    5. STRONGLY DISAGREE" << endl;

            CHOICE_SELECTION:
                cout << endl << "ENTER A CHOICE: ";

                        
                try     //....   Exception Handling incase of Wrong Input    ...//
                {     
                    cin >> choice;
                    cout << endl;
                    if ((choice <= 5) && (choice >= 1))
                    {
                        if (choice == 1)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    1. STRONGLY AGREE" << endl << endl;
                        }
                        if (choice == 2)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    2. AGREE" << endl << endl;
                        }
                        if (choice == 3)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    3. NEUTRAL" << endl << endl;
                        }
                        if (choice == 4)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    4. DISAGREE" << endl << endl;
                        }
                        if (choice == 5)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    5. STRONGLY DISAGREE" << endl << endl;
                        }
                    }
                    else
                    {
                        throw choice;
                    }
                }
                catch (int choice)
                {
                    cout << '\a';
                    cin.clear();
                    cin.ignore(256, '\n');
                    choice = 0;
                    for (int i = 1; i > 0; i--)
                    {
                        cout << "\n\n\n";
                        cout << "\t \t __________________________________________________\n";
                        cout << "\t \t |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                        cout << "\t \t |__________________________________________________\n";
                        Sleep(1000);
                        cout << endl << endl << " ERROR: INVALID INPUT: ENTER AGAIN: ";
                    }
                    goto CHOICE_SELECTION;
                }
            }
        }
        READ_FEEDBACK_FORM.close();
        WRITE_FEEDBACK_ANSWERS.close();
        return true;

    }

    // VIEW YOUR SUBMITTED FEEDBACK [OVERLOADED] 
    bool STUDENT::PRINT_SUBMITTED_FEEDBACK_FORM()
    {
        system("cls");
        print_heading();

        string FILE_PATH = "./Feedback Form/Submitted Feedbacks/" + GET_USERNAME() + ".txt";

        if (!CHECK_EXISTING_FILE(FILE_PATH.c_str()))
        {
            cout << "\n\n\n";
            cout << "\t \t __________________________________________________\n";
            cout << "\t \t |  No Feedback Submitted by this student yet...    \n";
            cout << "\t \t |__________________________________________________\n";
            return FALSE;
        }

        else
        {
            string SUBMITTED_FEEDBACK_FORM;
            fstream READ;
            READ.open(FILE_PATH.c_str(), ios::in);
            {
                while (getline(READ, SUBMITTED_FEEDBACK_FORM))
                {
                    cout << SUBMITTED_FEEDBACK_FORM << endl;
                }
            }
            READ.close();
            return TRUE;
        }

    }

    // CHANGE YOUR PASSWORD  [OVERLOADED]           
    void STUDENT::CHANGE_PASSWORD()
    {
        system("cls");
        print_heading();
        cout << " \t \t ________________________________________________\n";
        cout << " \t \t |             CHANGE YOUR PASSWORD               |\n";
        cout << " \t \t |________________________________________________|\n";
        cout << "\n";

        string NEW_PASSWORD;
        cout << "\t \t >> Enter your NEW PASSWORD: ";
        cin >> NEW_PASSWORD;

        string FILE_PATH = "./Students/" + GET_USERNAME() + ".txt";
        ofstream OVER_WRITE;
        OVER_WRITE.open(FILE_PATH.c_str());
        {
            OVER_WRITE << NEW_PASSWORD;
        }
        OVER_WRITE.close();
        ENCRYPT(FILE_PATH.c_str());

        cout << "\t \t ________________________________________________\n";
        cout << "\t \t |           PASSWORD CHANGED SUCCESSFULLY...     |\n";
        cout << "\t \t |________________________________________________|\n";
        cout << "\n";
    }
