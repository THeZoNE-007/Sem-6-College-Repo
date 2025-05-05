#include <iostream>
using namespace std;

class A {
public:
    void display() {
        cout << "Class A's method" << endl;
    }
};

class B : public A {
};

int main() {
    B obj;
    obj.display();  
    return 0;
}