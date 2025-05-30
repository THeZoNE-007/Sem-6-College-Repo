#include <iostream>
using namespace std;
class Number {
    int value;
public:
    Number(int v) : value(v) {}
    int getValue(){
        return value;
    } 
    void display() {
        cout << "Value: " << value << endl;
    }
};
Number operator-(Number obj){
    return Number(-obj.getValue());
}
int main() {
    Number num1(10);
    Number num2 = -num1;  // Calls overloaded unary minus operator
    cout << "Original: ";
    num1.display();
    cout << "After negation: ";
    num2.display();
    return 0;
}
