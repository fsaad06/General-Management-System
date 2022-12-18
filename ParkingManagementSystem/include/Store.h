// To Reduce Build Times 
#ifndef STORE
#define STORE

//importing required libraries 
#include<iostream>
#include<string>
#include<fstream>

//indicating standard namespace to use
using namespace std; 

// Only for Declaring some Variables
// Can also use Struct
class store
{
public:
	string vehicle_num;
	string vehicle_type;
	string park_time;
	string exit_time;
	string fee;
	string fine;
};

#endif

