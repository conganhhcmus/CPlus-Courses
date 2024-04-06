#include "BankAccount.h"

BankAccount::BankAccount() {
	_balance = 0;
	_id = "";
	_fullName = "";
}

BankAccount::BankAccount(string id, string fullName, float balance) {
	_id = id;
	_fullName = fullName;
	_balance = balance;
}

BankAccount::~BankAccount() {}

void BankAccount::Deposit(float amount) {
	if (amount <= 0) {
		cout << "Amount is invalid!" << endl;
		return;
	}
	_balance += amount;
	cout << "Deposit " << amount << " successful." << endl;
}

void BankAccount::Withdraw(float amount) {
	if (amount <= 0 || amount > _balance) {
		cout << "Amount is invalid or greater than balance!" << endl;
		return;
	}

	_balance -= amount;
	cout << "Withdraw " << amount << " successful." << endl;
}

void BankAccount::Lookup() const {
	cout << "----- Bank Account Info -----" << endl;
	cout << "ID: " << _id << endl;
	cout << "FullName: " << _fullName << endl;
	cout << "Balance: " << _balance << endl;
}