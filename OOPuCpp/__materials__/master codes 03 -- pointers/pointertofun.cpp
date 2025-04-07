#include <iostream>

class MyClass {
public:
    int a;
    double b;

    void show() {
        std::cout << "Inside show(): a = " << a << ", b = " << b << std::endl;
    }

    void setValues(int x, double y) {
        a = x;
        b = y;
    }
};

int main() {
    MyClass obj;

    // Pointer to data members
    int MyClass::*ptrToA = &MyClass::a;
    double MyClass::*ptrToB = &MyClass::b;

    // Pointer to member functions
    void (MyClass::*ptrToShow)() = &MyClass::show;
    void (MyClass::*ptrToSetValues)(int, double) = &MyClass::setValues;

    // Access data members using pointers
    obj.*ptrToA = 10;
    obj.*ptrToB = 3.14;

    // Call member function using pointer
    (obj.*ptrToShow)();  // Equivalent to obj.show();

    // Call setValues using pointer
    (obj.*ptrToSetValues)(20, 5.67);  // Equivalent to obj.setValues(20, 5.67);

    // Show again to verify values
    (obj.*ptrToShow)();

    return 0;
}
/*
// Declaration
<type> <ClassName>::* pointerName;

// Assignment
pointerName = &ClassName::memberName;

// Access using object
object.*pointerName = value;         // If you have an object
pointerToObject->*pointerName = value;  // If you have a pointer to object


// Declaration
<return_type> (ClassName::* pointerName)(<parameter_types>);

// Assignment
pointerName = &ClassName::memberFunction;

// Invocation using object
(object.*pointerName)(args);             // With object
(pointerToObject->*pointerName)(args);   // With pointer to object

*/