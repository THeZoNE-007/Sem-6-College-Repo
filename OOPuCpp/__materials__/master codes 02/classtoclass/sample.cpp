#include <iostream>
using namespace std;

class Sample {
private:
    int* data;
public:
    // Constructor
    Sample(int value) {
        data = new int(value);  // Dynamic memory allocation
        cout << "Constructor: Memory allocated, value = " << *data << endl;
    }

    // Destructor
    ~Sample() {
        cout << "Destructor: Memory freed, value = " << *data << endl;
        delete data;  // Free allocated memory
    }
};

int main() {
    Sample* obj = new Sample(10); // Dynamically allocated object
    delete obj; // Destructor is called explicitly

    return 0;
}
