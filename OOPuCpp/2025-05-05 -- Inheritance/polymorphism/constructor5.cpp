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
};

class B : public A {
public:
    B() {
        cout << "Default constructor of B" << endl;
    }

    B(int x, int y) : A(x) {
        cout << "Parameterized constructor of B with y = " << y << endl;
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
};

int main() {
    cout << "Calling default constructors:\n";
    C obj1;

    cout << "\nCalling parameterized constructors:\n";
    C obj2(1, 2, 3);

    return 0;
}
