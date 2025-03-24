#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string depositorName;  // Name of the depositor
    int accountNumber;     // Account number
    string accountType;    // Type of account (Savings or Current)
    double balance;        // Balance amount in the account

public:
    // Assign initial values
    void assignValues(string name, int accNumber, string accType, double initialBalance) {
        depositorName = name;
        accountNumber = accNumber;
        accountType = accType;
        balance = initialBalance;
    }

    // Deposit an amount
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    // Withdraw an amount
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    // Display name and balance
    void display() const {
        cout << "Name: " << depositorName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }

    // Get depositor's name (helper function for display in main)
    string getDepositorName() const {
        return depositorName;
    }
};

int main() {
    const int MAX_CUSTOMERS = 10; // Maximum number of customers
    BankAccount accounts[MAX_CUSTOMERS]; // Array of bank accounts

    // Assign initial values for each customer
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        string name = "Customer " + to_string(i + 1);
        int accNumber = 1000 + i; // Unique account number for each customer
        string accType = (i % 2 == 0) ? "Savings" : "Current"; // Alternate account types
        double initialBalance = 1000.0; // Initial balance for all customers

        accounts[i].assignValues(name, accNumber, accType, initialBalance);
    }

    // Perform operations on each account
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        cout << "\nAccount Details for " << accounts[i].getDepositorName() << ":" << endl;
        
        accounts[i].display(); // Display initial details
        
        accounts[i].deposit(500.0);   // Deposit an amount
        accounts[i].withdraw(300.0); // Withdraw an amount
        
        cout << "\nUpdated Account Details:" << endl;
        accounts[i].display(); // Display updated details
    }

    return 0;
}

