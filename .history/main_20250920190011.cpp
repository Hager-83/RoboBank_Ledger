#include <iostream>
#include "ledger.hpp"

using namespace std;
using std::string;

int operation = 0;

int return_value;
string ac_account_id[] = {"A00", "A01", "A02", "A03", "A04"}, account_id;
int    no_of_accounts = 5;

int main()
{
    while(true)
    {
        cout<<"\n\n------------------------------------------------"<<endl;
        cout << "                 Welcome ^^"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout << "Please choose your operation:  "<<endl;
        cout << "press [1] to Find Account."<<endl;
        cout << "press [2] to Get Or Create Account."<<endl;
        cout << "press [3] to Apply One."<<endl;
        cout << "press [4] to Apply All."<<endl;
        cout << "press [5] to Balance Of."<<endl;
        cout << "press [6] to Bank Summary."<<endl;
        cout << "press [0] for EXIT."<<endl;
        cout << "Enter Your choice: ";
        cin  >> operation;

        if(!operation)
        {
            cout << "Goodbye^^ "<<endl;
            cout << "--EXIT--"<<endl;
            break;
        }

        switch(operation)
        {
            case 1: /** Find Account Index */
                cout<<"Enter Account ID: ";
                cin.ignore();
                getline(cin, account_id);

                return_value = find_account_index(ac_account_id, no_of_accounts,account_id);
                if(-1 != return_value)
                {
                     cout << "Account found at index: " << return_value << endl;
                }
                else{
                     cout << "Invalid ID!!"<<endl;
                }
            break;

            case 2:

            break;



            default:
                cout<<"Invalid Operation!!";
            break;

        }

    

    

    }
    return 0;
    
}