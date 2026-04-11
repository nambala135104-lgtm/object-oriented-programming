#include <iostream>
using namespace std;

// -------- Inline Function --------
inline float calculateSavings(float income, float expense) {
    return income - expense;
}

// -------- Function Overloading --------
float add(float a, float b) {
    return a + b;
}

float add(float a, float b, float c) {
    return a + b + c;
}

float add(float a, float b, float c, float d) {
    return a + b + c + d;
}

// -------- Pass by Reference --------
void checkStatus(float &savings) {
    if (savings < 0)
        cout << "Status: You are in Loss!" << endl;
    else if (savings == 0)
        cout << "Status: No Savings This Month." << endl;
    else
        cout << "Status: Good! You saved money." << endl;
}

// -------- Class --------
class Budget {
private:
    float income;
    float rent, emi1, emi2;
    float grocery, food;
    float currentBill, waterBill, gasBill;
    float totalExpense, savings;

public:
    Budget() {
        income = rent = emi1 = emi2 = grocery = food = 0;
        currentBill = waterBill = gasBill = 0;
        totalExpense = savings = 0;
    }

    void inputData() {
        cout << "Enter Monthly Income: ";
        cin >> income;

        cout << "Enter House Rent: ";
        cin >> rent;

        cout << "Enter EMI 1: ";
        cin >> emi1;

        cout << "Enter EMI 2: ";
        cin >> emi2;

        cout << "Enter Grocery Expense: ";
        cin >> grocery;

        cout << "Enter Food Expense: ";
        cin >> food;

        cout << "Enter Current Bill: ";
        cin >> currentBill;

        cout << "Enter Water Bill: ";
        cin >> waterBill;

        cout << "Enter Gas Bill: ";
        cin >> gasBill;
    }

    void calculateTotalExpense() {
        float housing = add(rent, emi1, emi2);
        float bills = add(currentBill, waterBill, gasBill);
        totalExpense = add(housing, grocery, bills) + food;
    }

    void calculateFinalSavings() {
        savings = calculateSavings(income, totalExpense);
    }

    void displayReport() {
        cout << "\n------ Monthly Budget Report ------" << endl;
        cout << "Income: " << income << endl;
        cout << "Rent: " << rent << endl;
        cout << "EMI 1: " << emi1 << endl;
        cout << "EMI 2: " << emi2 << endl;
        cout << "Grocery: " << grocery << endl;
        cout << "Food: " << food << endl;
        cout << "Current Bill: " << currentBill << endl;
        cout << "Water Bill: " << waterBill << endl;
        cout << "Gas Bill: " << gasBill << endl;
        cout << "-----------------------------------" << endl;
        cout << "Total Expense: " << totalExpense << endl;
        cout << "Savings: " << savings << endl;

        checkStatus(savings);
    }

    void expensePercentage() {
        float percent = (totalExpense / income) * 100;
        cout << "Expense Percentage: " << percent << "%" << endl;
    }
};

// -------- Main Function --------
int main() {

    Budget b;
    int choice;

    do {
        cout << "\n===== Budget Management Menu =====" << endl;
        cout << "1. Enter Budget Data" << endl;
        cout << "2. Calculate Total Expense" << endl;
        cout << "3. Calculate Savings" << endl;
        cout << "4. Display Budget Report" << endl;
        cout << "5. Show Expense Percentage" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            b.inputData();
            break;

        case 2:
            b.calculateTotalExpense();
            cout << "Total Expense Calculated." << endl;
            break;

        case 3:
            b.calculateFinalSavings();
            cout << "Savings Calculated." << endl;
            break;

        case 4:
            b.displayReport();
            break;

        case 5:
            b.expensePercentage();
            break;

        case 6:
            cout << "Exiting Program..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while(choice != 6);

    return 0;
}
