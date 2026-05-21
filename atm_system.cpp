#include <iostream>
#include <string>

using namespace std;

// Global constants
const int DEFAULT_PIN = 12345;
const int MAX_ATTEMPTS = 3;
const int MAX_TRANSACTIONS = 100;

// Function Prototypes
bool authenticateUser(int defaultPIN, int &maxAttempts);
void showMainMenu();
void checkBalance(int balance);
void depositMoney(int &balance, string transactionHistory[], int &transCount);
void withdrawMoney(int &balance, string transactionHistory[], int &transCount);
void viewTransactionHistory(const string transactionHistory[], int transCount);

int main() {
    int maxAttempts = MAX_ATTEMPTS;
    int balance = 0;
    int choice;

    string transactionHistory[MAX_TRANSACTIONS];
    int transCount = 0;

    // 1. Authentication System
    if (!authenticateUser(DEFAULT_PIN, maxAttempts)) {
        cout << "\033[31m\n[!] Too many incorrect attempts. Account locked!\033[0m" << endl;
        return 0;
    }

    // 2. Main Menu Loop
    do {
        showMainMenu();
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                depositMoney(balance, transactionHistory, transCount);
                break;
            case 3:
                withdrawMoney(balance, transactionHistory, transCount);
                break;
            case 4:
                viewTransactionHistory(transactionHistory, transCount);
                break;
            case 5:
                cout << "\n\033[35mThank you for using BK ATM. Goodbye!\033[0m" << endl;
                break;
            default:
                cout << "\n\033[31mInvalid choice! Please try again.\033[0m" << endl;
        }
        cout << "\n\033[34m=============================================\033[0m\n";
    } while (choice != 5);

    return 0;
}

// User Authentication Function
bool authenticateUser(int defaultPIN, int &maxAttempts) {
    int pin;

    cout << "\033[36m";
    cout << "\t\t==========================================" << endl;
    cout << "\t\t               BK ATM SYSTEM              " << endl;
    cout << "\t\t==========================================" << endl;
    cout << "\033[0m" << endl;

    while (maxAttempts > 0) {
        cout << "\tEnter your PIN : ";
        cin >> pin;

        maxAttempts--;

        if (pin == defaultPIN) {
            cout << "\033[32m\n\tLogin Successful" << endl;
            cout << "\033[35m\tWelcome to BK ATM\033[0m" << endl;
            return true;
        } else {
            cout << "\033[31m\tIncorrect PIN. Attempts left: " << maxAttempts << "\033[0m" << endl;
        }
    }
    return false;
}

// Main Menu Display Function
void showMainMenu() {
    cout << "\n\033[34m============ MAIN MENU ============\033[0m" << endl;
    cout << " * [1] Check Balance" << endl;
    cout << " * [2] Deposit Money" << endl;
    cout << " * [3] Withdraw Money" << endl;
    cout << " * [4] Transaction History" << endl;
    cout << " * [5] Exit" << endl;
    cout << "\033[34m===================================\033[0m" << endl;
}

// Check Balance Function (Choice 1)
void checkBalance(int balance) {
    cout << "\033[32m";
    cout << "\nCurrent Balance : " << balance << " FRW" << endl;
    cout << "\033[0m";
}

// Deposit Function (Choice 2)
void depositMoney(int &balance, string transactionHistory[], int &transCount) {
    int amount;
    cout << "\nEnter amount to deposit : ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;

        cout << "\033[32m";
        cout << "\nDeposit Successful" << endl;
        cout << "New Balance : " << balance << " FRW" << endl;
        cout << "\033[0m";

        if (transCount < MAX_TRANSACTIONS) {
            transactionHistory[transCount] = "Deposited : " + to_string(amount) + " FRW";
            transCount++;
        }
    } else {
        cout << "\033[31mInvalid amount!\033[0m" << endl;
    }
}

// Withdraw Function (Choice 3)
void withdrawMoney(int &balance, string transactionHistory[], int &transCount) {
    int amount;
    cout << "\nEnter amount to withdraw : ";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;

        cout << "\033[32m";
        cout << "\nWithdrawal Successful" << endl;
        cout << "New Balance : " << balance << " FRW" << endl;
        cout << "\033[0m";

        if (transCount < MAX_TRANSACTIONS) {
            transactionHistory[transCount] = "Withdrawn : " + to_string(amount) + " FRW";
            transCount++;
        }
    } else if (amount > balance) {
        cout << "\033[31m\nInsufficient balance!\033[0m" << endl;
    } else {
        cout << "\033[31mInvalid amount!\033[0m" << endl;
    }
}

// View History Function (Choice 4)
void viewTransactionHistory(const string transactionHistory[], int transCount) {
    cout << "\n\033[33m========= TRANSACTION HISTORY =========\033[0m" << endl;
    if (transCount == 0) {
        cout << "No transactions made yet." << endl;
        return;
    }

    for (int i = 0; i < transCount; i++) {
        cout << " [" << (i + 1) << "] " << transactionHistory[i] << endl;
    }
}
