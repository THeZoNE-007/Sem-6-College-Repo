#include <iostream>
using namespace std;

class Demo {
public:
    // Constructor
    Demo() {
        cout << "Constructor called: Object Created" << endl;
    }

    // Destructor
    ~Demo() {
        cout << "Destructor called: Object Destroyed" << endl;
    }
};

int main() {
    cout << "Creating an object inside main..." << endl;
    Demo obj;  // Constructor is called

    cout << "Explicitly calling destructor..." << endl;
    obj.~Demo(); // Explicit call to destructor

    cout << "Exiting main function..." << endl;
    return 0;  // Destructor will be called again automatically when obj goes out of scope
}
