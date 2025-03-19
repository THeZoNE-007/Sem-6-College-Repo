#include <iostream>

class MyClass {
public:
    // Static variable
    static int staticVariable;

    // Static function
    static void staticFunction() {
        std::cout << "Static function called." << std::endl;
        std::cout << "Static variable value: " << staticVariable << std::endl;
        // Static functions can only access static members directly.
    }
};

// Initialize the static variable outside the class
int MyClass::staticVariable = 0;

int main() {
    // Accessing static variable
    MyClass::staticVariable = 10;
    std::cout << "Static variable: " << MyClass::staticVariable << std::endl;

    // Calling static function
    MyClass::staticFunction();

    // You can also call static members through an object (not recommended)
    MyClass obj;
    obj.staticFunction(); // This works, but MyClass::staticFunction() is preferred.

    return 0;
}