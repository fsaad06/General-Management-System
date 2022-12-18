//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>

// Including user defined header files
#include "./../include/Parking.h"
#include "./../include/Admin.h"

//indicating standard namespace to use
using namespace std;

// getter functions 
int parking::get_cabins(){
	return cabins;
}

int parking::get_fee_car(){
	return fee_car;
}

int parking::get_fine_car(){
	return fine_car;
}

int parking::get_fee_bike(){
	return fee_bike;
}

int parking::get_fine_bike(){
	return fine_bike;
}

parking make_parking_profile(){
	parking pr;
	string filename = admin::get_filename();
	fstream file;
	file.open(filename, ios::in);
	if (file)
	{
		char ch;
		string* values = new string[10];
		int i = 0;
		//varibales separated by commas
		while (!file.eof())
		{
			file >> ch;
			if (ch == ',')
			{
				i += 1;
			}
			else
			{
				values[i] += ch;
			}
		}
		//converting string to int and double
		pr.cabins = stoi(values[0]);
		pr.fee_car = stod(values[1]);
		pr.fee_bike = stod(values[2]);
		pr.hrs = stoi(values[3]);
		pr.fine_car = stod(values[4]);
		pr.fine_bike = stod(values[5]);

		delete[] values;//deleteing dynamic object
	}
	return pr;//returning object
}