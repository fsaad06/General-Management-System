//******************  Defining Functions for employee class   *********************/

#include "./../include/Employee.h"
#include <fstream>
void employee :: showEmpId(){
        cout << "Employee ID : " << emp_id << endl;
    }
void employee::write_account() // function to write in file
{
    customer ac;      // creating an customer class object
    ofstream outFile; // object of ofstream to write data into an file named "account.dat"
    outFile.open("account.dat", ios::binary | ios::app);
    ac.create_account();                                            // calling the create account function for creating an account
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(customer)); // wrinting data
    outFile.close();
}

void employee::display_sp(int n) //    	function to read specific record from file
{
    customer ac;
    bool flag = false;
    ifstream inFile; // object of ifstream to read data from a file named "account.dat"
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\nBALANCE DETAILS\n";

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(customer)))
    {
        if (ac.retAccNumber() == n)
        {
            ac.show_account(); // calling the show_account function for showing details of an account
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nNo Account with this Account number exists , \n please enter the correct details and try again";
}

void employee::modify_account(int n) //    	function to modify record of file
{
    bool found = false;
    customer ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(customer)); // calling all functions needed to modify an account
        if (ac.retAccNumber() == n)
        {
            ac.show_account();
            cout << "\n\nEnter The New Details of account" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(customer));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(customer));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}

void employee::delete_account(int n) //    	function to delete record of file
{
    cout << "Please verify your Employee id to continue : ";
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
        customer ac;
        ifstream inFile;
        ofstream outFile;
        inFile.open("account.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            return;
        }
        outFile.open("Temp.dat", ios::binary); // steps for deleting the data of an particular account
        inFile.seekg(0, ios::beg);
        while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(customer)))
        {
            if (ac.retAccNumber() != n)
            {
                outFile.write(reinterpret_cast<char *>(&ac), sizeof(customer));
            }
        }
        inFile.close();
        outFile.close();
        remove("account.dat");
        rename("Temp.dat", "account.dat"); // removing data from the file itself
        cout << "\n\n\tRecord Deleted ..";
    }
}

void employee::display_all() //    	function to display all accounts deposit list
{
    customer ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "========================================================\n";
    cout << "A/c no.          NAME         Type       Balance\n";
    cout << "========================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(customer)))
    {
        ac.report(); // calling the report function for showing details of all accounts
        cout << endl;
    }
    inFile.close();
}

void employee::deposit_withdraw(int n, int option) //    	function to deposit and withdraw amounts
{
    int amt;
    bool found = false;
    customer ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(customer));
        if (ac.retAccNumber() == n)
        {
            ac.show_account();
            if (option == 1)
            {
                cout << "\n\n\tTO DEPOSITE AMOUNT ";
                cout << "\n\nEnter The amount to be deposited : ";
                cin >> amt;
                ac.deposit(amt); // calling deposit func. for depositing an given amount
                cin.get();
            }
            if (option == 2)
            {
                cout << "\n\n\tTO WITHDRAW AMOUNT ";
                cout << "\n\nEnter The amount to be withdraw : ";
                cin >> amt;
                int bal = ac.retBalance() - amt;
                if ((bal < 500 && ac.retAccType() == 'S') || (bal < 1000 && ac.retAccType() == 'C'))
                    cout << "Insufficience balance\n";
                else
                    ac.withdraw(amt); // calling withdraw func. for withdrawing an given amount
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(customer));
            cout << "\n\n\t Record Updated\n";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found \n";
        return;
}