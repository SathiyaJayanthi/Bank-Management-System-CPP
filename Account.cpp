#include "Account.h"
#include <iomanip>


BankAccount::BankAccount(int accNo, string name, double bal)
    : accountNumber(accNo), accountHolder(name), balance(bal) {}

int BankAccount::getAccountNumber() const { return accountNumber; }
string BankAccount::getAccountHolder() const { return accountHolder; }
double BankAccount::getBalance() const { return balance; }

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "\n Deposit successful! New Balance: " << balance << endl;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << "\n Insufficient funds! Current Balance: " << balance << endl;
        return false;
    }
    balance -= amount;
    cout << "\n Withdrawal successful! Remaining Balance: " << balance << endl;
    return true;
}


void BankAccount::display() const {
    cout << left << setw(10) << accountNumber
         << setw(20) << accountHolder
         << "Rs." << fixed << setprecision(2) << balance << endl;
}
