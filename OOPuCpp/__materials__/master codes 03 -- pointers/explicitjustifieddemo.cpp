#include <iostream>
#include <new>  // Required for placement new
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
    // Allocate raw memory without calling a constructor
    void* memory = operator new(sizeof(Demo));

    // Construct object in allocated memory using placement new
    Demo* obj = new (memory) Demo;

    // Explicitly call the destructor since 'delete' won't be used
    cout << "Calling destructor explicitly..." << endl;
    obj->~Demo();

    // Free the allocated raw memory
    operator delete(memory);

    return 0;
}
