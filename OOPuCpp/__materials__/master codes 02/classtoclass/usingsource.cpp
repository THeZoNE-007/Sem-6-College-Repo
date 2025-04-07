#include <iostream>
//using namespace std;
// Forward declaration of Meters class
class Meters;

class Distance {
    int feet;
public:
    Distance(int f) : feet(f) {}

    // Conversion function declaration
    operator Meters();
};

class Meters {
    double meters;
public:
    Meters(double m) : meters(m) {}

    void show() {
        std::cout << "Meters: " << meters << std::endl;
    }
};
// Define conversion function AFTER the full definition of Meters
Distance::operator Meters() {
    return Meters(feet * 0.3048); // Convert feet to meters
}

int main() {
    Distance d(10);  // 10 feet
    Meters m = d;    // Class-to-class conversion
    m.show();        // Output: Meters: 3.048
    return 0;
}
/*
class Source{
 public:
  operator Destination();
}

*/