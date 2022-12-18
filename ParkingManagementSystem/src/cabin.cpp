//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>
#include <windows.h>
#include "./../include/Cabin.h"

//indicating standard namespace to use
using namespace std;

//Adding any number of tabs
void tab(int nums){
	for (int i = 0; i < nums; i++)
	{
		cout << "\t";
	}
}

//Adding any number of newlines
void line(int nums){
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

cabin::cabin(){}  						// To Provide Flexibility

cabin::cabin(int num)					// Parametarized Constructor 01
{
	cabin_num = num;
	type = 0;
	password = 0;
	num_plate = 0;
	parked = 0;
	time = 0;
}

cabin::cabin(int num, int park)			// Parametarized Constructor 02
{
	cabin_num = num;
	type = 0;
	password = 0;
	num_plate = 0;
	parked = park;
	time = 0;
}

cabin::cabin(int num, int park, int category, int plate, time_t times)// Parametarized Constructor 03
{
	cabin_num = num;
	password = 0;
	type = category;
	num_plate = plate;
	parked = park;
	time = times;
}
//getter functions
int cabin::get_cabin_num()
{
	return cabin_num;
}

cabin_data::cabin_data() : filename("cabin_file")
{
}
//checking existance of file
void cabin_data::check_data_file()
{
	cabin_file.open(filename, ios::in);
	if (cabin_file)
	{
		print_text(1, 5, "File exists");
		cabin_file.close();
	}
	else
	{
		print_text(1, 5, "File doesn't exist");
		make_data_file();
	}
}

void cabin_data::make_data_file()
{
	cabin_file.open(filename, ios::out);
	print_text(1, 5, "New file created");
	cabin_file.close();
}

//retrieving initial cabin data
void cabin_data::initial_cabin_data(int no_of_cabins)
{

	cabin_file.open(filename, ios::out);
	for (int i = 1; i <= no_of_cabins; i++)
	{
		//cabin_num, parked_status, type, password, num_plate, park_time
		cabin_file << to_string(i) + ",0,-1,-1,-1,-1,\n";
	}
	cabin_file.close();
}

//editing data
void cabin_data::edit_cabin_data(cabin c[], int size)
{

	delete_car_file();
	cabin_file.open(filename, ios::out);
	for (int i = 0; i < size; i++)
	{
		//cabin_num, parked_status, type, password, num_plate, park_time
		cabin_file << to_string(c[i].cabin_num) << "," << to_string(c[i].parked) << "," << to_string(c[i].type) <<
			"," << to_string(c[i].password) << "," << to_string(c[i].num_plate) << "," << to_string(c[i].time) << ",\n";
	}
	cabin_file.close();
}

void cabin_data::delete_car_file()
{
	cabin_file.close();
	cabin_file.open(filename, ios::trunc);
	cabin_file << "";
	cabin_file.close();
}

cabin* cabin_data::read_file_to_array(cabin cab[])
{
	cabin_file.open(filename, ios::in);

	if (cabin_file.is_open()) {
		string tp;
		int k = 0;
		while (getline(cabin_file, tp))
		{
			string temp = "";
			int j = 0;
			for (int i = 0; i <= (int)tp.size(); i++)
			{
				// If cur char is not del, then append it to the cur "word", otherwise
				  // you have completed the word, print it, and start a new word.
				if (tp[i] != ',') {
					temp += tp[i];
				}
				else {
					int num = stoi(temp);
						switch (j)
						{
						case 0:
							cab[k].cabin_num = num;

							break;

						case 1:
							cab[k].parked = num;
							break;

						case 2:
							cab[k].type = num;
							break;

						case 3:
							cab[k].password = num;
							break;

						case 4:
							cab[k].num_plate = num;
							break;

						case 5:
							cab[k].time = num;
							break;
						}

						j++;
						temp = "";
				}
			}
			k++;
		}
		cabin_file.close();
	}
	cabin_file.close();
	return cab;
}

int cabin_data::search_by_num(int plate)
{
	cabin_file.open(filename, ios::in);

	if (cabin_file.is_open()) {
		string tp;
		int k = 0;
		while (getline(cabin_file, tp))
		{
			string temp = "";
			int j = 0;
			for (int i = 0; i <= (int)tp.size(); i++)
			{
				// If cur char is not del, then append it to the cur "word", otherwise
				  // you have completed the word, print it, and start a new word.
				if (tp[i] != ',') {
					temp += tp[i];
				}
				else {
					int num = stoi(temp);
					if (plate == num && j == 4)
					{
						return k;
					}

					j++;
					temp = "";
				}
			}
			k++;
		}
		cabin_file.close();
	}
	cabin_file.close();
	return -1;
}