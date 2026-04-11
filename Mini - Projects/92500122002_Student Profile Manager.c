#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    int rollNo;
    string branch;
    int marks;
    char grade;

public:
    Student() {
        name = "";
        age = 0;
        rollNo = 0;
        branch = "";
        marks = 0;
        grade = ' ';
    }

    void getData() {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Branch: ";
        cin >> branch;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void setGrade() {
        if (marks > 90)
            grade = 'A';
        else if (marks > 75)
            grade = 'B';
        else if (marks > 60)
            grade = 'C';
        else
            grade = 'D';
    }

    void display() {
        cout << "\nStudent Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Branch: " << branch << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s1;

    s1.getData();
    s1.setGrade();   // grade calculated here
    s1.display();

    return 0;
}
