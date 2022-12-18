// Guard Against Multiple Builds
#ifndef PATIENT
#define PATIENT

// Including user defined header file
#include "./person.h"

//indicating standard namespace to use
using namespace std;

// #include "appointment.h" gives error, so found this solution on StackOverFlow 
class appointment;

// Single Level Inheritance
class patient : public person
{
private:
    int height;                             // in cms;
    int weight;                             // in pounds;
    bool hospitalized;
    bool alive;
    friend class appointment;               // To access Private Data

public:
    patient();                              // Default Constructor
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void hospitalize();
    void reportADeath();
    void removePerson();
};
#endif                                      // !PATIENT