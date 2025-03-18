#include <iostream>
using namespace std;

class Box {
public:
    int length, width;

    // Method to set dimensions
    void setDimensions(int l, int w) {
        length = l;
        width = w;
    }

    // Method to display dimensions
    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

// Function that takes an object by value
void modifyBox(Box &b) {
    b.length += 5; // Modifying the copy
    b.width += 5;
    cout << "Inside modifyBox function (after modification): ";
    b.display();
}

int main() {
    Box myBox;
    myBox.setDimensions(10, 20);

    cout << "Before calling modifyBox: ";
    myBox.display();

    modifyBox(myBox); // Passing object by value

    cout << "After calling modifyBox: ";
    myBox.display(); // Original object remains unchanged

    return 0;
}
