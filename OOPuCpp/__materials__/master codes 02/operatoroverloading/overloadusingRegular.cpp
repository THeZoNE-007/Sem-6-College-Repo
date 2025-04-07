#include <iostream>
using namespace std;
class Complex {
public:
    Complex(double real = 0.0, double imag = 0.0) : 
    real_(real), imag_(imag) {}

    double real() const { return real_; }
    double imag() const { return imag_; }

private:
    double real_;
    double imag_;
};

// Non-member, non-friend operator overloading for +
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real() << " + " << c.imag() << "i";
    return os;
}

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = c1 + c2;

    cout << c1 << " + " << c2 << " = " << c3 << std::endl;

    return 0;
}