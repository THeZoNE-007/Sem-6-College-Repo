#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;

public:
    void initialize(string depositorName, int accountNo, string type, double initialBalance) {
        name = depositorName;
        accountNumber = accountNo;
        accountType = type;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() {
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account;
    account.initialize("John Doe", 12345, "Savings", 1000.0);
    account.deposit(500.0);
    account.withdraw(300.0);
    account.display();
    return 0;
}
