#include <iostream>
#include "cal.hpp"
#include "ledger.hpp"
#include <cstring>


//#define MAX_SIZE 5;

using namespace std;

/****************** 1. Find Account Index ******************/
int find_account_index(string ac_account_id[], int ac_count, string ref_account_id)
{
    int ret_val = -1;
    for (int index =0; index <ac_count; index++)
    {
        if(ac_account_id[index] == ref_account_id)
        {
            ret_val = index;
            //cout << "Done successfully."<<endl;   
            break;
        }
        else{/* Doing Nothing */}
    }
    return ret_val;
}

/*************** 2. Get Or Create Account **************/
int get_or_create_account(string ac_account_id[],int ac_balance[],int ac_capacity,int& ac_count,string account_id)
{
    int ret_val = 0;

    ret_val = find_account_index(ac_account_id,ac_count, account_id);
    if(-1 == ret_val) // Account not found
    {
        if(ac_count < ac_capacity)
        {
            //Create Account & return index
            ac_account_id[ac_count] = account_id; // store New ID 
            ac_balance[ac_count]    = 0;
            ret_val = ac_count;
            ++ac_count;
            cout << "Account created." << endl;
            cout << "Done successfully."<<endl;

        }
        else
        {
            //Can't Create & return -1
            cout << "Error: Capacity Exceeded!" << endl;
        }
    }
    else
    {   //Account Found & return index 
        /* Doing Nothing */
    }
    return ret_val;
}

/*************** 3. Apply One Transaction **************/
void apply_one(string ac_account_id[], int ac_balance[], int ac_capacity, int& ac_count, string account_id,int tx_type,unsigned int amount_cents)
{
    int index   = -1;
    int balance = 0;
    
    index = find_account_index(ac_account_id, ac_count, account_id);
    if(-1 == index)
    { 
        cout << "--> Error!! Account not found!!"<< endl;
    }
    else
    {
        balance = ac_balance[index];

        switch(tx_type)
        {
            // Take alance from user
            case 0: /** Deposit **/
            case 4: /** TransferIn **/
                balance = apply_deposit(balance, amount_cents);
            break;

            case 1: /** Withdrawal **/
            case 5: /** TransferOut **/
                balance = apply_withdrawal(balance, amount_cents);
            break;

            case 2: /** Fee **/
                balance = apply_fee(balance, (int)amount_cents);
            break;

            case 3: /** Interest --> "Simple Intreset"  **/
            {
                int interest_amount = 0; 
                int  days, day_count_basis = 0;
                float apr = 0;
                char rounding_policy = 'U';

                cout << "Enter annual rate ";
                cin >> apr;
                cout << "Enter days to accure ";
                cin >> days;
                cout << "Enter day count basis (360 or 365) ";
                cin >> day_count_basis;
                cout << "Rounding policy\n";
                cout << "Press 'U' for Half Up or 'E' for Half Even ";
                cin >> rounding_policy;

                interest_amount = simple_interest(balance, apr, days, day_count_basis, rounding_policy);
                balance += interest_amount;
                cout << "---------------------------------\n";
                cout << "Simple Interest Result: " << interest_amount << " cents\n";
            break;
            }
                
            default: 
                cout << "Invalid operation!\n";
            break;
        }

        // Saving the new balance
        ac_balance[index] = balance;
        std::cout << "---------------------------------\n";
        cout << "Operation done."<<std::endl;
        cout << "New balance = " << ac_balance[index] <<" cents.\n" <<std::endl;
        cout << "---------------------------------\n";
    }
}
void apply_one( int , int ac_capacity, int& ac_count, string account_id,int tx_type,unsigned int amount_cents)
/*************** 3. Apply One Transaction **************/
void apply_all(string tx_account_id[], int tx_type[],int tx_amount_cents, int tx_count, string account_id,ac_balance, ac_capacity, ac_count

