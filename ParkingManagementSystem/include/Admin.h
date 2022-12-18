// To Reduce Build Times 
#ifndef ADMIN
#define ADMIN

//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>

// Including user defined header files
#include "Vehicle.h"
#include "Cabin.h"

//indicating standard namespace to use
using namespace std;

class admin{
	// Declaring passowrd and file name as static
	static int password;
	static string filename;

public:
	fstream admin_file;
	void check_admin_file();
	void make_admin_file();
	void delete_admin_file();

	// Defining Static Function for Password Verification
	static bool verify_password(int pass);
	void set_filename(string file);
	static string get_filename();
	void read_admin_file();
	void edit_admin_file();
	void read_vehicle();
	vector<store> read_to_vector();
	int calc_money();

	// Operator Overloading
	void operator-();

	//destructor
	~admin();
};
#endif