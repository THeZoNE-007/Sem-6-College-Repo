#include<iostream>
using namespace std;
class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading + operator
    /*
    returntype operatorOp(const Classname &obj){
    }
    */
    Complex operator+(const Complex &obj)
    {
        return Complex(real + obj.real, imag + obj.imag);
    }
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};
int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;//c1.operator+(c2)

    c3.display();

    return 0;
}