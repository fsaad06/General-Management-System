//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>

// Including user defined header files
#include "./../include/Vehicle.h"
#include "./../include/Cabin.h"

//indicating standard namespace to use
using namespace std;


vehicle_data::vehicle_data() : filename("vehicle_file")
{
}
//vector to introduce the concept of back insertion only
vector<store> vehicle_data::read_to_vector()
{
	vector<store> data;
	int money = 0;;
	vehicle_file.open(filename, ios::in);
	if (vehicle_file.is_open()) {
		string tp;
		string value[6];
		int k = 0;
		while (getline(vehicle_file, tp))
		{
				string temp = "";
				int j = 0;
				for (int i = 0; i < (int)tp.size(); i++)
				{
					// If cur char is not del, then append it to the cur "word", otherwise
					  // you have completed the word, print it, and start a new word.
					if (tp[i] != ',') {
						temp += tp[i];
					}
					else {
						value[j] = temp;
						j++;
						temp = "";
					}
				}

				store obj;
				obj.vehicle_num = value[0];
				obj.vehicle_type = value[1];
				obj.park_time = value[2];
				obj.exit_time = value[3];
				obj.fee = value[4];
				obj.fine = value[5];

				data.push_back(obj);


			k++;
		}
		vehicle_file.close();
	}
	vehicle_file.close();
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i].vehicle_num << setw(10)
			<< " " << data[i].vehicle_type << setw(10)
			<< " " << data[i].park_time << setw(10)
			<< " " << data[i].exit_time << setw(10)
			<< " " << data[i].fee << setw(10)
			<< " " << data[i].fine << setw(10) << endl;
	}
	return data;
}



//checking existance of file
void vehicle_data::check_vehicle_file()
{
	vehicle_file.open(filename, ios::in);
	if (vehicle_file) 
	{
		print_text(1, 5, "File exists");
		vehicle_file.close();
	}
	else
	{
		print_text(1, 5, "File doesn't exist");
		cout << endl;
		make_vehicle_file();
	}
}
//creating file
void vehicle_data::make_vehicle_file()
{
	vehicle_file.open(filename, ios::out);
	cout << "New file created" << endl;
	vehicle_file.close();
	initial_data();
}
//edit vehicle file
void vehicle_data::edit_vehicle_file(string vehicle_num, string type, string enter_time, string exit_time, string fee, string fine)
{
	vehicle_file.open(filename, ios::app);
	vehicle_file << vehicle_num + "," + type + "," + enter_time + exit_time + "," + fee + "," + fine + "," << "\n";
	vehicle_file.close();
}
//delete vehicle file
void vehicle_data::delete_vehicle_file()
{
	vehicle_file.open(filename, ios::out);
	vehicle_file << "";
	vehicle_file.close();
}

void vehicle_data::initial_data()
{
		vehicle_file.open(filename, ios::out);
		//car_num, type, park_time,exit_time,fee_payed,retrieved
		vehicle_file << "Vehicle Num,Vehicle Type,Park time,Exit Time,Fee,Fine,\n";
		vehicle_file.close();
}
//function to calculate money on the basis of time
int vehicle_data::calculate_money()
{
	int money = 0;;
	vehicle_file.open(filename, ios::in);
	if (vehicle_file.is_open()) {
		string tp;
		string value[6];
		int k = 0;
		while (getline(vehicle_file, tp))
		{
			string temp = "";
			int j = 0;
			for (int i = 0; i < (int)tp.size(); i++)
			{
				// If cur char is not del, then append it to the cur "word", otherwise
				  // you have completed the word, print it, and start a new word.
				if (tp[i] != ',') {
					temp += tp[i];
				}
				else {
					value[j] = temp;
					if (j == 4 && k!=0)
					{
						int mon;
						try
						{
							mon = stoi(temp);
							throw "Cannot convert string to int";
						}
						catch(const char* exception)
						{
							cerr << "Error: " << exception << endl;
						}
						money += mon;
					}
					j++;
					temp = "";
				}
			}
			k++;
		}
		vehicle_file.close();
	}
	vehicle_file.close();
	return money;
}
//function to read file
void vehicle_data::read_vehicle_file()
{
	vehicle_file.open(filename, ios::in);
	if (vehicle_file.is_open()) {
		string tp;
		while (getline(vehicle_file, tp))
		{
			print_text(1, 5, tp);
			cout << endl;
			/*cout << tp << "\n";*/
		}
		vehicle_file.close();
	}
	vehicle_file.close();
}

//setter functions

void vehicle::set_values(parking p)
{
	fine_bike = p.get_fine_bike();
	fee_bike = p.get_fee_bike();
	fine_car = p.get_fine_car();
	fee_car = p.get_fee_car();
}

void vehicle::set_cabin(int cab)
{
	cabin = cab;
}


void vehicle::set_num_plate(int num)
{

	num_plate = num;
}

void vehicle::set_park_time()
{
	park_time = time(nullptr);
}

void vehicle::set_exit_time()
{
	exit_time = time(nullptr);
}

void vehicle::set_custom_park_time(time_t t)
{
	park_time = t;
}

int vehicle::get_plate()
{
	return num_plate;
}

double vehicle::get_exit_time()
{
	return exit_time;
}

time_t vehicle::get_park_time()
{
	return park_time;
}

double vehicle::calculate_time()
{
	return (exit_time - park_time) / 60;
}


int car::get_type()
{
	return 1;
}
double car::calculate_fee()
{
	return calculate_time() * fee_car;
}
double car::calculate_fine()
{
	if (calculate_time() > hrs)
	{
		return calculate_time()* fine_car;
	}
	return 0;
}

car::~car()
{

}

int bike::get_type()
{
	return 0;
}
double bike::calculate_fee()
{
	return calculate_time() * fee_bike;
}
double bike::calculate_fine()
{
	if (calculate_time() > hrs)
	{
		return calculate_time() * fine_bike;
	}
	return 0;
}
//destructor
bike::~bike()
{

}
