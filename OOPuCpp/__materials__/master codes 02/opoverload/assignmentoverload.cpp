#include <iostream>

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overloading the == operator
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
};

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);

    std::cout << (p1 == p2) << std::endl; // Output: 1 (true)
    std::cout << (p1 == p3) << std::endl; // Output: 0 (false)

    return 0;
}