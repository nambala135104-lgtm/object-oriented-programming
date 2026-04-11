#include <iostream>
using namespace std;

// -------- Inline Function --------
inline int digitSum(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// -------- Pass by Value --------
int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// -------- Function Overloading --------

int power(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++)
        result *= base;
    return result;
}
double power(double base, int exp) {
    double result = 1;
    for(int i = 0; i < exp; i++)
        result *= base;
    return result;
}

// -------- Prime Check (Pass by Value) --------
bool isPrime(int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i <= n/2; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

// -------- Pass by Reference --------
void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num, a = 5, b = 10;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Factorial: " << factorial(num) << endl;
    cout << "Digit Sum: " << digitSum(num) << endl;
    cout << "Power (int): " << power(2,3) << endl;
    cout << "Power (double): " << power(2.5,3) << endl;

    if(isPrime(num))
        cout << "It is Prime Number\n";
    else
        cout << "It is Not Prime Number\n";

    cout << "Before Swap: a = " << a << " b = " << b << endl;
    swapNumbers(a, b);
    cout << "After Swap: a = " << a << " b = " << b << endl;

    return 0;
}
