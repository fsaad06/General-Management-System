// Guard Against Multiple Builds
#ifndef ADDRESS
#define ADDRESS

// Importing required libraries 
#include <string>

//indicating standard namespace to use
using namespace std;

// Can make Struct instead of class, here
class address
{
private:
    string line1, line2;
    string city;
    string state;
    string pinCode;
    string country;

public:
    address();
    void takeInput();
    void print();
    string addToStr();
    void strToAdd(string str);
};
#endif                      // !ADDRESS