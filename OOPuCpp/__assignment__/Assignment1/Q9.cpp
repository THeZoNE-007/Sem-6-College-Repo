#include <iostream>
using namespace std;

// Function to raise an integer to a power
int power(int m, int n = 2) {
    int result = 1;
    for (int i = 0; i < n; i++) result *= m;
    return result;
}

// Function to raise a double to a power
double power(double m, int n = 2) {
    double result = 1;
    for (int i = 0; i < n; i++) result *= m;
    return result;
}

int main() {
    int m1;
    double m2;
    int n;

    // Prompt user for integer base and exponent
    cout << "Enter an integer base and an exponent value (Press enter after just the base value to calculate square by default): ";
    cin >> m1;

    if (cin.peek() == '\n') {
        cin.ignore(); // Ignore the newline character
        cout << "Result (square): " << power(m1) << endl; // Calculate square
    } else {
        cin >> n;
        cout << "Result (" << m1 << " raised to the power of " << n << "): " << power(m1, n) << endl; // Calculate with provided exponent
    }

    // Prompt user for double base and exponent
    cout << "Enter a double base and an exponent value (Press enter after just the base value to calculate square by default): ";
    cin >> m2;

    if (cin.peek() == '\n') {
        cin.ignore(); // Ignore the newline character
        cout << "Result (square): " << power(m2) << endl; // Calculate square
    } else {
        cin >> n;
        cout << "Result (" << m2 << " raised to the power of " << n << "): " << power(m2, n) << endl; // Calculate with provided exponent
    }

    return 0;
}
