#include <iostream>

using namespace std;

int find_account_index (char *ac_account_id[], int ac_account, char *account_id)
int return_value;
char *ac_account_id[] = {"A00", "A01", "A02", "A03", "A04"};
int no_of_accounts;
string account_id;

int main()
{
    cout<<"      Welcome ^^"<<endl;

    cout<<"Enter Account ID: ";
    getline (cin,account_id);
    return_value = find_account_index(ac_account_id, no_of_accounts,account_id);
    if(!return_value)
    {
        cout << "Done Successful."<<endl;   
    }
    else{
        cout << "Inva"
    }



    return 0;
}