// To Reduce Build Times 
#ifndef PARKING
#define PARKING

//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>

//indicating standard namespace to use
using namespace std;

// Instead of defining as default (private), defining Data Variables as PROTECTED to be used by child classes
class parking
{
protected:
	int cabins;
	double fee_car;
	double fee_bike;
	int hrs;
	double fine_car;
	double fine_bike;

public:
	int get_cabins();
	int get_fee_car();
	int get_fine_car();
	int get_fee_bike();
	int get_fine_bike();

	//friend function
	friend parking make_parking_profile();
};

parking make_parking_profile();

#endif

