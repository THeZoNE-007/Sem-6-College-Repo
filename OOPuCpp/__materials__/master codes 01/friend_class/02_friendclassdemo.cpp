#include <iostream>

class ClassA {
private:
    int privateData;

public:
    ClassA(int data) : privateData(data) {}

    friend class ClassB; // Declare ClassB as a friend
};

class ClassB {
public:
    void displayPrivateData(ClassA& obj) {
        // ClassB can access ClassA's private members
        std::cout << "Private data of ClassA: " << obj.privateData << std::endl;
    }

    void modifyPrivateData(ClassA& obj, int newData) {
        obj.privateData = newData;
        std::cout << "Private data of ClassA modified to: " << obj.privateData << std::endl;
    }
};

int main() {
    ClassA objA(10);
    ClassB objB;

    objB.displayPrivateData(objA);
    objB.modifyPrivateData(objA, 20);
    objB.displayPrivateData(objA);

    return 0;
}