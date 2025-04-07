#include <iostream>
using namespace std;

class Demo {
public:
    int *x;

    // Constructor
    Demo(int val) {
        x = new int(val);  // Allocate memory dynamically
        cout << "Constructor called!" << endl;
    }

    // Copy Constructor (Deep Copy)
    Demo(const Demo &obj) {
        x = new int(*(obj.x));  // Allocate new memory and 
        //copy the value
        cout << "Copy Constructor called (Deep Copy)!" << endl;
    }

    // Destructor
    ~Demo() {
        delete x;  // Free allocated memory
        cout << "Destructor called!" << endl;
    }

    void display() {
        cout << "Value: " << *x << endl;
    }
};

int main() {
    Demo obj1(10);   // Constructor is called
    Demo obj2 = obj1; // Copy Constructor is called (Deep Copy)

    obj1.display();
    obj2.display();

    // Modifying obj2's value to see if it affects obj1
    *obj2.x = 20;
    cout << "After modifying obj2:" << endl;
    obj1.display();
    obj2.display();

    return 0;
}
