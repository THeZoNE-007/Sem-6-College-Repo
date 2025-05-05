#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
};

class Cat : public Animal {
};

int main() {
    Dog d;
    Cat c;
    d.eat();  // Output: Eating...
    c.eat();  // Output: Eating...
    return 0;
}
