#include <iostream>
using namespace std;

class Number {
public:
    int value;

    void setValue(int v) {
        value = v;
    }

    void display() const {
        cout << "Number: " << value << endl;
    }
};

void modifyNumber(Number &n) {  // Pass-by-reference
    n.value *= 2;
}

int main() {
    Number num;
    num.setValue(15);
    cout << "Before modification: ";
    num.display();
    modifyNumber(num);
    cout << "After modification: ";
    num.display();
    return 0;
}
