// Guard Against Multiple Builds
#ifndef PERSON
#define PERSON

// Importing Required Libraries 
#include <string>

// Including user defined header file
#include "./address.h"

// Indicating standard namespace to use
using namespace std;

// Instead of defining as default (private), defining Data Variables as PROTECTED to be used by child classes
class person                                            // Abstract class
{
protected:
    int id;
    string firstName, lastName;
    char gender;
    int16_t age;                                        // Defined as Short
    string mobNumber;
    address add;
    string cat;
    int category;
    //category: 01: Doctor; 02: Patient; 03: Nurse; 04: Driver;

public:
    person();
    virtual void fillMap() = 0;                         // Pure Virtual
    virtual void saveMap() = 0;
    virtual void addPerson(int16_t minAge = 0, int16_t maxAge = 1000);
    virtual void printDetails();
    virtual void printDetailsFromHistory();
    virtual void getDetails(int rec = 0) = 0;
    virtual void getDetailsFromHistory() = 0;
    virtual void removePerson() = 0;
};
#endif                                                  // !PERSON
