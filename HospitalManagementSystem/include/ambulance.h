// Guard Against Multiple Builds
#ifndef AMBULANCE
#define AMBULANCE

//importing required libraries 
#include <string>

// Indicating standard namespace to use
using namespace std;

// Including user defined header file
#include "./driver.h"
#include "./address.h"

class ambulance
{
private:
    int id;
    string model;
    string manufacturer;
    string vrn;                     // vehicle registration number;
    bool idle;
    address add;
    driver D;                       // Composition

public:
    ambulance();                     // Default Constructor
    void fillMap();
    void saveMap();
    void addAmbulance();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void send();
    void reportArrival();
    void removeAmbulance();
};
#endif // !AMBULANCE