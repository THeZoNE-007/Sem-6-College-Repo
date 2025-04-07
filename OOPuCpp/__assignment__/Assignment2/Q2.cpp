#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;

public:
    void initialize(string depositorName, int accountNo, string type, double initialBalance)
    {
        name = depositorName;
        accountNumber = accountNo;
        accountType = type;
        balance = initialBalance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display()
    {
        cout << "Account Holder: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount customers[10];

    for (int i = 0; i < 10; i++)
    {
        customers[i].initialize("Customer" + to_string(i + 1), 1000 + i, "Savings", 500.0);
    }

    customers[0].deposit(300.0);
    customers[1].withdraw(200.0);

    for (int i = 0; i < 10; i++)
    {
        cout << "Customer " << i + 1 << " details:" << endl;
        customers[i].display();
        cout << "--------------------------" << endl;
    }

    return 0;
}
