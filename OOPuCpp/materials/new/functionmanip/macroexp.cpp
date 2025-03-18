#include <iostream>

#define SQUARE(x) ((x) * (x))  // Macro to calculate the square of a number
#define MAX(a, b) ((a) > (b) ? (a) : (b))  // Macro to find the maximum of two numbers

int main() {
    int num1, num2;

    // Taking input from the user
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Using SQUARE macro
    std::cout << "Square of " << num1 << " is: " << SQUARE(num1) << std::endl;
    std::cout << "Square of " << num2 << " is: " << SQUARE(num2) << std::endl;

    // Using MAX macro
    std::cout << "Maximum of " << num1 << " and " << num2 << " is: " << MAX(num1, num2) << std::endl;

    return 0;
}
