#include <iostream>
#include "cal.hpp"
#include "ledger.hpp"

using namespace std;
using std::string;

int operation = 0;

int return_value;

const int ac_capacity = 10;
string    ac_account_id[ac_capacity] = {"A00", "A01", "A02", "A03", "A04"}, account_id;
int       no_of_accounts = 5;

int ac_balance[ac_capacity] = {5000, 1500, 3000, -700, 0};

int amount, tx_type;

int tx_count = 3;

int main()
{
    while(true)
    {
        cout<<"\n\n------------------------------------------------"<<endl;
        cout << "                 Welcome ^^"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout << "\nPlease choose your operation:  "<<endl;
        cout << "press [1] to Find Account."<<endl;
        cout << "press [2] to Get Or Create Account."<<endl;
        cout << "press [3] to Apply One."<<endl;
        cout << "press [4] to Apply All."<<endl;
        cout << "press [5] to Balance Of."<<endl;
        cout << "press [6] to Bank Summary."<<endl;
        cout << "press [0] for EXIT.\n"<<endl;
        cout << "Enter Your choice: ";
        cin  >> operation;

        if(!operation)
        {
            cout << "\nGoodbye^^ "<<endl;
            cout << "--EXIT--\n"<<endl;
            break;
        }

        switch(operation)
        {
            case 1: /** Find Account Index */
                cout << "\n--> Finding  Account."<<endl;
                cout<<"\nEnter Account ID: ";
                cin.ignore();
                getline(cin, account_id);

                return_value = find_account_index(ac_account_id, no_of_accounts,account_id);
                if(-1 != return_value)
                {
                     cout << "Done successfully."<<endl;
                     cout << "Account found at index: " << return_value << endl;
                }
                else{
                     cout << "--> Invalid ID!!"<<endl;
                     cout << "Account not found!"<<endl;
                }
            break;

            case 2: /** Get Or Create Account **/
                cout << "\n--> Get Or Create Account."<<endl;
                cout<<"\nEnter Account ID: ";
                cin.ignore();
                getline(cin, account_id);

                return_value = get_or_create_account(ac_account_id, ac_balance, ac_capacity, no_of_accounts, account_id);
                if(-1 != return_value)
                {
                    cout << "Done successfully."<<endl;
                    cout << "Account found at index: " << return_value << endl;
                    cout << "Total accounts now: " << no_of_accounts << endl;
                }
                else{/* Doing Nothing */}
            break;

            case 3: /** Apply One Transaction  **/
                cout << "\n--> Apply One Transaction."<<endl;
                cout<<"\nEnter Account ID: ";
                cin.ignore();
                getline(cin, account_id);
                cout << "Choose transaction: "<< endl;
                cout << "press [0] for Apply deposit."<<endl;
                cout << "press [1] for apply withdrawal."<<endl;
                cout << "press [2] for apply fee."<<endl;
                cout << "press [3] for Interest."<<endl;
                cout << "press [4] for TransferIn."<<endl;
                cout << "press [5] for TransferOut."<<endl;
                cout <<"Your choice: ";
                //cin.ignore();
                cin >> tx_type;
                if(3 != tx_type)
                {
                    cout<< "Enter amount in cents: ";
                    cin.ignore();
                    cin >> amount;
                }
                apply_one(ac_account_id,ac_balance, ac_capacity, no_of_accounts, account_id, tx_type, amount);
            break;

            case 4: /** Apply All Transactions  **/
            {
                cout << "\nApplying all transactions...\n";
                cout << "\n--> Apply All Transactions."<<endl;
                cout << "Enter nember of Transactions: ";
                cin >> tx_count;
                string tx_account_id[tx_count];
                int    tx_type[tx_count];          
                int    tx_amount_cents[tx_count];

                for (auto i =0; i<tx_count; i++)
                {
                    cout << "\nTransaction " << i + 1 << ":\n";

                    cout << "  --> Enter account ID: ";
                    cin >> tx_account_id[i];

                    cout << "  --> Enter transaction type (0=Deposit, 1=Withdrawal, 2=Fee, 3=Interest, 4=TransferIn, 5=TransferOut): ";
                    cin >> tx_type[i];

                    cout << "  --> Enter transaction amount in cents: ";
                    cin >> tx_amount_cents[i];
                }
                    apply_all(tx_account_id, tx_type, tx_amount_cents, tx_count,ac_account_id, ac_balance, ac_capacity, no_of_accounts);

                for (auto i =0; i<tx_count; i++)
                {
                    cout << i+1 << ") Account " << tx_account_id[i] << " | Type " << tx_type[i]
                    << " | Amount " << tx_amount_cents[i] << " cents\n";
                }
            }
            break;

            case 5: /** Balance of **/
                cout << "\n--> Balance of Account."<<endl;
                cout<<"\nEnter Account ID: ";
                cin.ignore();
                getline(cin, account_id);
                return_value = balance_of(ac_account_id, ac_balance, no_of_accounts, account_id);
                if(return_value)
                {
                    cout << "Account ["<<account_id<<"] Balance = "<< return_value << endl;
                }
                else{/* Nothing */}
            break;

            case 6: /** Bank summary **/
                cout << "\n--> Bank Summary."<<endl;
                bank_summary(no_of_accounts, ac_balance);
                
            break;
            default:
                cout<<"--> Invalid Operation!!";
            break;
        }
    }
    return 0;   
}