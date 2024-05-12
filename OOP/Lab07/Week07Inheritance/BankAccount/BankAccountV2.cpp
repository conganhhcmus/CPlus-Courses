#include "BankAccountV2.h"

#define MIN_BALANCE 50000

BankAccountV2::BankAccountV2() : BankAccount() {
	_minBalance = MIN_BALANCE;
}

BankAccountV2::BankAccountV2(string name, int balance) : BankAccount(name, balance) {
	_minBalance = MIN_BALANCE;
}

BankAccountV2::BankAccountV2(BankAccount account) {
	_name = account.name();
	_balance = account.balance();
	_minBalance = MIN_BALANCE;
}

int BankAccountV2::withdraw(int amount) {
	if (_balance >= (amount + MIN_BALANCE)) {
		_balance -= amount;
		return amount;
	}
	return 0;
}