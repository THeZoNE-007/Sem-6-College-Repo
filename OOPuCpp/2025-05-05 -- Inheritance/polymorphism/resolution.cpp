#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "This is class A" << endl;
    }
};

class B {
public:
    void show() {
        cout << "This is class B" << endl;
    }
};

class C : public A, public B {
    
};

int main() {
    C obj;

    // obj.show();  // ❌ Error: Ambiguous! Compiler doesn't know which show() to call

    obj.A::show();  // ✅ Resolving ambiguity by specifying class A
    obj.B::show();  // ✅ Resolving ambiguity by specifying class B

    return 0;
}