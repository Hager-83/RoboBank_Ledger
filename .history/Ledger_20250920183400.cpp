#include <iostream>
#include "cal.hpp"
#include "ledger.hpp"
#include <cstring>


//#define MAX_SIZE 5;

using namespace std;


int find_account_index(char *ac_account_id[], int ac_account, char *refaccount_id)
{
    int ret_val = -1;
    for (int index =0; index <ac_account; index++)
    {
        if(!(strcmp(ac_account_id[index], account_id)))
        {
            ret_val = index;
            cout << "Account found at index: " << index << endl;
            break;
        }
        else{/*Nothing*/}
    }
    return ret_val;
}




int find_account_index(string ac_account_id[], int ac_account, string& ref_account_id)
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

