#pragma once
#include "string"
#include "BankAccount.h"

using namespace std;

class BankAccountV2 : public BankAccount {
private:
	int _minBalance;
public:
	BankAccountV2();
	BankAccountV2(string name, int balance);
	BankAccountV2(BankAccount account);
	int withdraw(int amount);

};