#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(int accNum, string name, double initialBalance = 0.0) {
        accountNumber = accNum;
        holderName = name;
        balance = (initialBalance >= 0) ? initialBalance : 0.0;
    }

    // a. Deposit function
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive. Deposit failed.\n";
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }

    // b. Withdraw function - checks for insufficient balance
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive. Withdrawal failed.\n";
            return;
        }
        if (amount > balance) {
            cout << "Insufficient balance! Withdrawal of " << amount
                 << " failed. Current balance: " << balance << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
    }

    // Helper function to display account details
    void displayAccount() const {
        cout << "\nAccount Number: " << accountNumber
             << "\nHolder Name: " << holderName
             << "\nBalance: " << balance << endl;
    }
};

int main() {
    // Create a BankAccount object
    BankAccount account(101, "Alice", 1000.0);

    account.displayAccount();

    cout << "\n--- Transactions ---\n";
    account.deposit(500);       // Successful deposit
    account.withdraw(300);      // Successful withdrawal
    account.withdraw(5000);     // Should fail - insufficient balance
    account.deposit(-50);       // Should fail - invalid amount

    cout << "\n--- Final Account State ---";
    account.displayAccount();

    return 0;
}