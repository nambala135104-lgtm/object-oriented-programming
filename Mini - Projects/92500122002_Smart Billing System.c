#include <iostream>
#include <iomanip>   // For manipulators

using namespace std;

int main ()
{
    int n;// number of items
    cout << "Enter number of items: ";
    cin >> n;

    float grandTotal = 0;// to store total of all items

    for(int i = 1; i <= n; i++)
    {
        string itemName;
        int quantity;
        float price;
        float totalAmount;

        cout << "\nEnter Item Name: ";
        cin >> itemName;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price per Item: ";
        cin >> price;

        totalAmount = quantity * price; // Arithmetic operator
        grandTotal += totalAmount;

        cout << "\n";
        cout << setw(30) << "----- BILL -----" << endl;
        cout << setw(20) << "Item Name: " << itemName << endl;
        cout << setw (20) << "Quantity: " << quantity << endl;
        cout << setw(20) << "Price per Item: "
             << fixed << setprecision(2) << price << endl;
        cout << setw(20) << "Total Amount: "
             << fixed << setprecision(2) << totalAmount << endl;
    }

    cout << "\n";
    cout << setw(30) << "Grand Total: "
         << fixed << setprecision(2) << grandTotal << endl;

    return 0;
}
