#include "BankAccount.h"

string  BankAccount::name() const { return _name; }

int  BankAccount::balance() const { return _balance; }

BankAccount::BankAccount() { _name = ""; _balance = 0; }

BankAccount::BankAccount(string name, int balance) : _name(name), _balance(balance) {}

int BankAccount::withdraw(int amount) {
	if (_balance >= amount) {
		_balance -= amount;
		return amount;
	}
	return 0;
}