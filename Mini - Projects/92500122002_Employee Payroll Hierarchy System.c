#include <iostream>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int id;

public:
    void getData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter ID: ";
        cin >> id;
    }

    virtual void showSalary() {
        cout << "Basic Salary: 10000" << endl;
    }
};

// Derived Class 1
class Manager : public Employee {
public:
    void showSalary() {
        cout << "Salary of Manager: 20000" << endl;
    }
};

// Derived Class 2
class Developer : public Employee {
public:
    void showSalary() {
        cout << "Salary of Developer: 15000" << endl;
    }
};

// Derived Class 3
class Intern : public Employee {
public:
    void showSalary() {
        cout << "Salary of Intern: 8000" << endl;
    }
};

int main() {
    int choice, n;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Manager\n";
        cout << "2. Developer\n";
        cout << "3. Intern\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            cout << "Enter number of employees: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "\nEmployee " << i + 1 << ":\n";

                if (choice == 1) {
                    Manager m;
                    m.getData();
                    m.showSalary();
                }
                else if (choice == 2) {
                    Developer d;
                    d.getData();
                    d.showSalary();
                }
                else if (choice == 3) {
                    Intern in;
                    in.getData();
                    in.showSalary();
                }
            }
        }

        else if (choice == 4) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
