// To Reduce Build Times 
#ifndef CABIN
#define CABIN

//importing required libraries
#include<iostream>
#include<string>
#include<fstream>

// Including user defined header file
#include "./Parking.h"

//indicating standard namespace to use
using namespace std;

// Single Level Inheritace
class cabin : protected parking{
public:
	int cabin_num;
	int num_plate;
	int parked;
	int type;
	int password;

	// Using Appropriate Data Type for Time
	time_t time;

public:
	//cabin data as a friend (To access Private)
	friend class cabin_data;
    
	// Constructors
	cabin();     						// Default Constructor
	cabin(int num);						//parameterized constructors
	cabin(int num, int park);
	cabin(int num, int park, int category, int plate, time_t times);

	int get_cabin_num();
};

// class cabin data  inheriitng the properties of class parking
class cabin_data : protected parking
{
	string filename;
	int file_length;

public:
	fstream cabin_file;

	cabin_data();
	void check_data_file();
	void make_data_file();
	void initial_cabin_data(int no_of_cabins);
	void edit_cabin_data(cabin c[], int size);
	void delete_car_file();
	cabin* read_file_to_array(cabin cab[]);
	int search_by_num(int plate);
};

// Defining Functions for Front End
void tab(int nums);
void line(int nums);
void position(int x, int y);
void print_text(int lines, int tabs, string text);

#endif