#include <iostream>
#include "ledger.hpp"

using namespace std;
using std::string;

int return_value;
string ac_account_id[] = {"A00", "A01", "A02", "A03", "A04"};
int    no_of_accounts = 5;
string account_id;

int main()
{
    cout<<"      Welcome ^^"<<endl;

    cout<<"Enter Account ID: ";
    getline(cin, account_id);

    return_value = find_account_index(ac_account_id, no_of_accounts,account_id);
    if(-1 != return_value)
    {
        cout << "Account found at index: " << index << endl;

    }
    else{
        cout << "Invalid ID!!"<<endl;
    }

    return 0;
}