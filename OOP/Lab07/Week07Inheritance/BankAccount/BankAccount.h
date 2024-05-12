#pragma once
#include "string"

using namespace std;

class BankAccount {
protected:
	string _name;
	int _balance;
public:
	string name() const;
	int balance() const;
	BankAccount();
	BankAccount(string name, int balance);
	int withdraw(int amount);
};