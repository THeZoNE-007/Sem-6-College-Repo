#include <iostream>
#include <cmath> // For sqrt and pow functions

class MyPoint {
private:
    double x; // X-coordinate
    double y; // Y-coordinate

public:
    // No-argument constructor that initializes the point to (0, 0)
    MyPoint() : x(0), y(0) {}

    // Constructor that initializes the point with specified coordinates
    MyPoint(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Getter for x-coordinate
    double getX() const {
        return x;
    }

    // Getter for y-coordinate
    double getY() const {
        return y;
    }

    // Function to calculate the distance from this point to another point
    double distance(const MyPoint& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

int main() {
    // Create two MyPoint objects
    MyPoint point1;           // Point (0, 0)
    MyPoint point2(10, 30.5); // Point (10, 30.5)

    // Calculate the distance between point1 and point2
    double dist = point1.distance(point2);

    // Display the distance
    std::cout << "Distance between (" << point1.getX() << ", " << point1.getY()
              << ") and (" << point2.getX() << ", " << point2.getY() 
              << ") is: " << dist << std::endl;

    return 0;
}

