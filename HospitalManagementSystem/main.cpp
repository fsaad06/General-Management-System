// Importing Required Libraries 
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <sstream>
#include <stdio.h>
#include <ios>                   // used to get stream size
#include <limits>                // used to get numeric limits

//indicating standard namespace to use
using namespace std;
#pragma warning(disable:4996)

// Including user defined header file
#include "./include/global.h"
#include "./include/hospital.h"
#include "./include/address.h"
#include "./include/person.h"
#include "./include/appointment.h"
#include "./include/patient.h"
#include "./include/doctor.h"
#include "./include/nurse.h"
#include "./include/driver.h"
#include "./include/ambulance.h"

// ProtoTyping Functions, to be used here
void appointmentsMenu();
void patientsMenu();
void doctorsMenu();
void nursesMenu();
void driversMenu();
void ambulancesMenu();

// Functions to be used for Front-End
void initial_setup();
void tab(int nums);
void line(int nums);
void position(int x, int y);
void print_text(int lines, int tabs, string text);
void print_heading();

int main()
{
    fstream f;
    f.open("./data/appointments.csv", ios::in);
    string temp, s, header;
    getline(f, header);
    getline(f, temp);
    f.close();
    stringstream str(temp);
    getline(str, s, ',');
    getline(str, s, ',');
    initial_setup();
    print_heading();
    int dd, mm, yyyy;
    if (s != ""){
        print_text(1, 5,"\n\n\nLast usage date (DD-MM-YYYY) : ") ;
        cout << s.substr(6, 2) + "-" + s.substr(4, 2) + "-" + s.substr(0, 4) + "\n";
    }
    print_text(1, 5, "Please Enter Today's Date (DD-MM-YYYY) \n\n ");
    print_text(1, 5, "  Enter Day: ");
    cin >> dd;
    while (dd < 1 || dd > 31)
    {
        print_text(1, 5,"Invalid Day! Please enter a valid day: ");
        cin >> dd;
    }
    print_text(1, 5,"  Enter Month: ");
    cin >> mm;
    while (mm < 1 || mm > 12)
    {
        print_text(1, 5, "Invalid Month! Please enter a valid month: ");
        cin >> mm;
    }
    print_text(1, 5, "  Enter Year (YYYY): ");
    cin >> yyyy;
    yyyymmdd = yyyy * 10000 + mm * 100 + dd;
    if (stoi(((s == "") ? ("0") : (s))) < yyyymmdd)
    {
        f.open("./data/temp.csv", ios::out);
        f << header << "\n";
        f.close();
        remove("./data/appointments.csv");
        rename("./data/temp.csv", "./data/appointments.csv");
        fstream fout("./data/temp.csv", ios::out);
        f.open("./data/doctors.csv", ios::in);
        getline(f, temp);
        fout << temp << endl;
        while (getline(f, temp))
        {
            if (temp.size())
                temp[temp.size() - 1] = '0';
            fout << temp << endl;
        }
        f.close();
        fout.close();
        remove("./data/doctors.csv");
        rename("./data/temp.csv", "./data/doctors.csv");
    }
    else if (stoi(s) > yyyymmdd && s != "")
    {
        print_text(1, 5,"Entered date detected wrong!");
        print_text(1, 5,"Today's date can't be older than the last usage date, which is :");
        cout << s.substr(6, 2) + "-" + s.substr(4, 2) + "-" + s.substr(0, 4) + "\n";
        return 0;
    }
    // filling maps with data from csv files;
    {
        doctor d1;
        patient p;
        nurse n;
        driver d2;
        ambulance a1;
        appointment a2;
        d1.fillMap();
        p.fillMap();
        n.fillMap();
        d2.fillMap();
        a1.fillMap();
        a2.fillMap();
        // NOTE:
        // fill drivers' Map before ambulances' Map;
        // fill doctors' and patients' Map before appointments' Map;
    }
    while (1)
    {
        system("cls");
        int category = 0;
        print_text(1, 5,"------------------------------------------------------------");
        print_text(1, 5,"Select a category \n");
        print_text(1, 5, "---------------");
        print_text(1, 5,"./HOME");
        print_text(1, 5, "---------------");
        print_text(1, 5, "[01] : APPOINTMENTS\n");
        print_text(1, 5, "[02] : PATIENTS\n");
        print_text(1, 5, "[03] : DOCTORS\n");
        print_text(1, 5, "[04] : NURSES\n");
        print_text(1, 5, "[05] : DRIVERS\n");
        print_text(1, 5, "[06] : AMBULANCES\n");
        print_text(1, 5, "[-1] : EXIT\n");
        print_text(1, 5, "-----------------------------------------------------------\n");
        print_text(1, 5, "Enter your choice: ");
        cin >> category;
        cout << endl;
        print_text(1, 5, "------------------------------------------------------------\n");
        cout << "\n";
        if (category == -1)
        {
            print_text(1, 5,"--------------------------------------------------------------------------------\n");
            print_text(1, 5,"Shutting Down System...\n");
            print_text(1, 5,"--------------------------------------------------------------------------------~\n");
            break;
        }
        else if (category == 1) {
            appointmentsMenu();
        }

        else if (category == 2) {
            patientsMenu();
        }

        else if (category == 3){
            doctorsMenu();
        }

        else if (category == 4){
            nursesMenu();
        }

        else if (category == 5){
            driversMenu();
        }

        else if (category == 6){
            ambulancesMenu();
        }

        else{
            print_text(1, 5,"Invalid Choice!\n");
        }

        cout << endl;
    }
    // saving data inside maps by overwriting it on the files
    {
        doctor d1;
        patient p;
        nurse n;
        driver d2;
        ambulance a1;
        appointment a2;
        d1.saveMap();
        p.saveMap();
        n.saveMap();
        d2.saveMap();
        a1.saveMap();
        a2.saveMap();
    }

    return 0;
}

// Setting Colour
void initial_setup(){
	system("color 0C");
}

// Adding any number of tabs
void tab(int nums)
{
	for (int i = 0; i < nums; i++)       // Option 02: for (int i : Range)
	{
		cout << "\t";
	}
}

//Adding any number of newlines
void line(int nums)
{
	for (int i = 0; i < nums; i++)
	{
		cout << "\n";
	}
}

//Setting position of cursor on console
void position(int x, int y)
{
	HANDLE Screen;
	Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position_value = { (short)x,(short)y };
	SetConsoleCursorPosition(Screen, position_value);
}

//Custom function for formatted text
void print_text(int lines, int tabs, string text)
{
	line(lines);
	tab(tabs);
	cout << text;
}

// Setting Heading
void print_heading(){
	system("cls");

	for (int x1 = 0; x1 < 120; x1++)
	{
		position(x1, 2);
		printf("%c", 219);
	}
	position(42, 4);
	print_text(0, 0, "Hospital Management System");

	for (int x2 = 0; x2 < 120; x2++)
	{
		position(x2, 6);
		printf("%c", 219);
	}
	line(2);
}


void appointmentsMenu()
{
    bool exit = false;
    while (!exit)
    {
        system("cls");
        int purpose = 0;
        cout << "\n \n";
        print_text(1, 5,"Select an option:\n\n");

        print_text(1, 5, "--------------------------------");
        print_text(1, 5, "./HOME/APPOINTMENTS");
        print_text(1, 5, "--------------------------------\n");
        print_text(1, 5, "[01] : Book an appointment\n");
        print_text(1, 5, "[02] : Get appointment details\n");
        print_text(1, 5, "[03] : Show all appointments\n\n");
        print_text(1, 5, "[-1] : Back\n");
        print_text(1, 5, "--------------------------------- \n \n");
        print_text(1, 5,"Enter your choice: ");
        cin >> purpose;

        if (purpose == 1){
            appointment a;
            a.book();
        }

        else if (purpose == 2){
            appointment a;
            a.getDetails();
            a.printDetails();
        }

        else if (purpose == 3){
            hospital::printAppointments();
        }

        else if (purpose == -1){
            exit = true;
            break;
        }

        else{
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        print_text(1, 5,"Press ENTER to continue...\n");
        cout << endl;

        getchar();
    }
    return;
}

void patientsMenu()
{
    system("cls");
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << endl << endl;
        print_text(1, 5,"Select an option:\n\n");

        print_text(1, 5,"-----------------------------\n");
        print_text(1, 5,"./HOME/PATIENTS");
        print_text(1, 5,"-----------------------------\n");
        print_text(1, 5,"[01] : Register a new patient\n");
        print_text(1, 5,"[02] : Get patient details\n");
        print_text(1, 5,"[03] : Hospitalize a registered patient\n");
        print_text(1, 5,"[04] : Report a patient's death\n");
        print_text(1, 5,"[05] : Discharge a patient or their body\n");
        print_text(1, 5,"[06] : Fetch patient details from history\n");
        print_text(1, 5,"[07] : Get details of all registered patients\n\n");
        print_text(1, 5,"[-1] : Back\n");
        print_text(1, 5,"-----------------------------\n\n");
        print_text(1, 5,"Enter your choice: ");
        cin >> purpose;

        if (purpose == 1){
            patient p;
            p.addPerson();
        }

        else if (purpose == 2){
            patient p;
            p.getDetails(1);
            p.printDetails();
        }

        else if (purpose == 3){
            patient p;
            p.hospitalize();
        }

        else if (purpose == 4){
            patient p;
            p.reportADeath();
        }

        else if (purpose == 5){
            patient p;
            p.removePerson();
        }

        else if (purpose == 6){
            patient p;
            p.getDetailsFromHistory();
        }

        else if (purpose == 7){
            hospital::printPatients();
        }

        else if (purpose == -1){
            exit = true;
            break;
        }

        else{
            print_text(1, 5,"Invalid choice!\n");
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        print_text(1, 5,"Press ENTER to continue...\n");
        cout << endl;

        getchar();
    }
    return;
}

void doctorsMenu()
{
    system("cls");
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << endl << endl << endl;
        print_text(1, 5,"Select an option:\n");

        print_text(1, 5, "---------------------------\n");
        print_text(1, 5,"./HOME/DOCTORS");
        print_text(1, 5, "---------------------------\n");
        print_text(1, 5, "[01] : Register a new doctor\n");
        print_text(1, 5, "[02] : Get doctor details\n");
        print_text(1, 5, "[03] : Remove a doctor\n");
        print_text(1, 5, "[04] : Fetch doctor details from history\n");
        print_text(1, 5, "[05] : Get details of all registered doctors\n");
        print_text(1, 5, "[-1] : Back\n");
        print_text(1, 5, "---------------------------\n\n");
        print_text(1, 5, "Enter your choice: ");
        cin >> purpose;

        if (purpose == 1){
            doctor d;
            d.addPerson();
        }

        else if (purpose == 2){
            doctor d;
            d.getDetails(1);
            d.printDetails();
        }

        else if (purpose == 3){
            doctor d;
            d.removePerson();
        }

        else if (purpose == 4){
            doctor d;
            d.getDetailsFromHistory();
        }

        else if (purpose == 5){
            hospital::printDoctors();
        }

        else if (purpose == -1){
            exit = true;
            break;
        }

        else{
            print_text(1, 5, "Invalid choice!\n");
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        print_text(1, 5,"Press ENTER to continue...\n");
        cout << endl;

        getchar();
    }
    return;
}

void nursesMenu()
{
    system("cls");
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << endl << endl;
        print_text(1, 5, "Select an option:\n");

        print_text(1, 5,"----------------------------\n");
        print_text(1, 5,"./HOME/NURSES");
        print_text(1, 5, "----------------------------\n");
        print_text(1, 5, "[01] : Register a new nurse\n");
        print_text(1, 5, "[02] : Get nurse details\n");
        print_text(1, 5, "[03] : Remove a nurse\n");
        print_text(1, 5, "[04] : Fetch nurse details from history\n");
        print_text(1, 5, "[05] : Get details of all registered nurses\n\n");
        print_text(1, 5, "[-1] : Back\n");
        print_text(1, 5, "----------------------------\n");
        print_text(1, 5, "Enter your choice: ");
        cin >> purpose;

        if (purpose == 1){
            nurse n;
            n.addPerson();
        }

        else if (purpose == 2){
            nurse n;
            n.getDetails(1);
            n.printDetails();
        }

        else if (purpose == 3){
            nurse n;
            n.removePerson();
        }

        else if (purpose == 4){
            nurse n;
            n.getDetailsFromHistory();
        }
        else if (purpose == 5){
            hospital::printNurses();
        }

        else if (purpose == -1){
            exit = true;
            break;
        }

        else{
            print_text(1, 5,"Invalid choice!\n");
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        print_text(1, 5,"Press ENTER to continue...\n");
        cout << endl;

        getchar();
    }
    return;
}

void driversMenu()
{
    system("cls");
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << endl << endl;
        print_text(1, 5, "Select an option:\n");

        print_text(1, 5,"----------------------------\n");
        print_text(1, 5,"./HOME/DRIVERS");
        print_text(1, 5, "----------------------------\n");
        print_text(1, 5, "[01] : Register a new driver\n");
        print_text(1, 5, "[02] : Get driver details\n");
        print_text(1, 5, "[03] : Remove a driver\n");
        print_text(1, 5, "[04] : Fetch driver details from history\n");
        print_text(1, 5, "[05] : Get details of all registered drivers\n");
        print_text(1, 5, "[-1] : Back\n");
        print_text(1, 5, "----------------------------\n\n");
        print_text(1, 5, "Enter your choice: ");
        cin >> purpose;

        if (purpose == 1){
            driver d;
            d.addPerson();
        }

        else if (purpose == 2){
            driver d;
            d.getDetails(1);
            d.printDetails();
        }

        else if (purpose == 3){
            driver d;
            d.removePerson();
        }

        else if (purpose == 4){
            driver d;
            d.getDetailsFromHistory();
        }

        else if (purpose == 5){
            hospital::printDrivers();
        }

        else if (purpose == -1){
            exit = true;
            break;
        }

        else{
            print_text(1, 5,"Invalid choice!\n");
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        print_text(1, 5, "Press ENTER to continue...\n");
        cout << endl;

        getchar();
    }
    return;
}

void ambulancesMenu()
{
    system("cls");
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << endl << endl;
        print_text(1, 5,"Select an option:\n\n");

        print_text(1, 5,"----------------------------\n");
        print_text(1, 5, "./HOME/AMBULANCES");
        print_text(1, 5, "----------------------------\n");
        print_text(1, 5, "[01] : Add an ambulance\n");
        print_text(1, 5, "[02] : Send an ambulance\n");
        print_text(1, 5, "[03] : Get ambulance details\n");
        print_text(1, 5, "[04] : Report ambulance arrival\n");
        print_text(1, 5, "[05] : Remove an ambulance\n");
        print_text(1, 5, "[06] : Fetch ambulance details from history\n");
        print_text(1, 5, "[07] : Get details of all registered ambulances\n");
        print_text(1, 5, "[-1] : Back\n");
        print_text(1, 5, "----------------------------\n");
        print_text(1, 5, "Enter your choice: ");
        cin >> purpose;

        if (purpose == 1){
            ambulance a;
            a.addAmbulance();
        }

        else if (purpose == 2){
            ambulance a;
            a.send();
        }

        else if (purpose == 3){
            ambulance a;
            a.getDetails(1);
            a.printDetails();
        }

        else if (purpose == 4){
            ambulance a;
            a.reportArrival();
        }

        else if (purpose == 5){
            ambulance a;
            a.removeAmbulance();
        }

        else if (purpose == 6){
            ambulance a;
            a.getDetailsFromHistory();
        }

        else if (purpose == 7){
            hospital::printAmbulances();
        }

        else if (purpose == -1){
            exit = true;
            break;
        }

        else{
            print_text(1, 5, "Invalid choice!\n");
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        print_text(1, 5, "Press ENTER to continue...\n");
        cout << endl;

        getchar();
    }
    return;
}