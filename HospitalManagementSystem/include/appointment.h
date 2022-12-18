// Guard Against Multiple Builds
#ifndef APPOINTMENT
#define APPOINTMENT

//indicating standard namespace to use
using namespace std;

// Including user defined header file
#include "./patient.h"
#include "./doctor.h"

class appointment
{
private:
    int id;
    doctor D;
    patient P;
    int hh;                             // hh -> start hour in 24 hour format;
public:
    appointment();                      // Default Constructor
    ~appointment();                     // User-Defined Destructor
    void fillMap();
    void saveMap();
    void printDetails();
    void book();
    void fillDetails();
    void getDetails();
};
#endif                                   // !APPOINTMENT