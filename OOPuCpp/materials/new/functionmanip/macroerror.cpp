#include <iostream>

#define product(m, n) m * n  // Macro to calculate the product of two values

int main() {
    int x, y, result;

    // Taking input from the user
    std::cout << "Enter values for x, y : ";
    std::cin >> x >> y;

    // Using the macro
    result = product(x, y + 1);  // Problematic expansion

    // Displaying the result
    std::cout << "Result of product(x, y + l) is: " << result << std::endl;

    return 0;
}
