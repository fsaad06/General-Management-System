//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>
#include <windows.h>
#include <stdio.h>
#include <filesystem>
#include<bits/stdc++.h>

//indicating standard namespace to use
using namespace std;

// Including user defined header files
#include "./../include/Admin.h"

ADMIN::ADMIN()                                          // Default Constructor 
{
    LOGIN_SUCCESSFUL = false;
}
void ADMIN::SET_USERNAME(string SET_THIS_USERNAME)      // Setter for USERNAME //
{
    USERNAME = SET_THIS_USERNAME;
}
string ADMIN::GET_USERNAME()                            //Getter for USERNAME
{
    return USERNAME;
}

void ADMIN::SET_PASSWORD(string SET_THIS_PASSWORD)      // Setter for PASSWORD
{
    PASSWORD = SET_THIS_PASSWORD;
}
string ADMIN::GET_PASSWORD()                            // Getter for PASSWORD 
{
    return PASSWORD;
}

//LOGIN FUNCTION 
bool ADMIN::LOGIN_FUNCTION(bool ITS_ADMIN)
{
    cout << "Enter your LOGIN: " << flush;
    cin >> USERNAME;

    LOWER_USERNAME = USERNAME;
    transform(LOWER_USERNAME.begin(), LOWER_USERNAME.end(), LOWER_USERNAME.begin(), ::tolower); //...function to convert string into lowercase
    if (LOWER_USERNAME == "admin")                                                            
    {
        ITS_ADMIN = TRUE;
        return ITS_ADMIN;
    }
    else
    {
        ITS_ADMIN = FALSE;
        return ITS_ADMIN;
    }
}



// LOGIN VALIDATION FUNCTION
bool ADMIN::LOGIN_VALIDATION_FUNCTION()
{
    cout << "Enter your PASSWORD: " << flush;
    cin >> PASSWORD;
    string ADMIN_FILE_PATH = "./../Admin/ADMIN_LOGIN.txt";
    string CHECK = GET_LOGIN_DATA(ADMIN_FILE_PATH.c_str()); //...this function returns with a line [password] from ADMIN file....//
            
    try     //... Exception Handling incase of Unsuccessful Login ...//
    {     
        if (CHECK == USERNAME)
        {
            ADMIN_FILE_PATH = "./../Admin/ADMIN_PASSWORD.txt";
            DECRYPT(ADMIN_FILE_PATH.c_str());                   //... calling the decrypt function, so we can match the password...//
            CHECK = GET_LOGIN_DATA(ADMIN_FILE_PATH.c_str());    //...this function returns with a line [password] from ADMIN file....//
            if (CHECK == PASSWORD)
            {
                cout << "LOGIN SUCCESSFUL...!!" << endl;
                LOGIN_SUCCESSFUL = true;
                ENCRYPT(ADMIN_FILE_PATH.c_str());                //...encrypting the password...//
                return TRUE;
            }
            else
            {
                ENCRYPT(ADMIN_FILE_PATH.c_str());               //...if the login fails [wrong password],  we still encrypt the password...//
                throw LOGIN_SUCCESSFUL;
            }
        }
        else
        {
            throw LOGIN_SUCCESSFUL;                              //...USERNAME != admin, so it might be a student, or bad username input...//
        }
    }
    catch (bool LOGIN_SUCCESSFUL)
    {
        UNREFERENCED_PARAMETER(LOGIN_SUCCESSFUL);               //...catching the bool was resulting in some warnings, and this is the solution I found online...//
        system("cls");
        cout << flush;
        print_heading();
        cout << "login Failed, Try Again..." << endl << endl;
        bool ITS_ADMIN = FALSE;
        return FALSE;
    }
}

//GET USERNAME & PASSWORD FUNCTION  
string ADMIN::GET_LOGIN_DATA(const string& FILE_NAME)
{
    string LINE;
    fstream READ;
    READ.open(FILE_NAME.c_str(), ios::in);
    {
        if (READ.is_open())                 //...file exists = TRUE...//
        {
            getline(READ, LINE);            //...reads a line from the file [username/password]...//
        }
    }
    READ.close();
    return LINE; //...returning the read data...//
}



// ADMIN MAIN MENU 
int ADMIN::ADMIN_MAIN_MENU_FUNCTION(int choice)
{
    system("cls");
    print_heading();
    cout << "\t \t You're now logged in as an ADMINISTRATOR...." << endl << endl << endl;

    cout << "\t \t >> Please choose one of the following options:\n\n";

    cout << "\t \t ____________________________________________" << endl;
    cout << "\t \t |1. Manage Feedback Form                     |" << endl;
    cout << "\t \t |2. Manage Students                          |" << endl;
    cout << "\t \t |3. Manage Submitted Feedbacks               |" << endl;
    cout << "\t \t |4. Change Your Password                     |" << endl;
    cout << "\t \t |5. Log-Out                                  |" << endl;
    cout << "\t \t |6. Exit                                     |" << endl;
    {
        cout << "\n          Answer: ";

                 //////////////////////////////////////////////////////////
        try     //....   Exception Handling incase of Wrong Input    ...//
        {      //////////////////////////////////////////////////////////
            cin >> choice;
            if ((choice <= 6) && (choice >= 1)) //...the choice is within the range...//
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
                cout << "\t \t |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                cout << "\t \t |__________________________________________________\n";
                Sleep(1000);
                system("cls");
            }
            ADMIN_MAIN_MENU_FUNCTION(choice);
        }
    }
}



//ADMIN MANAGE FEEDBACK FORM MENU 
int ADMIN::ADMIN_MANAGE_FEEDBACK_FORM_MENU_FUNCTION(int choice)
{
    system("cls");
    print_heading();

    cout << "\t \t>> Please choose one of the following options:\n\n";

    cout << "\t \t____________________________________________" << endl;
    cout << "\t \t|1. Print Feedback Form                      |" << endl;
    cout << "\t \t|2. Edit Feedback Form                       |" << endl;
    cout << "\t \t|3. Search Feedback Form                     |" << endl;
    cout << "\t \t|4. Return to Main Menu                      |" << endl;
    cout << "\t \t|5. Exit                                     |" << endl;
    {
        cout << "\n\t \tAnswer: ";

      
        try                         //....   Exception Handling incase of Wrong Input    ...//
        {      
            cin >> choice;
            if ((choice <= 5) && (choice >= 1)){
                return choice;
            }
            else{
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
                cout << "\t \t__________________________________________________\n";
                cout << "\t \t|  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                cout << "\t \t|__________________________________________________\n";
                Sleep(1000);
                system("cls");
            }
            ADMIN_MANAGE_FEEDBACK_FORM_MENU_FUNCTION(choice);
        }
    }
}


//1.1.PRINT THE FEEDBACK FORM 
void ADMIN::PRINT_FEEDBACK_FORM()
{
    cout << "\t \t_________________________________\n";
    cout << "\t \t|          FEEDBACK FORM          |\n";
    cout << "\t \t|_________________________________|\n";
    cout << "\n";
    string* FEEDBACK_FORM;
    int LINE_COUNT = 0;
    int COUNTER = 0;

    fstream READ;
    string READ_LINE;
    READ.open("./../Feedback Form/Feedback Form.txt", ios::in);
    {
        while (getline(READ, READ_LINE))
        {
            LINE_COUNT++;
        }
    }
    READ.close();
                                        
    FEEDBACK_FORM = new string[LINE_COUNT];     //...Dynamic String Array that has element number = lines in feedback form...// 
                                                //... [each line has one question, hence each index will carry one question]..//

    READ.open("./../Feedback Form/Feedback Form.txt", ios::in);
    {
        while (getline(READ, READ_LINE))
        {
            FEEDBACK_FORM[COUNTER] = READ_LINE;
            COUNTER++;
        }
    }
    READ.close();

    for (int i = 0; i < LINE_COUNT; i++)
    {
        cout << FEEDBACK_FORM[i] << endl;
    }
    delete[]FEEDBACK_FORM;
}


// ADMIN EDIT FEEDBACK FORM MENU 
int ADMIN::ADMIN_EDIT_FEEDBACK_FORM_MENU_FUNCTION(int choice)
{
    system("cls");
    print_heading();
    cout << "\t \t________________________________________________\n";
    cout << "\t \t|               EDIT FEEDBACK FORM               |\n";
    cout << "\t \t|________________________________________________|\n";
    cout << "\n";

    cout << "\t \t>> Please choose one of the following options:\n\n";

    cout << "\t \t____________________________________________" << endl;
    cout << "\t \t|1. Add A New Question                       |" << endl;
    cout << "\t \t|2. Remove A Question                        |" << endl;
    cout << "\t \t|3. Return to Main Menu                      |" << endl;
    cout << "\t \t|4. Exit                                     |" << endl;
    {
        cout << "\n\t \tAnswer: ";


        try                     //....   Exception Handling incase of Wrong Input    ...//
        {    
            cin >> choice;
            if ((choice <= 4) && (choice >= 1)){
                return choice;
            }
            else{
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
                cout << "\t \t|  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                cout << "\t \t|__________________________________________________\n";
                Sleep(1000);
                system("cls");
            }
            ADMIN_EDIT_FEEDBACK_FORM_MENU_FUNCTION(choice);
        }
    }
}



// ADD A NEW QUESTION 
void ADMIN::ADD_QUESTION()
{
    system("cls");
    print_heading();
    cout << "\t \t__________________________________________________\n";
    cout << "\t \t|                ADD A NEW QUESTION                |\n";
    cout << "\t \t|__________________________________________________|\n";
    cout << "\n";

    string QUESTION;
    cout << "\t \t Enter The NEW QUESTION: ";
    cin.ignore();
    getline(cin, QUESTION); //... reading the new question in a new line ...///

    fstream READ;
    string READ_LINE;
    int LINE_COUNT = 0;
    READ.open("./../Feedback Form/Feedback Form.txt", ios::in);
    {
        while (getline(READ, READ_LINE))
        {
            LINE_COUNT++;
        }
    }
    READ.close();

    QUESTION = to_string(LINE_COUNT + 1) + ") " + QUESTION;      //... adding numeric identifier to the new question...//

    READ.open("./../Feedback Form/Feedback Form.txt", ios::app);
    {
        READ << endl << QUESTION;                               //... writing the new question add by the user into the file...//
    }
    READ.close();

    cout << "\t \t__________________________________________________\n";
    cout << "\t \t| NEW QUESTION ADDED SUCCESSFULLY...               |\n";
    cout << "\t \t|__________________________________________________|\n";
    cout << "\n";
}

// REMOVE A QUESTION
void ADMIN::REMOVE_QUESTION()
{
    system("cls");
    print_heading();
    cout << "\t \t __________________________________________________\n";
    cout << "\t \t|                REMOVE A QUESTION                 |\n";
    cout << "\t \t|__________________________________________________|\n";
    cout << "\n";

    int QUESTION;
    cout << "\t \tEnter the Question Number that you want to remove: ";

    fstream READ;
    string READ_LINE;
    int LINE_COUNT = 0;
    READ.open("./../Feedback Form/Feedback Form.txt", ios::in);
    {
        while (getline(READ, READ_LINE))
        {
            LINE_COUNT++;
        }
    }
    READ.close();

    try                                                 //....   Exception Handling incase of Wrong Input    ...//
    {   
        cin >> QUESTION;
        if ((QUESTION <= LINE_COUNT) && (QUESTION >= 1))
        {
            string* FEEDBACK_FORM;
            int COUNTER = 0;
                                                
            FEEDBACK_FORM = new string[LINE_COUNT];     //...Dynamic String Array that has element number = lines in feedback form...// 
                                                         //... [each line has one question, hence each index will carry one question]..//
            READ.open("./../Feedback Form/Feedback Form.txt", ios::in);
            {
                while (getline(READ, READ_LINE))
                {
                    if ((COUNTER + 1) != QUESTION)
                    {
                        FEEDBACK_FORM[COUNTER] = READ_LINE; //... reading all the questions except the one we want to remove...//
                        COUNTER++;
                    }
                    else
                    {
                        COUNTER++;
                    }
                }
            }
            READ.close();

            ofstream OVER_WRITE;
            OVER_WRITE.open("./../Feedback Form/Feedback Form.txt");
            {
                for (int i = 0; i < LINE_COUNT; i++)
                {
                    if (i != QUESTION - 1)              //... writing all the questions except the one we want to remove...//
                    {
                        OVER_WRITE << FEEDBACK_FORM[i] << endl;
                    }
                }
            }
            OVER_WRITE.close();

            cout << "\t \t__________________________________________________\n";
            cout << "\t \t| QUESTION REMOVED SUCCESSFULLY...                 |\n";
            cout << "\t \t|__________________________________________________|\n";
            cout << "\n";
            delete[]FEEDBACK_FORM;
        }
        else
        {
            throw QUESTION;
        }
    }
    catch (int QUESTION)
    {
        cout << '\a';
        cin.clear();
        cin.ignore(256, '\n');
        QUESTION = 0;
        system("cls");
        cout << flush;
        for (int i = 3; i > 0; i--)
        {
            cout << "\n\n\n";
            cout << "\t \t__________________________________________________\n";
            cout << "\t \t|  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
            cout << "\t \t|__________________________________________________\n";
            Sleep(1000);
            system("cls");
        }
        REMOVE_QUESTION();
    }
}

// SEARCH IN FEEDBACK FORM    
bool ADMIN::SEARCH_IN_FEEDBACK_FORM()
{
    system("cls");
    print_heading();
    cout << "\t \t__________________________________________________\n";
    cout << "\t \t|              SEARCH IN FEEDBACK FORM             |\n";
    cout << "\t \t|__________________________________________________|\n";
    cout << "\n";

    string QUERY;
    cout << "\t \t Enter your Search Query: ";
    cin.ignore();
    getline(cin, QUERY);

    string* FEEDBACK_FORM;
    int LINE_COUNT = 0;
    int COUNTER = 0;

    fstream READ;
    string READ_LINE;
    READ.open("./../Feedback Form/Feedback Form.txt", ios::in);
    {
        while (getline(READ, READ_LINE))
        {
            LINE_COUNT++;
        }
    }
    READ.close();
    FEEDBACK_FORM = new string[LINE_COUNT];     //...Dynamic String Array that has element number = lines in feedback form...// 
                                                //... [each line has one question, hence each index will carry one question]..//

    READ.open("./../Feedback Form/Feedback Form.txt", ios::in);
    {
        while (getline(READ, READ_LINE))
        {
            FEEDBACK_FORM[COUNTER] = READ_LINE;
            COUNTER++;
        }
    }
    READ.close();

    for (int i = 0; i < LINE_COUNT; i++)
    {
        if (FEEDBACK_FORM[i].find(QUERY) != string::npos)   //...searching until end of file for the query...//
        {
            return TRUE;
        }
    }
    return FALSE;
}



// ADMIN MANAGE STUDENTS MENU
int ADMIN::ADMIN_MANAGE_STUDENTS_MENU_FUNCTION(int choice)
{
    system("cls");
    print_heading();

    cout << "\t \t>> Please choose one of the following options:\n\n";

    cout << "\t \t____________________________________________" << endl;
    cout << "\t \t|1. Check Total Number of Students           |" << endl;
    cout << "\t \t|2. Search A Student  [NEPTUN CODE]          |" << endl;
    cout << "\t \t|3. Remove A Student  [NEPTUN CODE]          |" << endl;
    cout << "\t \t|4. Add A New Student [NEPTUN CODE]          |" << endl;
    cout << "\t \t|5. Return to Main Menu                      |" << endl;
    cout << "\t \t|6. Exit                                     |" << endl;
    {
        cout << "\n\t \tAnswer: ";

        try     //....   Exception Handling incase of Wrong Input    ...//
        {   
            cin >> choice;
            if ((choice <= 6) && (choice >= 1)){
                return choice;
            }
            else{
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
                cout << "\t \t__________________________________________________\n";
                cout << "\t \t|  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                cout << "\t \t|__________________________________________________\n";
                Sleep(1000);
                system("cls");
            }
            ADMIN_MANAGE_STUDENTS_MENU_FUNCTION(choice);
        }
    }
}
// CHECK TOTAL NUMBER OF STUDENTS 
void ADMIN::TOTAL_STUDENTS()
{
    system("cls");
    print_heading();;
    cout << "\t \t________________________________________________\n";
    cout << "\t \t|                  TOTAL STUDENTS                |\n";
    cout << "\t \t|________________________________________________|\n";
    cout << "\n";

    int TOTAL_FILES = 0;
    string FILE_PATH = "./../Students/";                          //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (auto& p : filesystem::directory_iterator(FILE_PATH)) // This Loop was inspired by Stack Overflow Discussion on File Counting Methods, It makes use of FILESYSTEM library.....//
    {                                                        // https://stackoverflow.com/questions/41304891/how-to-count-the-number-of-files-in-a-directory-using-standard/41305019 //
        TOTAL_FILES++;                                      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    }
    cout << "\n\t \t >> Total Number of Students: " << TOTAL_FILES << " <<" << endl << endl << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////      2.2.SEARCH A STUDENT [NEPTUN CODE]      /////////////////////////////////////
void ADMIN::SEARCH_STUDENT()
{
    system("cls");
    print_heading();
    cout << "\t \t  __________________________________________________\n";
    cout << "\t \t |                 SEARCH A STUDENT                 |\n";
    cout << "\t \t |__________________________________________________|\n";
    cout << "\n";

    string NEPTUN;
    cout << "              Enter NEPTUN CODE: ";
    cin >> NEPTUN;

    string FILE_PATH = "./../Students/" + NEPTUN + ".txt";

    if (!CHECK_EXISTING_FILE(FILE_PATH.c_str())) //... each student has it's own file, named as his/her NEPTUN code, if the students exists, it means his/her file MUST exist too...///
    {
        cout << "\n\n\n";
        cout << "\t \t __________________________________________________\n";
        cout << "\t \t |  No Student exists under this NEPTUN Code...     \n";
        cout << "\t \t |__________________________________________________\n";
    }
    else
    {
        cout << "\n\n\n";
        cout << "\t \t __________________________________________________\n";
        cout << "\t \t |  Student Exists In The Database...                \n";
        cout << "\t \t |__________________________________________________\n";
    }
}

// 2.3.REMOVE A STUDENT [NEPTUN CODE]
void ADMIN::REMOVE_STUDENT()
{
    system("cls");
    print_heading();
    cout << " \t \t __________________________________________________\n";
    cout << " \t \t |                 REMOVE A STUDENT                 |\n";
    cout << " \t \t |__________________________________________________|\n";
    cout << "\n";
    cout << "\t \t >> Please be aware, removing a student will also remove his/her submitted feedbacks...!!!" << endl << endl;

    string NEPTUN;
    cout << "\t \t Enter NEPTUN CODE: ";
    cin >> NEPTUN;

    string FILE_PATH = "./Students/" + NEPTUN + ".txt";

    if (!CHECK_EXISTING_FILE(FILE_PATH.c_str()))
    {
        cout << "\n\n\n";
        cout << "\t \t __________________________________________________\n";
        cout << "\t \t |  No Student exists under this NEPTUN Code...     \n";
        cout << "\t \t |__________________________________________________\n";
    }
    else
    {
        remove(FILE_PATH.c_str());//......................................................removing student
        string FILE_PATH = "./Feedback Form/Submitted Feedbacks/" + NEPTUN + ".txt";//...changing path to submitted feedback
        remove(FILE_PATH.c_str());//....................................................removing submitted feedback

        cout << "\n\n\n";
        cout << "\t \t __________________________________________________\n";
        cout << "\t \t |  Student Deleted Successfully...                 \n";
        cout << "\t \t |__________________________________________________\n";
    }
}

//ADD A NEW STUDENT [NEPTUN CODE]
void ADMIN::ADD_STUDENT()
{
    system("cls");
    print_heading();
    cout << "\t \t __________________________________________________\n";
    cout << "\t \t |                   ADD A STUDENT                  |\n";
    cout << "\t \t |__________________________________________________|\n";
    cout << "\n";

    string NEPTUN;
    cout << "\t \t Enter NEPTUN CODE: ";
    cin >> NEPTUN;


    string FILE_PATH = "./../Students/" + NEPTUN + ".txt";

    if (CHECK_EXISTING_FILE(FILE_PATH.c_str()))
    {
        cout << "\n\n\n";
        cout << "\t \t __________________________________________________\n";
        cout << "\t \t |  Student already exists...                       \n";
        cout << "\t \t |__________________________________________________\n";
    }
    else
    {
        string PASSWORD;
        cout << "\t \t Set A New PASSWORD: "; //... setting a temporary password for the new student...//
        cin >> PASSWORD;

        fstream ADD;
        ADD.open(FILE_PATH.c_str(), ios::app); //...made a file named as Student's NPETUN, and added the password...//
        {
            ADD << PASSWORD;
        }
        ADD.close();

        ENCRYPT(FILE_PATH.c_str()); //...encrypting the password...//
        cout << "\n\n\n";
        cout << "\t \t __________________________________________________\n";
        cout << "\t \t |  Student Added Successfully...                 \n";
        cout << "\t \t |__________________________________________________\n";
    }
}

// ADMIN MANAGE SUBMITTED FEEDBACKS MENU 
int ADMIN::ADMIN_MANAGE_SUBMITTED_FEEDBACKS_MENU_FUNCTION(int choice)
{
    system("cls");
    print_heading();

    cout << "\t \t >> Please choose one of the following options:\n\n";

    cout << "\t \t _________________________________________________" << endl;
    cout << "\t \t |1. Check Total Number of Submitted Feedbacks     |" << endl;
    cout << "\t \t |2. Print  A Student's Feedback [NEPTUN CODE]     |" << endl;
    cout << "\t \t |3. Remove A Student's Feedback [NEPTUN CODE]     |" << endl;
    cout << "\t \t |4. Return to Main Menu                           |" << endl;
    cout << "\t \t |5. Exit                                          |" << endl;
    {
        cout << "\n\t \t Answer: ";

        //////////////////////////////////////////////////////////
        try     //....   Exception Handling incase of Wrong Input    ...//
        {      //////////////////////////////////////////////////////////
            cin >> choice;
            if ((choice <= 5) && (choice >= 1)){
                return choice;
            }
            else{
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
                cout << "\t \t |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                cout << "\t \t |__________________________________________________\n";
                Sleep(1000);
                system("cls");
            }
            ADMIN_MANAGE_SUBMITTED_FEEDBACKS_MENU_FUNCTION(choice);
        }
    }
}



// 3.1.CHECK TOTAL NUMBER OF SUBMITTED FEEDBACKS
void ADMIN::TOTAL_SUBMITTED_FEEDBACKS()
{
    system("cls");
    print_heading();
    cout << "\t \t ________________________________________________\n";
    cout << "\t \t |         TOTAL SUBMITTED FEEDBACK FORMS         |\n";
    cout << "\t \t |________________________________________________|\n";
    cout << "\n";

    int TOTAL_FILES = 0;
    string FILE_PATH = "./../Feedback Form/Submitted Feedbacks/"; //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (auto& p : filesystem::directory_iterator(FILE_PATH)) // This Loop was inspired by Stack Overflow Discussion on File Counting Methods, It makes use of FILESYSTEM library.....//
    {                                                        // https://stackoverflow.com/questions/41304891/how-to-count-the-number-of-files-in-a-directory-using-standard/41305019 //
        TOTAL_FILES++;                                      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    }
    cout << "\n               >> Total Number of Submitted Feedback Files: " << TOTAL_FILES << " <<" << endl << endl << endl;
}



//  3.2.PRINT A STUDENT'S FEEDBACK [NEPTUN CODE] 
bool ADMIN::PRINT_SUBMITTED_FEEDBACK_FORM()
{
    system("cls");
    print_heading();
    cout << "\t \t ___________________________________________\n";
    cout << "\t \t |          SUBMITTED FEEDBACK FORM          |\n";
    cout << "\t \t |___________________________________________|\n";
    cout << "\n";

    string NEPTUN;
    cout << "\t \t Enter NEPTUN CODE: ";
    cin >> NEPTUN;

    string FILE_PATH = "./../Feedback Form/Submitted Feedbacks/" + NEPTUN + ".txt";

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

// REMOVE A STUDENT'S FEEDBACK [NEPTUN CODE]
void ADMIN::REMOVE_SUBMITTED_FEEDBACK()
{
    system("cls");
    print_heading();
    cout << "\t \t __________________________________________________\n";
    cout << "\t \t |          REMOVE SUBMITTED FEEDBACK FORM          |\n";
    cout << "\t \t |__________________________________________________|\n";
    cout << "\n";

    string NEPTUN;
    cout << "\t \t Enter NEPTUN CODE: ";
    cin >> NEPTUN;

    string FILE_PATH = "./../Feedback Form/Submitted Feedbacks/" + NEPTUN + ".txt"; //... default path for submitted feedbacks...//

    if (!CHECK_EXISTING_FILE(FILE_PATH.c_str()))
    {
        cout << "\n\n\n";
        cout << "\t \t __________________________________________________\n";
        cout << "\t \t |  No Feedback Submitted by this student yet...    \n";
        cout << "\t \t |__________________________________________________\n";
    }
    else
    {
        remove(FILE_PATH.c_str());

        cout << "\n\n\n";
        cout << "\t \t __________________________________________________\n";
        cout << "\t \t |  Submitted Feedback File Deleted Successfully... \n";
        cout << "\t \t |__________________________________________________\n";
    }
}

// CHANGE YOUR PASSWORD
void ADMIN::CHANGE_PASSWORD()
{
    system("cls");
    print_heading();
    cout << "\t \t ________________________________________________\n";
    cout << "\t \t |             CHANGE YOUR PASSWORD               |\n";
    cout << "\t \t |________________________________________________|\n";
    cout << "\n";

    string NEW_PASSWORD;
    cout << "\t \t >> Enter your NEW PASSWORD: ";
    cin >> NEW_PASSWORD;

    string FILE_PATH = "./../Admin/ADMIN_PASSWORD.txt";
    ofstream OVER_WRITE;
    OVER_WRITE.open(FILE_PATH.c_str());         // opening in default [over-write] mode
    {
        OVER_WRITE << NEW_PASSWORD;             // over writing the old password
    }
    OVER_WRITE.close();
    ENCRYPT(FILE_PATH.c_str());                  // encryopting the new password

    cout << "\t \t ________________________________________________\n";
    cout << "\t \t |           PASSWORD CHANGED SUCCESSFULLY...     |\n";
    cout << "\t \t |________________________________________________|\n";
    cout << "\n";


}

// Checking Existing File
bool ADMIN::CHECK_EXISTING_FILE(const string& FILE_NAME)
{
    fstream READ;
    READ.open(FILE_NAME.c_str(), ios::in);
    {
        if (READ.is_open())             // file exists and can be opened...
        {
            READ.close();
            return TRUE;                // file found...
        }
        return false;                   // file not found...
    }
}

// ENCRYPT 
void ADMIN::ENCRYPT(const string& FILE_NAME)
{
    string DATA;
    fstream READ;
    READ.open(FILE_NAME.c_str(), ios::in);
    {
        getline(READ, DATA);
        for (unsigned int x = 0; x < DATA.length(); x++)
        {
            DATA[x] += 3;       // using simple ceasar cipher...
                                 //add a number to each character 
                                //and garble the whole string character by character
        }
    }
    READ.close();

    ofstream OVERWRITE;
    OVERWRITE.open(FILE_NAME.c_str());
    {
        OVERWRITE << DATA;      // over-write the old data with new encrypted data...
    }
    OVERWRITE.close();
}

// DECRYPT               
void ADMIN::DECRYPT(const string& FILE_NAME)
{
    string DATA;
    fstream READ;
    READ.open(FILE_NAME.c_str(), ios::in);
    {
        getline(READ, DATA);
        for (unsigned int x = 0; x < DATA.length(); x++)
        {
            DATA[x] -= 3;       // using simple ceasar cipher...
                                //add a number to each character 
                                //and garble the whole string character by character
        }
    }
    READ.close();

    ofstream OVERWRITE;
    OVERWRITE.open(FILE_NAME.c_str());
    {
        OVERWRITE << DATA;// over-write the old data with new encrypted data...
    }
    OVERWRITE.close();
}