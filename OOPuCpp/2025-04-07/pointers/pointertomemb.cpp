#include <iostream>

class MyClass {
public:
    int a;
    double b;
};

int main() {
    MyClass obj;
    
    // Pointer to member variable
    int MyClass::*ptrToA = &MyClass::a;
    double MyClass::*ptrToB = &MyClass::b;

    // Accessing members using pointer to member
    obj.*ptrToA = 42;
    obj.*ptrToB = 3.14;

    std::cout << "obj.a = " << obj.a << std::endl;
    std::cout << "obj.b = " << obj.b << std::endl;

    // Displaying the pointer values (they store offsets, not absolute addresses)
    std::cout << "Offset of a: " << ptrToA << std::endl;
    std::cout << "Offset of b: " << ptrToB << std::endl;

    return 0;
}
