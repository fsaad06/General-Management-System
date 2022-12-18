// Importing required libraries
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

// Including user defined header file
#include "./../include/global.h"
#include "./../include/person.h"


// Default Constructor
person::person()
{
    id = -1;
}
void person::addPerson(int16_t minAge, int16_t maxAge)
{
    // getting basic details of the person from the user side;
    cout << "\n\tEnter name: \n\tFirst name:";
    getline(cin >> ws, firstName);
    cout << "\n\tLast name:";
    getline(cin, lastName);

    cout << "\nEnter age: ";
    cin >> age;
    while (age <= 0)
        cout << "\tWas that supposed to make any kind of sense?\nEnter again!\n", cin >> age;
    if (category != 2)
    {
        if (age < minAge)
            return void(cout << "\t😢 Sorry, person should be at least " << minAge << " years old to be registered as a " << cat << ".\n");
        else if (age > maxAge)
            return void(cout << "\t😢 Sorry, we can't register a person older than " << maxAge << " years as a " << cat << ".\n");
    }

    cout << "\n\tGender (M = Male || F = Female): \n";
    cin >> gender;
    while (gender != 'M' && gender != 'F')
        cout << "\tM or F?\n", cin >> gender;
    cout << "\n\tEnter mobile number (with country code): \n";
    getline(cin >> ws, mobNumber);
    add.takeInput();
    return;
}

void person::printDetails()
{
    if (id == -1)
        return;
    cout << "\n\t Details:\n";
    cout << "\t ID              : " << id << "\n";
    cout << "\t Full Name       : " << firstName << " " << lastName << "\n";
    cout << "\t Gender          : " << gender << "\n";
    cout << "\t Age             : " << age << "\n";
    cout << "\t Mobile          : " << mobNumber << "\n";
    cout << "\t Address         : ";
    add.print();
    return;
}

// Retrieving Data From .csv File
void person::printDetailsFromHistory()
{
    if (id == -1)
        return;
    cout << "\n \tHistory Details :\n";
    cout << "\t Full Name       : " << firstName << " " << lastName << "\n";
    cout << "\t Gender          : " << gender << "\n";
    cout << "\t Age             : " << age << "\n";
    cout << "\t Mobile          : " << mobNumber << "\n";
    cout << "\t Address         : ";
    add.print();
    return;
}