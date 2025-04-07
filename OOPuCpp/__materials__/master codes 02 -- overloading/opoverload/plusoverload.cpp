#include <iostream>

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overloading the + operator
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    void display() const {
        std::cout << "Point: (" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2; // Using the overloaded + operator
    p3.display();
    return 0;
}