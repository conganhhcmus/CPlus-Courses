#include <iostream>
#include "SavingAccount.h"
#include "BankAccount.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Testing Bank Account
    float depositAmount = 20.00;
    float withdrawAmount = 100.00;
    float defaultBalance = 50.99;
    BankAccount* ba = new BankAccount("1234567890", "Nguyen Van A", defaultBalance);
    ba->Lookup();
    cout << "\n-----Deposit-----" << endl;
    ba->Deposit(depositAmount);
    cout << endl;
    ba->Lookup();
    cout << "\n-----Withdraw-----" << endl;
    ba->Withdraw(withdrawAmount);
    cout << endl;
    ba->Lookup();
    cout << endl;
    delete ba;

    // Testing Saving Account
    depositAmount = 20.00;
    withdrawAmount = 100.00;
    defaultBalance = 100.00;
    float interestRate = 20.00; //20% per year
    int period = 12; // 12 months
    int monthHadBeenDeposited = 25; // 25 months;

    SavingAccount* sa = new SavingAccount("1234567890", "Nguyen Van A", defaultBalance, interestRate, period);
    sa->Lookup();
    cout << "\n-----Update Month Had been deposited-----" << endl;
    sa->UpdateMonth(monthHadBeenDeposited);
    cout << endl;
    sa->Lookup();
    cout << endl;
    cout << "\n-----Deposit-----" << endl;
    sa->Deposit(depositAmount);
    cout << endl;
    sa->Lookup();
    cout << "\n-----Withdraw-----" << endl;
    sa->Withdraw(withdrawAmount);
    cout << endl;
    cout << "\n-----Lookup Balance-----" << endl;
    sa->LookupBalance();
    cout << endl;
    delete sa;

    return 0;
}