#include <iostream>

class Point {
public:
    int x, y;

    // Constructor
    Point(int x_val, int y_val) : x(x_val), y(y_val) {
        std::cout << "Constructor called" << std::endl;
    }

    // Copy constructor
    Point(const Point& other) : x(other.x), y(other.y) {
        std::cout << "Copy constructor called" << std::endl;
    }

    void display() {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
};

int main() {
    Point p1(10, 20); // Normal constructor is called
    p1.display();

    Point p2 = p1; // Copy constructor is called
    p2.display();

    Point p3(p1); // Copy constructor is also called here.
    p3.display();

    return 0;
}