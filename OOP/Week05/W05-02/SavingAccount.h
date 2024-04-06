#pragma once
#include "BankAccount.h"
class SavingAccount: BankAccount {
private:
	float _interestRate;
	int _period;
	int _month;

	float CalculateInterestMoney() const;
public:
	SavingAccount();
	SavingAccount(string, string, float, float, int);
	~SavingAccount();
	void UpdateMonth(int);
	void Deposit(float);
	void Withdraw(float);
	void Lookup() const;
	void LookupBalance();
};