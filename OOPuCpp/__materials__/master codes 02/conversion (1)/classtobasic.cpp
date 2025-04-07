#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v) { value = v; }
    /*
    operator returntype(){
    coversion logic
    return returntypeValue;}
    */
    // Overloaded conversion operator
    operator int() {
        return value;
    }
};

int main() {
    Number num(25);
    int x = num;  // Implicit conversion from Number to int
    cout << "Converted value: " << x << endl;
    return 0;
}
