#include <iostream>
using namespace std;

class Number {
    int value;
public:
    // Constructor for basic type to class type conversion
    Number(int v) {
        value = v;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num = 10;  // Implicit conversion from int to Number
    num.display();
    return 0;
}
