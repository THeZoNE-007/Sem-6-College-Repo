#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    void setPoint(int a, int b) {
        x = a;
        y = b;
    }

    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

Point createPoint(int a, int b) {
    Point p;
    p.setPoint(a, b);
    return p;
}

int main() {
    Point pt = createPoint(5, 10);
    pt.display();
    return 0;
}
