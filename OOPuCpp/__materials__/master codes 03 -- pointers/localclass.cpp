#include <iostream>

void exampleFunction() {
    // Local class inside the function
    class LocalClass {
    public:
        void greet() {
            std::cout << "Hello from LocalClass!" << std::endl;
        }
    };

    // Create object and use it
    LocalClass obj;
    obj.greet();
}

int main() {
    exampleFunction();
    return 0;
}
/*

They can access static variables or constants from the 
enclosing function (but not non-static locals directly).

They cannot have static data members.

They cannot use templates (in standard C++).

Can have member functions, constructors, destructors, etc.

*/