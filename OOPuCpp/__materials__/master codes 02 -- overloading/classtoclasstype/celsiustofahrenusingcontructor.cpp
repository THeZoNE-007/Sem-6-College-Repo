#include <iostream>
using namespace std;

class Celsius {
private:
    float temp;
public:
    Celsius(float t) : temp(t) {}

    float getTemp() const {
        return temp;
    }
};

class Fahrenheit {
private:
    float temp;
public:
    // Constructor for Class Type to Class Type conversion
    Fahrenheit(Celsius c) {
        temp = (c.getTemp() * 9.0 / 5.0) + 32;  // Convert Celsius to Fahrenheit
    }

    void display() {
        cout << "Temperature in Fahrenheit: " << temp << "°F" << endl;
    }
};

int main() {
    Celsius c(25);  // 25°C
    Fahrenheit f = c;  // Implicit conversion (Class Type to Class Type)
    
    f.display();  // Output: Temperature in Fahrenheit: 77°F
    return 0;
}
