//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>
#include <windows.h>

// Including user defined header files
#include "./../include/Admin.h"
#include "./../include/Cabin.h"

//indicating standard namespace to use
using namespace std;

int admin::password = 12345;//setting admin password
string admin::filename = "setup_data";

admin::~admin()
{
	admin_file.close();
	system("pause");
	getchar();
}
//checking existance of file
void admin::check_admin_file()
{
	admin_file.open(filename, ios::in);
	if (admin_file) {
		print_text(1, 5, "File exists");
		admin_file.close();
	}
	else
	{
		print_text(1, 5, "File doesn't exist");
		make_admin_file();
	}
}
//creating and setting admin file
void admin::make_admin_file()
{
	admin_file.open(filename, ios::out);
	print_text(1, 5, "New file created");
	print_text(1, 5, "________________________________");
	print_text(1, 5, "Enter number of cabins:");
	int cabins;
	cin >> cabins;

	//exception handling
	try {
		if (cabins < 0 || cabins > 9)
		{
			throw 1;
		}
	}
	catch (int x)
	{
		print_text(1, 5, "Out of bound. Default value 4 set");
		cabins = 4;
	}
	//prompts the admin to set the following data
	print_text(1, 5, "Enter per hour fee(car):");
	int hr_fee_car;
	cin >> hr_fee_car;

	print_text(1, 5, "Enter per hour fee(bike):");
	int hr_fee_bike;
	cin >> hr_fee_bike;

	print_text(1, 5, "Enter limit hours:");
	int hr;
	cin >> hr;

	print_text(1, 5, "Enter fine fee per hour(car):");
	int fine_car;
	cin >> fine_car;
	fine_car += hr_fee_car;

	print_text(1, 5, "Enter fine fee per hour(bike):");
	int fine_bike;
	cin >> fine_bike;
	fine_bike += hr_fee_bike;
	print_text(1, 5, "________________________________");

	admin_file << to_string(cabins) + "," + to_string(hr_fee_car) + "," + to_string(hr_fee_bike)
		+ "," + to_string(hr) + "," + to_string(fine_car) + "," + to_string(fine_bike);
	admin_file.close();

	cabin_data set_cabin;
	set_cabin.initial_cabin_data(cabins);
}

//deleting admin file
void admin::delete_admin_file()
{
	admin_file.close();
	admin_file.open(filename, ios::out);
	admin_file << "";
	admin_file.close();
}

//function to verify password
bool admin::verify_password(int pass)
{
	if (pass == password)
	{
		return true;
	}
	return false;
}


void admin::set_filename(string file)
{
	filename = file;
}

string admin::get_filename()
{
	return filename;
}
//view record
void admin::read_admin_file()
{
	admin_file.open(filename, ios::in);
	char ch;
	string* values = new string[10];
	int i = 0;
	while (!admin_file.eof())
	{
		admin_file >> ch;
		if (ch == ',')
		{
			i += 1;
		}
		else
		{
			values[i] += ch;
		}
	}
	print_text(1, 5, "________________________________");
	print_text(1, 5, "Cabin numbers is : " + values[0]);
	print_text(1, 5, "Per hour fee(car) is: " + values[1]);
	print_text(1, 5, "Per hour fee(bike) is : " + values[2]);
	print_text(1, 5, "Limit hours are : " + values[3]);
	print_text(1, 5, "Fine fee(car) is : " + values[4]);
	print_text(1, 5, "Fine fee(bike) is : " + values[5]);
	print_text(1, 5, "________________________________");
	print_text(1, 0, "");
	admin_file.close();

	delete[] values;
}
//edit properties
void admin::edit_admin_file()
{
	admin_file.open(filename, ios::in);
	char ch;
	string* values = new string[10];
	int i = 0;
	while (!admin_file.eof())
	{
		admin_file >> ch;
		if (ch == ',')
		{
			i += 1;
		}
		else
		{
			values[i] += ch;
		}
	}

	admin_file.close();//closing file

	print_text(1, 5, "________________________________");
	print_text(1, 5, "Edit Cabin Numbers     : 1");
	print_text(1, 5, "Edit car per hour fee  : 2");
	print_text(1, 5, "Edit bike per hour fee : 3");
	print_text(1, 5, "Edit Limit hours       : 4");
	print_text(1, 5, "Edit car per hour fine : 5");
	print_text(1, 5, "Edit bike per hour fine: 6");
	print_text(1, 5, "Exit                   : Any");
	print_text(1, 5, "________________________________");

	admin_file.close();

	print_text(2, 5, "Your choice: ");

	int choice;
	cin >> choice;

	if (choice < 1 || choice > 6)
	{
		return;
	}
	else
	{
		print_text(1, 5, "Enter the new value: ");
		int val;
		cin >> val;
		delete_admin_file();
		values[choice - 1] = to_string(val);
		admin_file.open(filename, ios::out);
		admin_file << values[0] + "," + values[1] + "," + values[2]
			+ "," + values[3] + "," + values[4] + "," + values[5];
		admin_file.close();
		cabin_data set_cabin;
		set_cabin.initial_cabin_data(stoi(values[0]));
	}

	delete[] values;//deleting dynamic object pointer

}

void admin::read_vehicle()
{
	vehicle_data file;
	file.read_vehicle_file();
}

vector<store> admin::read_to_vector()
{
	vehicle_data file;
	return file.read_to_vector();
}

int admin::calc_money()
{
	vehicle_data file;
	return file.calculate_money();
}


void admin::operator -()
{
	make_admin_file();
}