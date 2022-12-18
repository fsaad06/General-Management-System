// Guard Against Multiple Builds
#ifndef DRIVER
#define DRIVER

//importing required libraries  
#include <string>

// Including user defined header file
#include "./person.h"

//indicating standard namespace to use
using namespace std;

// #include "ambulance.h" gives error, so found this solution on StackOverFlow 
class ambulance;

// Single Level Inheritance
class driver : public person
{
private:
    string licenseNumber;
    bool idle;
    friend class ambulance;      // To access Private Data

public:
    driver();                    // Default Constructor
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void removePerson();
};
#endif                            // !DRIVER