#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:

    BankAccount(int accNo = 0, string name = "", double bal = 0.0);


    int getAccountNumber() const;
    string getAccountHolder() const;
    double getBalance() const;


    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
};

#endif
