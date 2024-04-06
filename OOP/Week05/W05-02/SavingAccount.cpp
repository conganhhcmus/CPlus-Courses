#include "SavingAccount.h"

SavingAccount::SavingAccount(): BankAccount() {
	_interestRate = 0;
	_period = 0;
	_month = 0;
}

SavingAccount::SavingAccount(string id, string fullName, float balance, float interestRate, int period) : BankAccount(id, fullName, balance) {
	_interestRate = interestRate;
	_period = period;
	_month = 0;
}

SavingAccount::~SavingAccount() {}

void SavingAccount::UpdateMonth(int month) {
	if (month <= _month) {
		cout << "Update month that had been deposited failed because the month input is smaller than this." << endl;
		return;
	}

	_month = month;
	cout << "Update month to " << month << " successful" << endl;
}

void SavingAccount::Deposit(float amount) {
	if (_month < _period) {
		cout << "Deposit failed because month that had been deposited is smaller period." << endl;
		return;
	}

	_balance += CalculateInterestMoney();
	_balance += amount;
	_month = 0;
	cout << "Deposit " << amount << " successful." << endl;
}

void SavingAccount::Withdraw(float amount) {
	if (_month < _period) {
		cout << "Withdraw failed because month that had been deposited is smaller period." << endl;
		return;
	}

	_balance += CalculateInterestMoney();
	_balance -= amount;
	_month = 0;
	cout << "Withdraw " << amount << " successful." << endl;
}

void SavingAccount::Lookup() const {
	cout << "----- Saving Account Info -----" << endl;
	cout << "ID: " << _id << endl;
	cout << "FullName: " << _fullName << endl;
	cout << "Balance: " << _balance << endl;
	cout << "Interest: " << _interestRate << "%" << endl;
	cout << "Period: " << _period << " month(s)" << endl;
	cout << "Month : " << _month << " month(s) that had been deposited" << endl;
}

void SavingAccount::LookupBalance() {
	float balance = _balance + CalculateInterestMoney();
	cout << "----- Saving Account Info -----" << endl;
	cout << "ID: " << _id << endl;
	cout << "FullName: " << _fullName << endl;
	cout << "Balance: " << balance << endl;
	cout << "Interest: " << _interestRate << "%" << endl;
	cout << "Period: " << _period << " month(s)" << endl;
	cout << "Month : " << _month << " month(s) that had been deposited" << endl;
}

float SavingAccount::CalculateInterestMoney() const {
	// Note: The remaining months will default to no interest.
	float interestMoney = 0;
	for (int i = 0; i < (_month / _period); i++) {
		interestMoney += (_balance + interestMoney) * (_interestRate / 100);
	}

	return interestMoney;
}