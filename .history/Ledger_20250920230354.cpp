#include <iostream>
#include "cal.hpp"
#include "ledger.hpp"
#include <cstring>


//#define MAX_SIZE 5;

using namespace std;

/****************** 1. Find Account Index ******************/
int find_account_index(string ac_account_id[], int ac_acount, string ref_account_id)
{
    int ret_val = -1;
    for (int index =0; index <ac_account; index++)
    {
        if(ac_account_id[index] == ref_account_id)
        {
            ret_val = index;
            cout << "Done Successful."<<endl;   
            break;
        }
        else{/*Nothing*/}
    }
    return ret_val;
}

/*************** 2. Get Or Create Account **************/
int get_or_create_account(string ac_account_id[],int ac_balance[],int ac_capacity,int ac_count,string account_id)
{
    int ret_val = 0;

    ret_val = find_account_index(ac_account_id[],ac_count, account_id);
    if(-1 == ret_val) // Account not found!
    {
        if(ac_count < ac_capacity)
        {
            ac_account_id[ac_count] = account_id;
            ac_balance[ac_count]    = 0;
            ret_val = ac_count;
        }

    }

}

