//Guard Against Multiple Builds
#ifndef INDEPENDATANTFINCTIONS_H
#define INDEPENDATANTFINCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>

//indicating standard namespace to use
using namespace std;

// Helping Functions     
void initial_setup();

// Adding any number of tabs
void tab(int nums);

//Adding any number of newlines
void line(int nums);

//Setting position of cursor on console
void position(int x, int y);

//Custom function for formatted text
void print_text(int lines, int tabs, string text);

// Setting Heading
void print_heading();

int MAIN_MENU_OR_EXIT(int choice);
void EXIT(); 

#endif              // !INDEPENDATANT_FUNCTIONS
