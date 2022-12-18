// Guard Against Multiple Builds
#ifndef NURSE
#define NURSE

// Importing required libraries
#include <string>

// Including user defined header file
#include "./person.h"

//indicating standard namespace to use
using namespace std;

// Single Level Inheritance
class nurse : public person
{
private:
    string type;

public:
    nurse();                            // Default Constructor
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void removePerson();
};
#endif // !NURSE