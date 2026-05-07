#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Account.h"

using namespace std;

void saveToFile(const vector<BankAccount>& accounts) {
    ofstream outFile("bank_data.txt");
    for (const auto& acc : accounts) {
        outFile << acc.getAccountNumber() << ","
                << acc.getAccountHolder() << ","
                << acc.getBalance() << endl;
    }
    outFile.close();
}

vector<BankAccount> loadFromFile() {
    vector<BankAccount> accounts;
    ifstream inFile("bank_data.txt");
    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, bal;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, bal, ',');
        accounts.push_back(BankAccount(stoi(id), name, stod(bal)));
    }
    inFile.close();
    return accounts;
}

int main() {
    vector<BankAccount> accounts = loadFromFile();
    int choice;

    do {
        cout << "\n=====  BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Create Account";
        cout << "\n2. Display All Accounts";
        cout << "\n3. Deposit Money";
        cout << "\n4. Withdraw Money";
        cout << "\n5. Exit";
        cout << "\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int id; string name; double bal;
            cout << "Enter Account Number: "; cin >> id;
            cin.ignore();
            cout << "Enter Name: "; getline(cin, name);
            cout << "Initial Deposit: "; cin >> bal;
            accounts.push_back(BankAccount(id, name, bal));
            saveToFile(accounts);
        }
        else if (choice == 2) {
            cout << "\nID        Name                Balance\n";
            cout << "--------------------------------------\n";
            for (const auto& acc : accounts) acc.display();
        }
        else if (choice == 3 || choice == 4) {
            int id; double amt;
            cout << "Enter Account Number: "; cin >> id;
            bool found = false;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == id) {
                    cout << "Enter Amount: "; cin >> amt;
                    if (choice == 3) acc.deposit(amt);
                    else acc.withdraw(amt);
                    found = true;
                    saveToFile(accounts);
                    break;
                }
            }
            if (!found) cout << " Account not found!\n";
        }

    } while (choice != 5);

    return 0;
}
