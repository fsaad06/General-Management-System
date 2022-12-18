#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <sstream>
#include <stdio.h>

// Including user defined header file
#include "./include/Bank.h"
#include "./include/Customer.h"
#include "./include/Employee.h"

//indicating standard namespace to use
using namespace std;

// Functions to be used for Front-End
void initial_setup();
void tab(int nums);
void line(int nums);
void position(int x, int y);
void print_text(int lines, int tabs, string text);
void print_heading();

//******************        MAIN FUNCTION           ***********************/

int main()
{
    initial_setup(); // calling intro funciton for displaying some info
    print_heading();
    employee emp(1);

    char ch;
    int num;

    do
    {
        system("cls"); // giving choice and calling the particular funciton based on the choice entered
        cout << "\n\n\n\t MAIN MENU";
        cout << "\n\n\t 01. NEW ACCOUNT";
        cout << "\n\n\t 02. DEPOSIT AMOUNT";
        cout << "\n\n\t 03. WITHDRAW AMOUNT";
        cout << "\n\n\t 04. BALANCE ENQUIRY";
        cout << "\n\n\t 05. ALL ACCOUNT HOLDER LIST";
        cout << "\n\n\t 06. CLOSE AN ACCOUNT";
        cout << "\n\n\t 07. MODIFY AN ACCOUNT";
        cout << "\n\n\t 08. EXIT";
        cout << "\n\n\t Select Your Option (1-8) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            emp.write_account();
            break;

        case '2':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            emp.deposit_withdraw(num, 1);
            break;

        case '3':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            emp.deposit_withdraw(num, 2);
            break;

        case '4':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            emp.display_sp(num);
            break;

        case '5':
            emp.display_all();
            break;

        case '6':

            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            emp.delete_account(num);
            break;

        case '7':

            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            emp.modify_account(num);
            break;

        case '8':
            print_text(1, 5, "\n \nThanks for using our Bank Management System");
            print_text(1, 5, "\n  We Hope that our system did'nt disappointed you : \n");
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}



// Setting Colour
void initial_setup(){
	system("color 0D");
}

// Adding any number of tabs
void tab(int nums)
{
	for (int i = 0; i < nums; i++)       // Option 02: for (int i : Range)
	{
		cout << "\t";
	}
}

//Adding any number of newlines
void line(int nums)
{
	for (int i = 0; i < nums; i++)
	{
		cout << "\n";
	}
}

//Setting position of cursor on console
void position(int x, int y){
	HANDLE Screen;
	Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position_value = { (short)x,(short)y };
	SetConsoleCursorPosition(Screen, position_value);
}

//Custom function for formatted text
void print_text(int lines, int tabs, string text){
	line(lines);
	tab(tabs);
	cout << text;
}

// Setting Heading
void print_heading(){
	system("cls");

	for (int x1 = 0; x1 < 120; x1++)
	{
		position(x1, 2);
		printf("%c", 219);
	}
	position(42, 4);
	print_text(0, 0, "Bank Management System");

	for (int x2 = 0; x2 < 120; x2++)
	{
		position(x2, 6);
		printf("%c", 219);
	}
	line(2);
    print_text(1, 5, "Hope You Will Enjoy \n \n "); 
    print_text(1, 5, "Please press enter to continue : ");

    cin.get();
}
