#include <iostream>
#include <vector>
using namespace std;

// ================= BASE CLASS =================
class Account {
protected:
string type;
double balance;
int pin;
vector<string> history;

public:
Account(string t) {
type = t;
balance = 0;

cout << "Set PIN for " << type << " account: ";
    cin >> pin;
}

bool checkPin(int entered) {
    return entered == pin;
}

string getType() {
    return type;
}

virtual void deposit(double amt) {
    balance += amt;

    string msg = "Deposited Rs." + to_string(amt) +
                 " | Balance: Rs." + to_string(balance);

    history.push_back(msg);
    cout << msg << endl;
}

virtual void withdraw(double amt) {
    if (amt <= balance) {
        balance -= amt;

        string msg = "Withdrawn Rs." + to_string(amt) +
                     " | Balance: Rs." + to_string(balance);

        history.push_back(msg);
        cout << msg << endl;
    } else {
        cout << "Insufficient Balance\n";
    }
}

virtual void interest() = 0;

void showHistory() {
    cout << "\n--- " << type << " History ---\n";
    for (int i = 0; i < history.size(); i++) {
        cout << history[i] << endl;
    }
}

double getBalance() {
    return balance;
}

};

// ================= SAVINGS =================
class Savings : public Account {
public:
Savings() : Account("Savings") {}

void interest() {
    double i = balance * 0.04;
    balance += i;

    string msg = "Interest Added Rs." + to_string(i) +
                 " | Balance: Rs." + to_string(balance);

    history.push_back(msg);
    cout << msg << endl;
}

};

// ================= CURRENT =================
class CurrentAccount : public Account {
public:
CurrentAccount() : Account("Current") {}

void interest() {
    cout << "No interest for current account\n";
}

};

// ================= FD =================
class FD : public Account {
int years;
int done;

public:
FD() : Account("Fixed Deposit") {
cout << "Enter FD years: ";
cin >> years;
done = 0;
}

void interest() {
    if (done == 0) {
        double i = balance * 0.07 * years;

        cout << "\nFD DETAILS:\n";
        cout << "Principal: Rs." << balance << endl;
        cout << "Years: " << years << endl;
        cout << "Interest: Rs." << i << endl;

        balance += i;
        done = 1;

        string msg = "FD Interest Rs." + to_string(i) +
                     " added | Total: Rs." + to_string(balance);

        history.push_back(msg);

        cout << "Total Amount: Rs." << balance << endl;
    } else {
        cout << "Interest already added\n";
    }
}

void withdraw(double amt) {
    if (done == 0) {
        cout << "Cannot withdraw before time completion\n";
    } else {
        Account::withdraw(amt);
    }
}

};

// ================= MAIN =================
int main() {

Savings savings;
CurrentAccount current;
FD fd;

int choice;

do {
    cout << "\n===== ATM SYSTEM =====\n";
    cout << "1. Savings Account\n";
    cout << "2. Current Account\n";
    cout << "3. Fixed Deposit\n";
    cout << "4. FD Interest\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    Account* acc = NULL;

    if (choice == 1) acc = &savings;
    else if (choice == 2) acc = &current;
    else if (choice == 3) acc = &fd;

    if (choice >= 1 && choice <= 3) {
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (!acc->checkPin(enteredPin)) {
            cout << "Wrong PIN\n";
            continue;
        }

        int op;
        cout << "\n--- " << acc->getType() << " Account Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Show History\n";
        cout << "Enter option: ";
        cin >> op;

        if (op == 1) {
            double a;
            cout << "Enter amount to deposit: ";
            cin >> a;
            acc->deposit(a);
        }
        else if (op == 2) {
            double a;
            cout << "Enter amount to withdraw: ";
            cin >> a;
            acc->withdraw(a);
        }
        else if (op == 3) {
            cout << "Balance: Rs." << acc->getBalance() << endl;
        }
        else if (op == 4) {
            acc->showHistory();
        }
        else {
            cout << "Invalid Option\n";
        }
    }

    else if (choice == 4) {
        fd.interest();
    }

    else if (choice == 0) {
        cout << "Exiting...\n";
    }

    else {
        cout << "Invalid Choice\n";
    }

} while (choice != 0);

return 0;

}


