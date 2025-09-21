#include <cstring>
#include "cal.hpp"
#include "ledger.hpp"

using namespace std;


int find_account_index (char *ac_account_id[], int ac_account, char account_id)
{
    int ret_val = -1;
    for (int index =0; index <ac_account, index++)
    {
        if(strcmp(*ac_account_id[i], account_id)==0)
        {
            ret_val = i;
            return ret_val;

        }
    }
    return ret_val;
}

