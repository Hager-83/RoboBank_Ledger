#ifndef _LEDGER_HPP_
#define _LEDGER_HPP_

#include <cstring>
using std::string;



//#define MAX_SIZE 5;

/****************** 1. Find Account Index ******************/
int find_account_index(string ac_account_id[], int ac_acount, string ref_account_id);

/*************** 2. Get Or Create Account **************/
int get_or_create_account(string ac_account_id[],int ac_balance[],int ac_capacity,int ac_count,string account_id);


#endif /*_LEDGER_HPP_*/