// Imporing Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>

//indicating standard namespace to use
using namespace std;

// Including user defined header file
#include "./include/Admin.h"
#include "./include/CaesarCipher.h"
#include "./include/IndependantFunctions.h"
#include "./include/Student.h"

//indicating standard namespace to use
using namespace std;

// Helping Functions
bool ITS_ADMIN;
bool ITS_STUDENT;
int CHOICE;

int main()
{
    ADMIN ADMINISTRATOR;
    STUDENT STUDENT;

    initial_setup();
    print_heading();

LOGIN_SCREEN:
    // ADMIN RELATED FUNCTIONS AND IMPLEMENTATIONS 
    if (ADMINISTRATOR.LOGIN_FUNCTION(ITS_ADMIN)) {
        if (ADMINISTRATOR.LOGIN_VALIDATION_FUNCTION()){
            ITS_ADMIN = TRUE;
            ITS_STUDENT = FALSE;

    Admin_Main_Menu:
            CHOICE = ADMINISTRATOR.ADMIN_MAIN_MENU_FUNCTION(CHOICE);

            if (CHOICE == 1) {
                cout << flush;
                CHOICE = ADMINISTRATOR.ADMIN_MANAGE_FEEDBACK_FORM_MENU_FUNCTION(CHOICE);
                {
                    if (CHOICE == 1)
                    {
                        system("cls");
                        cout << flush;
                        print_heading();
                        ADMINISTRATOR.PRINT_FEEDBACK_FORM();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1){
                                goto Admin_Main_Menu;
                            }
                            else{
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 2) /////..... User Selected: Edit Feedback Form ...../////
                    {
                        cout << flush;
                        CHOICE = ADMINISTRATOR.ADMIN_EDIT_FEEDBACK_FORM_MENU_FUNCTION(CHOICE);
                        if(CHOICE == 1)
                        {
                            ADMINISTRATOR.ADD_QUESTION();
                            CHOICE = 0;
                            CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                            {
                                if (CHOICE == 1){
                                    goto Admin_Main_Menu;
                                }
                                else{
                                    CHOICE = 0;
                                    EXIT();
                                }
                            }
                        }
                        if(CHOICE == 2){
                            ADMINISTRATOR.REMOVE_QUESTION();
                            CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                            {
                                if (CHOICE == 1){
                                    goto Admin_Main_Menu;
                                }
                                else{
                                    CHOICE = 0;
                                    EXIT();
                                }
                            }
                        }
                        if (CHOICE == 3){
                            goto Admin_Main_Menu;
                        }
                        if (CHOICE == 4)
                        {
                            EXIT();
                        }                        
                    }
                    if (CHOICE == 3) {
                        system("cls");
                        cout << flush;
                        print_heading();
                        if(ADMINISTRATOR.SEARCH_IN_FEEDBACK_FORM()){
                            cout << "\t \t __________________________________________________\n";
                            cout << "\t \t |                QUERY FOUND...!!!                 |\n";
                            cout << "\t \t |__________________________________________________|\n";
                            cout << "\n";
                        }
                        else{
                            cout << "\t \t __________________________________________________\n";
                            cout << "\t \t |  Your Query doesn't exist in the Feedback Form   |\n";
                            cout << "\t \t |__________________________________________________|\n";
                            cout << "\n";
                        }
                        
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1){
                                goto Admin_Main_Menu;
                            }
                            else{
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 4){
                        goto Admin_Main_Menu;
                    }
                    if (CHOICE == 5){
                        EXIT();
                    }
                }
            }
            if (CHOICE == 2){
                cout << flush;
                CHOICE = ADMINISTRATOR.ADMIN_MANAGE_STUDENTS_MENU_FUNCTION(CHOICE);
                {
                    if (CHOICE == 1){
                        ADMINISTRATOR.TOTAL_STUDENTS();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1){
                                goto Admin_Main_Menu;
                            }
                            else{
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 2){
                        ADMINISTRATOR.SEARCH_STUDENT();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1)
                            {
                                goto Admin_Main_Menu;
                            }
                            else
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 3){
                        ADMINISTRATOR.REMOVE_STUDENT();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);{
                            if (CHOICE == 1)
                            {
                                goto Admin_Main_Menu;
                            }
                            else
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 4)
                    {
                        ADMINISTRATOR.ADD_STUDENT();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1){
                                goto Admin_Main_Menu;
                            }
                            else{
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 5)
                    {
                        goto Admin_Main_Menu;
                    }
                    if (CHOICE == 6)
                    {
                        EXIT();
                    }
                }
            }
            if (CHOICE == 3){
                system("cls");
                cout << flush;
                print_heading();
                CHOICE = ADMINISTRATOR.ADMIN_MANAGE_SUBMITTED_FEEDBACKS_MENU_FUNCTION(CHOICE);
                {
                    if (CHOICE == 1)
                    {
                        ADMINISTRATOR.TOTAL_SUBMITTED_FEEDBACKS();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1){
                                goto Admin_Main_Menu;
                            }
                            else{
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 2){
                        if (!ADMINISTRATOR.PRINT_SUBMITTED_FEEDBACK_FORM()){
                            CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                            {
                                if (CHOICE == 1){
                                    goto Admin_Main_Menu;
                                }
                                else{
                                    EXIT();
                                }
                            }
                        }
                        else{
                            CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                            {
                                if (CHOICE == 1){
                                    goto Admin_Main_Menu;
                                }
                                else{
                                    EXIT();
                                }
                            }
                        }

                    }
                    if (CHOICE == 3)
                    {
                        ADMINISTRATOR.REMOVE_SUBMITTED_FEEDBACK();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1){
                                goto Admin_Main_Menu;
                            }
                            else
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 4){
                        goto Admin_Main_Menu;
                    }
                    if (CHOICE == 5){
                        EXIT();
                    }
                }
            }
            if (CHOICE == 4)
            {
                ADMINISTRATOR.CHANGE_PASSWORD();
                CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                {
                    if (CHOICE == 1)
                    {
                        goto Admin_Main_Menu;
                    }
                    else
                    {
                        CHOICE = 0;
                        EXIT();
                    }
                }
            }
            if (CHOICE == 5){
                system("cls");
                print_heading();
                goto LOGIN_SCREEN;
            }
            if (CHOICE == 6)
            {
                EXIT();
            }

        }
        else
        {
            goto LOGIN_SCREEN; 
        }

    }

    else
    {
        STUDENT.SET_USERNAME(ADMINISTRATOR.GET_USERNAME());

        if (STUDENT.LOGIN_VALIDATION_FUNCTION()){
            ITS_ADMIN = FALSE;
            ITS_STUDENT = TRUE;

        Student_Main_Menu:
            CHOICE = STUDENT.STUDENT_MAIN_MENU_FUNCTION(CHOICE);

            if (CHOICE == 1)
            {
                system("cls");
                cout << flush;
                print_heading();
                ADMINISTRATOR.PRINT_FEEDBACK_FORM();
                CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                {
                    if (CHOICE == 1)
                    {
                        goto Student_Main_Menu;
                    }
                    else
                    {
                        CHOICE = 0;
                        EXIT();
                    }
                }


            }
            if (CHOICE == 2){
                if (!STUDENT.STUDENT_FILL_OUT_THE_FEEDBACK_FORM_FUNCTION(CHOICE)){
                    CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                    {
                        if (CHOICE == 1){
                            goto Student_Main_Menu;
                        }
                        else{
                            EXIT();
                        }
                    }
                }
                else{
                    CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                    {
                        if (CHOICE == 1)
                        {
                            goto Student_Main_Menu;
                        }
                        else{
                            EXIT();
                        }
                    }
                }

            }
            if (CHOICE == 3){
                if (!STUDENT.PRINT_SUBMITTED_FEEDBACK_FORM()){
                    CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                    {
                        if (CHOICE == 1){
                            goto Student_Main_Menu;
                        }
                        else{
                            EXIT();
                        }
                    }
                }
                else{
                    CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                    {
                        if (CHOICE == 1){
                            goto Student_Main_Menu;
                        }
                        else{
                            EXIT();
                        }
                    }
                }
            }
            if (CHOICE == 4){
                STUDENT.CHANGE_PASSWORD();
                CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                {
                    if (CHOICE == 1){
                        goto Student_Main_Menu;
                    }
                    else{
                        CHOICE = 0;
                        EXIT();
                    }
                }
            }
            if (CHOICE == 5){
                system("cls");
                print_heading();
                goto LOGIN_SCREEN;
            }
            if (CHOICE == 6){
                EXIT();
            }
        }
        else
            goto LOGIN_SCREEN; 
    }
    return 0;
}