#include <iostream>

class ClassB; // Forward declaration of ClassB

class ClassA {
private:
    int valueA;

public:
    ClassA(int a) : valueA(a) {}
    friend void combinedFunction(ClassA& a, ClassB& b);
};

class ClassB {
private:
    int valueB;

public:
    ClassB(int b) : valueB(b) {}
    friend void combinedFunction(ClassA& a, ClassB& b);
};

void combinedFunction(ClassA& a, ClassB& b) {
    std::cout << "ClassA value: " << a.valueA << std::endl;
    std::cout << "ClassB value: " << b.valueB << std::endl;
    std::cout << "Sum of values: " << a.valueA + b.valueB << std::endl;
}

int main() {
    ClassA objA(10);
    ClassB objB(20);

    combinedFunction(objA, objB);

    return 0;
}