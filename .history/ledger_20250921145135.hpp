#ifndef _LEDGER_HPP_
#define _LEDGER_HPP_

#include <cstring>
using std::string;



//#define MAX_SIZE 5;

/****************** 1. Find Account Index ******************/
int find_account_index(string *ac_account_id, int ac_acount, string account_id);

/*************** 2. Get Or Create Account *****************/
int get_or_create_account(string *ac_account_id,int *ac_balance,int ac_capacity,int& ac_count,string account_id);

/*************** 3. Apply One Transaction ****************/
void apply_one(string *ac_account_id, int *ac_balance, int ac_capacity, int& ac_count, string account_id,int tx_type,unsigned int amount_cents);

/*************** 4. Apply All Transactions ***************/
void apply_all(string *tx_account_id, int *tx_type,int *tx_amount_cents, int tx_count, string *ac_account_id,int *ac_balance,int ac_capacity,int& ac_count);

/********************* 5.Balance of  ********************/
int balance_of(string *ac_account_id, int *ac_balance, int ac_count,string account_id);

/********************* 6.Bank Summary ******************/
void bank_summary(int ac_count, int ac_balance[]);

#endif /*_LEDGER_HPP_*/