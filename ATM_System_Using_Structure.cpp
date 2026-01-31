#include <iostream>
#include <string>
using namespace std;

// Structure for account data
struct Account {
    string name;
    int pin;
    float balance;
};

// Function to check balance
void checkBalance(Account a) {
    cout << "\nAccount Holder: " << a.name;
    cout << "\nCurrent Balance: " << a.balance << endl;
}

// Function to deposit amount
void deposit(Account &a) {
    float amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if(amount > 0)
        a.balance += amount;
    else
        cout << "Invalid amount!\n";
}

// Function to withdraw amount
void withdraw(Account &a) {
    float amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if(amount > 0 && amount <= a.balance)
        a.balance -= amount;
    else
        cout << "Insufficient Balance or Invalid Amount!\n";
}

int main() {
    Account acc[2] = {
        {"Aisha", 1234, 5000},
        {"Ali", 4321, 3000}
    };

    int choice, enteredPin;
    bool exit = false;

    while(!exit) {
        cout << "\n--- ATM Menu ---";
        cout << "\n1. Check Balance";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        cout << "Enter PIN: ";
        cin >> enteredPin;

        bool pinFound = false;

        for(int i = 0; i < 2; i++) {
            if(acc[i].pin == enteredPin) {
                pinFound = true;

                if(choice == 1)
                    checkBalance(acc[i]);
                else if(choice == 2)
                    deposit(acc[i]);
                else if(choice == 3)
                    withdraw(acc[i]);
                else if(choice == 4)
                    exit = true;
                else
                    cout << "Invalid choice!\n";
            }
        }

        if(!pinFound)
            cout << "PIN not found! Try again.\n";
    }

    return 0;
}
