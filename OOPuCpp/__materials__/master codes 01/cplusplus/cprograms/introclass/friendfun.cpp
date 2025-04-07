#include <iostream>
using namespace std;

class Box {
private:
    int width;
public:
    void setWidth(int w) {
        width = w;
    }

    // Declare friend function
    friend void printWidth(const Box &b);
};

void printWidth(const Box &b) {
    cout << "Width of the box: " << b.width << endl;
}

int main() {
    Box box;
    box.setWidth(50);
    printWidth(box);
    return 0;
}
