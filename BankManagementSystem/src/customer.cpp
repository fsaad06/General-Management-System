//******************  Defining Functions for Customer class   *********************/

#include "./../include/Customer.h"
#include <iomanip>
void customer::create_account() // function to get data from user
{
    cout << "Please verify your Employee id to continue : "; // verifing the employee by ID
    int id;
    cin >> id;
    bool flag = false;
    for (int i = 0; i < 5; i++){
        if (id == idOfEmp[i]) // if employee id entered is correct then , only you can access ahead
        {
            flag = true;
            break;
        }
    }
    if (flag == false)
        cout << "\nPlease enter the correct ID to continue \n";

    else{
        cout << "\nEnter The account No. : "; // steps for creating account
        cin >> accNumber;
        cout << "\n\nEnter The Name of The account Holder : ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "\nEnter Type of The account (C/S) : ";
        cin >> type;
        type = toupper(type);
        cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
        cin >> balance;
        cout << "\n\n\nAccount Created..";
    }
}

void customer::show_account() const // function to show data on screen
{
    cout << "\nAccount No. : " << accNumber;
    cout << "\nAccount Holder Name : ";
    cout << name;
    if (type == 'C')
        cout << "\nType of Account : Credit "
             << "  ";
    else if (type == 'S')
        cout << "\nType of Account : Savings"
             << "  ";
    cout << "\nBalance amount : " << balance << endl;
}

void customer::modify() // function to add new data
{
    cout << "\nPlease verify your Employee id to continue : ";
    int id;
    cin >> id;
    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        if (id == idOfEmp[i])
        {
            flag = true;
            break;
        }
    }
    if (flag == false)
        cout << "\nPlease enter the correct ID to continue \n";
    else
    {
        cout << "\nAccount No. : " << accNumber; // steps for modifying an account
        cout << "\nModify Account Holder Name : ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "\nModify Type of Account : ";
        cin >> type;
        type = toupper(type);
        cout << "\nModify Balance amount : ";
        cin >> balance;
    }
}

void customer::deposit(int x) // function to accept amount and add to balance amount
{
    balance += x;
    cout << "\nUpdated Account Balance is : " << balance << endl;
}

void customer::withdraw(int x) // function to accept amount and subtract from balance amount
{
    balance -= x;
}

void customer::report() const // function to show data
{
    cout << accNumber << setw(5) << " " << name << setw(10) << " " << type << setw(6) << balance << endl;
}

int customer::retAccNumber() const // function to return account number
{
    return accNumber;
}

int customer::retBalance() const // function to return balance amount
{
    return balance;
}

char customer::retAccType() const // function to return type of account
{
    return type;
}