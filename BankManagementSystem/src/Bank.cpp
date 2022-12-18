//******************  Defining Functions for Bank class   *********************/

#include "./../include/Bank.h"
Bank::Bank() {}                               // Default Constructor : Just For Flexibility
    
Bank::Bank(string name, string branch){       // Parametrized Constructor
    Bank_name = name;
    Bank_branch = branch;
}

void Bank:: showBankDetails(){                
    cout << "\n \t Name of the Bank is : " << Bank_name;
    cout << "\n \t Branch is : " << Bank_branch << endl;
}