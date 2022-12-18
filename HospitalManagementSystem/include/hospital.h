// Guard Against Multiple Builds
#ifndef HOSPITAL
#define HOSPITAL

// Importing required libraries
#include <string>
#include <vector>
#include <map>

// Including user defined header file
#include "./doctor.h"
#include "./patient.h"
#include "./nurse.h"
#include "./driver.h"
#include "./ambulance.h"
#include "./appointment.h"

// Indicating standard namespace to use
using namespace std;

class hospital
{
private:
    // map<id, object>
    static map<int, doctor> doctorsList;
    static map<int, patient> patientsList;
    static map<int, nurse> nursesList;
    static map<int, driver> driversList;
    static map<int, ambulance> ambulancesList;
    static map<int, appointment> appointmentsList;

    // Variables that can't be changed (Easily)
    static const int doctorsLimit;
    static const int nursesLimit;
    static const int driversLimit;
    static const int ambulancesLimit;
    static const int appointmentsLimit;

     // To access Private Data
    friend class doctor;             
    friend class patient;
    friend class nurse;
    friend class driver;
    friend class ambulance;
    friend class appointment;

public:
    // To access only static data members.
    static void printDoctors();
    static void printPatients();
    static void printNurses();
    static void printDrivers();
    static void printAmbulances();
    static void printAppointments();
};

#endif                  // !HOSPITAL