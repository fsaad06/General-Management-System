//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>


// Including user defined header files
#include "./../include/IndependantFunctions.h"

//indicating standard namespace to use
using namespace std;

void EXIT()
{
    cout << "\n\n\n";
    cout << "\t \t __________________________________________________\n";
    cout << "\t \t|    Terminating the Program in 1 second...!!!     |\n";
    cout << "\t \t|__________________________________________________|\n";
    Sleep(1000); // waiting 1s before exiting...just for "dramatic effect"
}
void initial_setup(){
	system("color 0B");
}

// Adding any number of tabs
void tab(int nums){
	for (int i = 0; i < nums; i++)            // Option 02: for (int i : Range)
	{
		cout << "\t";
	}
}

//Adding any number of newlines
void line(int nums){
	for (int i = 0; i < nums; i++){
		cout << "\n";
	}
}

//Setting position of cursor on console
void position(int x, int y)
{
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
	print_text(0, 0, "Student Management System");

	for (int x2 = 0; x2 < 120; x2++)
	{
		position(x2, 6);
		printf("%c", 219);
	}
	line(2);
}

int MAIN_MENU_OR_EXIT(int choice)
{
    cout << "\n\n";
    cout << "\t \t >> Please choose one of the following options:\n\n";
    cout << "\t \t ____________________________________________" << endl;
    cout << "\t \t |1. Return to Main Menu                      |" << endl;
    cout << "\t \t |2. Exit                                     |" << endl;
    {
        cout << "\n\t \t Answer: ";

        try                          //....   Exception Handling incase of Wrong Input    ...//
        {    
            cin >> choice;
            if ((choice == 2) || (choice == 1)) {
                return choice;      // returning right choice...
            }
            else{
                throw choice;       // throwing bad input for chocie...
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
            for (int i = 3; i > 0; i--)  // incase of wrong input, user waits for i seconds to try again...prevents spamming...
            {
                cout << "\n\n\n";
                cout << "\t \t  __________________________________________________\n";
                cout << "\t \t |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                cout << "\t \t |__________________________________________________\n";
                Sleep(1000);
                system("cls");
            }
            print_heading();
            MAIN_MENU_OR_EXIT(choice);
        }
    }
}