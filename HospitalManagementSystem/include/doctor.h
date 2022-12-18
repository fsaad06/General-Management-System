//Guard Against Multiple Builds
#ifndef DOCTOR
#define DOCTOR

//importing required libraries 
#include <string>

// Including user defined header file
#include "./person.h"

//indicating standard namespace to use
using namespace std;

// #include "appointment.h" gives error, so found this solution on StackOverFlow 
class appointment;

// Single Level Inheritance
class doctor : public person
{
private:
    string type;
    int appointmentsBooked;
    friend class appointment;           // To access Private Data

public:
    doctor();                           // Default Constructor
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void removePerson();
};
#endif                                  // !DOCTOR