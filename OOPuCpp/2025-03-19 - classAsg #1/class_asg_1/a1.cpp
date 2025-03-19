#include <iostream>

class Rectangle {
private:
    double width;  // Width of the rectangle
    double height; // Height of the rectangle

public:
    // No-argument constructor
    Rectangle() : width(1), height(1) {}

    // Parameterized constructor
    Rectangle(double w, double h) : width(w), height(h) {}

    // Method to calculate the area
    double getArea() const {
        return width * height;
    }

    // Method to calculate the perimeter
    double getPerimeter() const {
        return 2 * (width + height);
    }

    // Method to display rectangle properties
    void display() const {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Perimeter: " << getPerimeter() << std::endl;
    }
};

int main() {
    // Create two Rectangle objects
    Rectangle rect1(4, 40);     // Width 4, Height 40
    Rectangle rect2(3.5, 35.9);  // Width 3.5, Height 35.9

    // Display properties of the first rectangle
    std::cout << "Rectangle 1:" << std::endl;
    rect1.display();
    
    std::cout << std::endl; // Add a line break for better readability

    // Display properties of the second rectangle
    std::cout << "Rectangle 2:" << std::endl;
    rect2.display();

    return 0;
}

