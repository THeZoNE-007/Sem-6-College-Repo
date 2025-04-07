#include <iostream>
using namespace std;

class Fahrenheit;  // Forward declaration

class Celsius {
private:
    float temp;
public:
    Celsius(float t) : temp(t) {}

    float getTemp() const {
        return temp;
    }

    // Conversion operator to convert Celsius to Fahrenheit
    operator Fahrenheit();
};

class Fahrenheit {
private:
    float temp;
public:
    Fahrenheit(float t) : temp(t) {}

    void display() {
        cout << "Temperature in Fahrenheit: " << temp << "°F" << endl;
    }
};

// Defining the conversion operator
Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9.0 / 5.0) + 32);
}

int main() {
    Celsius c(30);  // 30°C
    Fahrenheit f = c;  // Implicit conversion using conversion operator

    f.display();  // Output: Temperature in Fahrenheit: 86°F
    return 0;
}
