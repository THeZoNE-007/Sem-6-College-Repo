#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "Default constructor of A" << endl;
    }
    A(int x) {
        cout << "Parameterized constructor of A with x = " << x << endl;
    }
    ~A() {
        cout << "Destructor of A" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "Default constructor of B" << endl;
    }
    B(int x, int y) : A(x) {
        cout << "Parameterized constructor of B with y = " << y << endl;
    }
    ~B() {
        cout << "Destructor of B" << endl;
    }
};

class C : public B {
public:
    C() {
        cout << "Default constructor of C" << endl;
    }
    C(int x, int y, int z) : B(x, y) {
        cout << "Parameterized constructor of C with z = " << z << endl;
    }
    ~C() {
        cout << "Destructor of C" << endl;
    }
};

int main() {
    cout << "Creating obj1 with default constructors:\n";
    C obj1;

    cout << "\nCreating obj2 with parameterized constructors:\n";
    C obj2(1, 2, 3);

    cout << "\nEnd of main()\n";
    return 0;
}
/*
Constructors run top-down (base to derived).

Destructors run bottom-up (derived to base).

All destructors are called automatically when objects go out of scope.

This guarantees proper cleanup in a multilevel inheritance hierarchy.


*/