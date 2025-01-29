#include <iostream>
#include <cmath>

using namespace std;

bool isArmstrong(int number) {
    int originalNumber = number;
    int sum = 0;
    int n = 0;

    // Calculate the number of digits
    while (originalNumber != 0) {
        originalNumber /= 10;
        n++;
    }

    originalNumber = number;

    // Calculate the sum of the digits raised to the power of n
    while (originalNumber != 0) {
        int digit = originalNumber % 10;
        sum += pow(digit, n);
        originalNumber /= 10;
    }

    return sum == number;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}

