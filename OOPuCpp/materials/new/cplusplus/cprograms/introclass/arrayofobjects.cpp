#include <iostream>
using namespace std;

class Item {
public:
    int value;

    void setValue(int v) {
        value = v;
    }

    void display() const {
        cout << "Item value: " << value << endl;
    }
};

int main() {
    const int SIZE = 3;
    Item items[SIZE];

    for (int i = 0; i < SIZE; i++) {
        items[i].setValue((i + 1) * 10);
    }

    for (int i = 0; i < SIZE; i++) {
        items[i].display();
    }
    return 0;
}
