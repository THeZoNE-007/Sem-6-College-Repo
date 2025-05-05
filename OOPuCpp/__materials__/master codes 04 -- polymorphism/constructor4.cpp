#include <iostream>
using namespace std;

// Base Class
class A {
public:
    A(int x) {
        cout << "Constructor of A called with x = " << x << endl;
    }
};

// Derived from A
class B : public A {
public:
    B(int x, int y) : A(x) { // Call A's constructor
        cout << "Constructor of B called with y = " << y << endl;
    }
};

// Derived from B
class C : public B {
public:
    C(int x, int y, int z) : B(x, y) { // Call B's constructor
        cout << "Constructor of C called with z = " << z << endl;
    }
};

int main() {
    C obj(1, 2, 3);  // Construct C with parameters
    return 0;
}
/*
Constructor of A is called first, because C → B → A.

When using parameterized constructors:

Derived class must explicitly call base class constructors in the initializer list.

If you omit the call and there's no default constructor in the base class, compilation error
 will occur.


*/