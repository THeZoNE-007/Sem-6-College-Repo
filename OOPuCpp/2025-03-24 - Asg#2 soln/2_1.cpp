#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string depositorName;  // Name of the depositor
    int accountNumber;      // Account number
    string accountType;     // Type of account (savings or current)
    double balance;         // Balance amount in the account

public:
    // Member function to assign initial values
    void assignValues(string name, int accNumber, string accType, double initialBalance) {
        depositorName = name;
        accountNumber = accNumber;
        accountType = accType;
        balance = initialBalance;
    }

    // Member function to deposit an amount
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Member function to withdraw an amount after checking the balance
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    // Member function to display name and balance
    void display() const {
        cout << "Depositor Name: " << depositorName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance Amount: " << balance << endl;
    }
};

int main() {
    BankAccount account;

    // Assign initial values
    account.assignValues("John Doe", 123456, "Savings", 1000.0);

    // Display initial details
    cout << "Initial Account Details:" << endl;
    account.display();

    // Deposit an amount
    account.deposit(500.0);
    
    // Withdraw an amount
    account.withdraw(200.0);
    
    // Attempt to withdraw more than the balance
    account.withdraw(1500.0);

    // Display final details
    cout << "\nFinal Account Details:" << endl;
    account.display();

    return 0;
}

