#include <iostream>
#include <vector>
using namespace std;

// Template function for processing data
template <class T>
void processData(vector<T> data, T divisor) {
    try {
        if (divisor == 0) {
            throw divisor;
        }

        cout << "Processed Data: ";
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] / divisor << " ";
        }
        cout << endl;
    }

    catch (T x) {
        cout << "Error: Division by zero not allowed!" << endl;
    }
}

int main() {
    int n;
    float value, divisor;

    cout << "Enter number of elements: ";
    cin >> n;

    try {
        if (n <= 0) {
            throw n;
        }

        vector<float> arr;

        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> value;
            arr.push_back(value);
        }

        cout << "Enter divisor: ";
        cin >> divisor;

        processData(arr, divisor);
    }

    catch (int x) {
        cout << "Error: Invalid number of elements!" << endl;
    }

    return 0;
}
