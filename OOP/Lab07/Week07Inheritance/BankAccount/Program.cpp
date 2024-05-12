#include "iostream"
#include "vector"
#include "BankAccount.h"
#include "BankAccountV2.h"
#include "format" // Requires C++20

using namespace std;

auto getAllAccounts() {
	return vector<BankAccount> {
		BankAccount("Alice", 60000),
			BankAccount("Bob", 100000),
			BankAccount("Charlie", 100000),
			BankAccount("David", 200000),
			BankAccount("Eve", 300000),
	};
}

auto getAllAccountsV2() {
	auto accounts = getAllAccounts();
	vector <BankAccountV2> result;
	for (auto& account : accounts) {
		result.push_back(account);
	}

	return result;
}

int main(int argc, char* argv[])
{
	cout << endl << "----- Bank Account V1 -----" << endl;
	auto accounts = getAllAccounts();

	for (auto& account : accounts) {
		cout << format("{} can withdraw {} \n",
			account.name(),
			account.withdraw(70000));
	}

	cout << endl << "----- Bank Account V2 -----" << endl;

	auto accountsV2 = getAllAccountsV2();

	for (auto& account : accountsV2) {
		cout << format("{} can withdraw {} \n",
			account.name(),
			account.withdraw(70000));
	}

	return 0;
}