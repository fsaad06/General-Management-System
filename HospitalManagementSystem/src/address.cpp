// Importing required libraries
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

// Including user defined header file
#include "./../include/global.h"
#include "./../include/address.h"

// Default Constructor
address::address()
{
    line1 = "";                     // or can make = NULL
    line2 = "";
    city = "";
    state = "";
    pinCode = "";
    country = "";
}

// setter Function
void address::takeInput()
{
    cout << "\n\t Enter address:";
    cout << "\n\t Line 1:";
    getline(cin >> ws, line1);
    cout << "\n\t Line 2 (optional):";
    getline(cin, line2);
    cout << "\n\t City:";
    getline(cin >> ws, city);
    cout << "\n\t State:";
    getline(cin >> ws, state);
    cout << "\n\t Pin Code:";
    getline(cin >> ws, pinCode);
    cout << "\n\t Country:";
    getline(cin >> ws, country);
    return;
}

// Somehow Getter Function
void address::print()
{
    cout << "\t Line 1: " << line1 << "\n";
    if (line2 != "")
        cout << "                  "
             << "Line 2: " << line2 << "\n";
    cout << "                  ";
    cout << "City: " << city << "\n";
    cout << "                  ";
    cout << "State: " << state << "\n";
    cout << "                  ";
    cout << "Pin Code: " << pinCode << "\n";
    cout << "                  ";
    cout << "Country: " << country << "\n";
    return;
}

// For Storing Data in .csv files
string address::addToStr()
{
    stringstream s;
    s << line1 << "`" << line2 << "`" << city << "`" << state << "`" << pinCode << "`" << country;
    string add;
    getline(s, add);
    for (auto &i : add)
        if (i == ',')
            i = '^';
    return add;
}


void address::strToAdd(string str)
{
    stringstream s(str);
    
    getline(s, line1, '`');
    for (auto &i : line1)
        if (i == '^')
            i = ',';

    getline(s, line2, '`');
    for (auto &i : line2)
        if (i == '^')
            i = ',';

    getline(s, city, '`');
    getline(s, state, '`');
    getline(s, pinCode, '`');
    getline(s, country, '`');
    return;
}