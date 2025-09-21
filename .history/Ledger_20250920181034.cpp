#include <cstring>
#include "cal.hpp"
#include "ledger.hpp"

//#define MAX_SIZE 5;

using namespace std;


int find_account_index (char *ac_account_id[], int ac_account, char *account_id)
{
    int ret_val = -1;
    for (int index =0; index <ac_account; index++)
    {
        if(!strcmp(ac_account_id[index], account_id))
        {
            ret_val = index;
            cout << "Found successful."<<endl;
            cout << "Account found at index: " << index << endl;
            break;
        }
        else{/*Nothing*/}
    }
    return ret_val;
}

