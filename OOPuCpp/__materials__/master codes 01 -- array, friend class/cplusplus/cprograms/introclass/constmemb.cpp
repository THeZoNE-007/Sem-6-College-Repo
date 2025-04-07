#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
public:
    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const { // const member function
        return radius;
    }

    double area() const {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Circle c;
    c.setRadius(3.0);
    cout << "Radius: " << c.getRadius() << endl;
    cout << "Area: " << c.area() << endl;
    return 0;
}
