// Guard Against Multiple Builds
#ifndef GLOBAL_HMS
#define GLOBAL_HMS

// Importing required libraries
#include <string>

//indicating standard namespace to use
using namespace std;

extern int yyyymmdd;                // extern : extends the visibility of variables and functions across multiple source files
int power(int n = 1, int exp = 0);
int strToNum(string s);

#endif                              // !GLOBAL_HMS