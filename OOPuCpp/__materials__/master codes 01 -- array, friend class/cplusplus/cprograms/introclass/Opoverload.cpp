#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;

    void setValues(double r, double i) {
        real = r;
        imag = i;
    }

    // Overload the + operator
    Complex operator+(const Complex &other) const {
        Complex temp;
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1, c2, c3;
    c1.setValues(3.0, 2.0);
    c2.setValues(1.5, 4.5);
    c3 = c1 + c2;
    c3.display();
    return 0;
}
