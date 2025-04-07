#include <iostream>
using namespace std;

// Function to raise a number m to power n
double power(double m, int n = 2) {
    double result = 1;
    for (int i = 0; i < n; i++) result *= m;
    return result;
}

int main() {
    double m;
    int n;

    // Prompt user for base value
    cout << "Enter a base and an exponent value (Press enter after just the base value to calculate square by default): ";
    cin >> m;

    if (cin.peek() == '\n') {
        cin.ignore(); // Ignore the newline character
        cout << "Result (square): " << power(m) << endl; // Calculate square
    } else {
        cin >> n;
        cout << "Result (" << m << " raised to the power of " << n << "): " << power(m, n) << endl; // Calculate with provided exponent
    }

    return 0;
}

