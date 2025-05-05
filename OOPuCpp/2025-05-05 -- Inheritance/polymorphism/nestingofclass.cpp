#include <iostream>
#include <string>
using namespace std;
// Class Nesting Example
class Outer
{
private:
    int outerData = 10;

public:
    class Inner
    { // Inner class is nested inside Outer class
    public:
        void displayOuterData(const Outer &outer)
        {
            std::cout << "Outer data from Inner: " << outer.outerData << std::endl;
        }
    };

    void outerFunction()
    {
        Inner innerObj;
        innerObj.displayOuterData(*this);
    }
    class Inner2
    {
    public:
        void printHello()
        {
            std::cout << "Hello from Inner2" << std::endl;
        }
    };
};
int main()
{
    // Class Nesting
    cout << "Class Nesting Example:\n";
    Outer outerObj;
    outerObj.outerFunction(); // Accessing inner class from outer class

    Outer::Inner innerObj; // Creating inner class object outside
    innerObj.displayOuterData(outerObj);

    Outer::Inner2 innerObj2;
    innerObj2.printHello();

    cout << "\n";
    return 0;
}