//Importing the basic libraries
#include <iostream>
#include <fstream>
#include <windows.h>

//Using standard namespace
using namespace std;

// Functions to be used for Front-End
void initial_setup();
void tab(int nums);
void line(int nums);
void position(int x, int y);
void print_text(int lines, int tabs, string text);
void print_heading();
int Selection();

int main()
{
    initial_setup(); // calling intro funciton for displaying some info
    print_heading();

    switch (Selection()){
    case 1: 
    system ("HMS.exe");
    break;
    
    case 2: 
    system ("test.exe");
    break;
    
    case 3: 
    system ("bankManagementSystem.exe");
    break;
    
    case 4: 
    system ("Feedback.exe");
    break;

    default : print_text(1, 5, "INVALID INPUT"); 
}

    system("pause");
    return 0;
}

// Setting Colour
void initial_setup(){
	system("color 0E");
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
	print_text(0, 0, "General Management System");

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

int Selection (){
    int temp;
    cout << endl << endl;
    system("cls");
    cout << endl << endl;
    print_text(1, 5, "-----------------------------------------");
    print_text(1, 5, "Please Select One Among the Following "); 
    print_text(1, 5, "-----------------------------------------");
    cout << endl << endl;
    print_text(1, 5, "[01] : HOSPITAL MANAGEMENT SYSTEM \n  "); 
    print_text(1, 5, "[02] : PARKING MANAGEMENT SYSTEM \n "); 
    print_text(1, 5, "[03] : BANK MANAGEMENT SYSTEM \n "); 
    print_text(1, 5, "[04] : STUDENT HOSPITAL MANAGEMENT SYSTEM \n  "); 
    print_text(1, 5, "Your Option :   "); 
    cin >> temp;
    return temp;
}