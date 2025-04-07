#include <iostream>
using namespace std;
class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
    // Friend function for operator overloading
    friend Complex operator+(const Complex &c1, const Complex &c2);
};
/*
friend returntype operatorOp(const classname &obj1,
const classname &obj2);
*/
// Definition outside the class
Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
int main()
{
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}
