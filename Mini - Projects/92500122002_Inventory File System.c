#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int choice, n, id, count = 0;
    char name[50];

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student Records\n";
        cout << "2. Display Records\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1: {
            ofstream fout("student.txt");  // overwrite
            cout << "Enter number of students: ";
            cin >> n;

            for (int i = 1; i <= n; i++) {
                cout << "\nEnter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin >> name;

                fout << id << " " << name << endl;
            }

            fout.close();
            cout << "\nRecords Written Successfully!\n";
            break;
        }

        case 2: {
            ifstream fin("student.txt");
            count = 0;

            cout << "\n--- Student Records ---\n";

            while (fin >> id >> name) {
                cout << "ID: " << id << "\tName: " << name << endl;
                count++;
            }

            cout << "\nTotal Records = " << count << endl;
            fin.close();
            break;
        }

        case 3:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
