#include <iostream>
#include <string>
using namespace std;

class User {
private:	
	string name;
	string surname;
public:
	User(string name, string surname) {
		this->name = name;
		this->surname = surname;
	};
	string getFullName() {
		return name + " " + surname;
	};
};
class Account{
private:
	double balance;
public:
	void deposit(double amount) {
		balance += amount;
	}
	bool withdraw(double amount) {
		if(amount <= balance) {
			balance -= amount;
			return true;
		}
		else {
			return false;
		}
	}
	Account(double startBalance) {
		balance = startBalance;
	}
	double getBalance() {
		return balance;
	};
};
bool isValidName(string name) {
	for (char c : name) {
		if (!isalpha(c) && c != ' ') {
			return false;
		}
	}
	return true;
}

int main() {
	string firstName, lastName;
	
	do {
		cout << "Enter your name: ";
		cout << endl;
		cin >> firstName;
		cout << endl;
		if (!isValidName(firstName)) {
			cout << "The name must contain only letters!" << endl;
			cout << endl;
		}
	} while (!isValidName(firstName));
	
	do {
		cout << "Enter your surname: ";
		cout << endl;
		cin >> lastName;
		cout << endl;
		if (!isValidName(lastName)) {
			cout << "The surname must contain only letters!" << endl;
			cout << endl;
		}
	} while (!isValidName(lastName));
	
	User user(firstName, lastName);
	Account account(0.00);
	
	while(true) {
		cout << "Hello " << user.getFullName() << "!" << endl;
		cout << endl;
		cout << "Menu:" << endl;
		cout << endl;
		cout << "1. Top up account" << endl;
		cout << "2. Withdraw money" << endl;
		cout << "3. Check balance" << endl;
		cout << "4. Exit" << endl;
		
		int choice;
		double amount;
		cin >> choice;
		cout << endl;
		if(cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Error! Enter a number." << endl;
			continue;
		}
		
		if(choice == 1) {
			cout << "Enter the amount: " << endl;
			cin >> amount;
			cout << endl;
			account.deposit(amount);
			cout << "Your balance = " << account.getBalance() << endl;
			cout << endl;
		}
		else if(choice == 2) {
			cout << "Enter the amount:" << endl;
			cin >> amount;
			cout << endl;
			if(account.withdraw(amount)) {
				cout << "You took off - " << amount << "." << endl;
				cout << endl;
				cout << "Your balance = " << account.getBalance() << endl;
				cout << endl;
			}
			else {
				cout << "Insufficient funds" << endl;
			}
		}
		else if(choice == 3) {
			cout << "Your balance = " << account.getBalance() << endl;
		}
		else if(choice == 4) {
			cout << "GoodBye " << user.getFullName() << "!" << endl;
			break;
		}
		else {
			cout << "Error! Choose 1, 2, 3, or 4." << endl;
		}
		
		
	}
	return 0;
}
