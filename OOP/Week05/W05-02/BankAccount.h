#pragma once
#include "string"
#include "iostream"

using namespace std;

class BankAccount {
protected:
	string _id;
	string _fullName;
	float _balance;
public:
	BankAccount();
	BankAccount(string, string, float);
	~BankAccount();
	void Deposit(float);
	void Withdraw(float);
	void Lookup() const;
};